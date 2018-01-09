#include"Table.h"
#include<sstream>
bool strloss = false;
Table::Table()
{
	id = ++TID;
	name = "table " + std::to_string(id);
}
Table& Table::Create(std::vector<std::string> names, std::vector<char> coltypes)
{
	for (unsigned int i = 0; i < names.size(); i++)
	{
		colname.push_back(names[i]);
		coltype.push_back(coltypes[i]);
	}
	return *this;
}
Table& Table::Create(std::initializer_list<std::string> list)
{
	std::string text;
	char type;
	for (auto p=list.begin(); p != list.end(); p++)
	{
		text = *p;
		std::istringstream iss(text);
		std::vector<std::string> results(std::istream_iterator<std::string>{iss},
			std::istream_iterator<std::string>());
		colname.push_back(results[1]);
		if (results[0] == "int" || results[0] == "integer")
			type = 'i';
		else if (results[0] == "double")
			type = 'd';
		else
			type = 's';
		std::string value = results[1];
		coltype.push_back(type);
	}
	return *this;
}
Table& Table::AddRecord(std::istream &in)
{
	Record *rec = new Record();
	int id;
	for (unsigned int i = 0; i < colname.size(); i++)
	{
		std::string value;
		if (coltype[i] == 'i')
		{
			getline(in,value);
			if (TypeFinder(value) == 'i')
			{

				if (!in.fail())
				{
					id = table.size() + 1;
					rec->IdReset(id);
					rec->Add(value);
				}
				else
				{
					in.clear();
					in.ignore(0);
				}
			}
			else
			{
				rec->Add(std::to_string(0));
			}
		}
		else
		if (coltype[i] == 'd')
		{
			getline(in, value);
			if (TypeFinder(value) == 'd' || TypeFinder(value) == 'i')
			{
				if (!in.fail())
				{
					id = table.size() + 1;
					rec->IdReset(id);
					rec->Add(value);
				}
				else
				{
					in.clear();
					in.ignore(0);
				}
			}
			else
			{
				rec->Add(std::to_string(0.0));
			}
		}
		else
		if (coltype[i] == 's')
		{
			if (strloss)
			{
				strloss = true;
				in.get();
			}
			getline(in, value);
			id = table.size() + 1;
			rec->IdReset(id);
			rec->Add(value);
			in.clear();
			in.ignore(0);
		}

	}
	strloss = true;
	table.push_back(rec);
	return *this;
}

Table& Table::AddRecord(std::initializer_list<std::string> list)
{
	Record *rec = new Record;
	
	std::string text;
	std::string temp;
	auto p = list.begin();
	for (unsigned int i = 0; i < colname.size(); i++)
	{
		temp = *p;
		rec->Add(temp);
		p++;
	}
	table.push_back(rec);
	return *this;
}
void Table::DeleteRecord(unsigned int  index)
{
	for (unsigned int i = 0; i<table.size(); i++)
	{
		if (table[i]->GetId()==index)
			table.erase(table.begin());
	}
}

Record& Table::FindRecord(unsigned int index, std::ostream &out)
{
	index--;
	if (index>table.size() || index < 0)
	{
		if (table.size() == 0)
		{
			Record *rec = new Record;
			out << "Table is empty.\nFirst record was created(empty)\n";
			table.push_back(rec);
			return *table[0];
		}
		out << "ID out of range\n";
		return *table[0];
	}
	
	else
		return *table[index];
	
}

Record& Table::FindRecord(const std::string& value)
{
	for (unsigned int i = 0; i < table.size(); i++)
	{
		if (table[i]->Find(value))
		{
			return *table[i];
		}
	}
	//return ?
}

void Table::FindRecords(const std::string& value,std::ostream &out)
{
	for (unsigned int i = 0; i < table.size(); i++)
	{
		if (table[i]->Find(value))
		{
			table[i]->Show(out);
		}
	}
}
void Table::Show(std::ostream &out)
{
	for (unsigned int i = 0; i < colname.size(); i++)
	{
		out << colname[i] << "  ";
	}
	out << std::endl;
	Record *ptr;
	for (unsigned int i = 0; i < table.size(); i++)
	{
		ptr = table[i];
		ptr->Show(out);
	}
}



void Table::Delete()
{
	table.clear();
}

void Table::Set(unsigned int colindex, unsigned int rowindex,std::istream &in)
{
	table[rowindex-1]->Set(colindex,in);
}

Table::~Table()
{
	table.clear();
}