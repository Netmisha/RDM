#include"Table.h"
#include<sstream>
bool strloss = false;
Table::Table()
{
	id = ++TID;
	name = "table " + std::to_string(id);
}
Table& Table::Create(std::vector<std::string>& names, std::vector<char>& coltypes)
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
		else if (results[0]=="string")
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

Table& Table::AddColumn(const std::string& type, const std::string& name)
{
	colname.push_back(name);
	if (type == "int" || type == "integer")
		coltype.push_back('i');
	else if (type == "double")
		coltype.push_back('d');
	else if (type == "string")
		coltype.push_back('s');
	for (unsigned int i = 0; i < table.size(); i++)
	{
		if (type == "int" || type == "integer")
			table[i]->Add("0");
		else if (type == "double")
			table[i]->Add("0.0");
		else if (type == "string")
			table[i]->Add("_");
	}
	return *this;
}
Table& Table::DeleteRecord(unsigned int  index)
{
	for (unsigned int i = 0; i<table.size(); i++)
	{
		if (table[i]->GetId()==index)
			table.erase(table.begin());
	}
	return *this;
}

Record* Table::FindRecord(unsigned int index)
{
	index--;
	if (table.size() == 0)
	{
		return nullptr;
	}
	else
	for (unsigned int i = 0; i < table.size(); i++)
	{
		if (table[i]->GetId() == index)
			return table[index];
		else
			return nullptr;
	}
}

Record* Table::FindRecord(const std::string& value)
{
	for (unsigned int i = 0; i < table.size(); i++)
	{
		if (table[i]->Find(value))
		{
			return table[i];
		}
	}
	return nullptr;
}

Table& Table::FindRecords(const std::string& value, std::ostream &out)
{
	for (unsigned int i = 0; i < table.size(); i++)
	{
		if (table[i]->Find(value))
		{
			table[i]->Show(out);
		}
	}
	return *this;
}
Table& Table::Show(std::ostream &out)
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
	return *this;
}



Table& Table::Delete()
{
	table.clear();
	return *this;
}

Table& Table::Set(unsigned int rowindex, unsigned int colindex, std::istream &in)
{
	table[rowindex-1]->Set(colindex,in);
	return *this;
}

Table* Table::Set(unsigned int rowindex, unsigned int colindex, std::string& value)
{
	if (rowindex > 0 && rowindex < table.size())
	{
		table[rowindex - 1]->Set(colindex, value);
		return this;
	}
	else
		return nullptr;
}

Table* Table::Set(unsigned int rowindex, std::string column, std::string value)
{
	if (rowindex > 0 && rowindex < table.size())
	{
		rowindex--;
		for (unsigned int i = 0; i < colname.size(); i++)
		{
			if (colname[i] == column)
				table[rowindex]->Set(i + 1, value);
		}
		return this;
	}
	else
		return nullptr;
}

Table& Table::AddTable(const Table& source)
{
	int count=colname.size();
	int count2 = count;
	for (unsigned int i = 0; i < source.colname.size(); i++)
	{
		colname.push_back(source.colname[i]);
		coltype.push_back(source.coltype[i]);
	}
	count = table.size();
	for (int i = 0; i < count; i++)
	{
		
		for (unsigned int j = count2; j < colname.size(); j++)
		{
			switch (coltype[j])
			{
			case 'i':
			{
				table[i]->Add("0");
				break;
			}
			case 'd':
			{
				table[i]->Add("0.0");
				break;
			case 's':
			{
				table[i]->Add("_");
				break;
			}
			}
			default:
				break;
			}
		}
	}
	return *this;

}
std::vector<std::string> Table::GetCName()
{
	return colname;
}
std::vector<char>& Table::GetCType()
{
	return coltype;
}
int Table::GetID()const
{
	return id;
}
const char* Table::GetName()const
{
	const char* cname;
	cname = name.c_str();
	return cname;
}
unsigned int Table::Size()
{
	return table.size();
}
Table::~Table()
{
	table.clear();
}