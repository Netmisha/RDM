#include"Table.h"
bool strloss = false;
Table::Table()
{
	id = ++TID;
	name = "table " + std::to_string(id);
	count = 0;
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

Table& Table::AddRecord(std::istream &in)
{
	Record *rec = new Record();
	char type;
	int id;
	for (unsigned int i = 0; i < colname.size(); i++)
		{
		
			type = coltype[count];
			if (type == 'i')
			{
				
				int value;
				in >> value; 
				if (!in.fail())
				{
					Integer *arg = new Integer(value);
					id = table.size() + 1;
					rec->IdReset(id);
					rec->Add(type, arg);
				}
				else
				{
					in.clear();
					in.ignore(0);
				}
			}
			else
			if (type == 'd')
			{
				double value;
				in >> value;
				if (!in.fail())
				{
					Double *arg = new Double(value);
					id = table.size() + 1;
					rec->IdReset(id);
					rec->Add(type, arg);
				}
				else
				{
					in.clear();
					in.ignore(0);
				}
			}
			else
			if (type == 's')
			{
				std::string value;
				if (strloss)
				{
					strloss = true;
					in.get(); //have some problem with get() here if first input is string
				}
				getline(in, value);
				String *arg = new String(value);
				id = table.size() + 1;
				rec->IdReset(id);
				rec->Add(type, arg);
				in.clear();
				in.ignore(0);
				
			}
			count++;
			
		}
	strloss = true;
	table.push_back(rec);
	count = 0;
	return *this;
}

void Table::DeleteRecord(unsigned int  ID, std::ostream &out)
{
	if (ID > table.size()||ID<1)
		out << "ID out of range\n";
	else
		table.erase(table.begin() + ID - 1);
}

Record& Table::FindRecord(unsigned int ID, std::ostream &out)
{
	if (ID>table.size() || ID < 0)
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
		return *table[ID];
	
}

void Table::Show(std::ostream &out)
{
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

Table::~Table()
{
	table.clear();
}