#include"Table.h"
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

Table& Table::AddRecord(std::istream &in)
{
	Record *rec = new Record();
	char type;
	int id;
	for (unsigned int i = 0; i < colname.size(); i++)
	{
		std::string value;
		type = coltype[i];
		if (type == 'i')
		{
			getline(in,value);
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
		if (type == 'd')
		{
			//double value;
			getline(in, value);
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
		if (type == 's')
		{
			//std::string value;
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
//Table& Table::AddRecord(std::istream &in)
//{
//	Record *rec = new Record();
//	char type;
//	int id;
//	for (unsigned int i = 0; i < colname.size(); i++)
//		{
//		
//			type = coltype[i];
//			if (type == 'i')
//			{
//				int value;
//				in >> value; 
//				if (!in.fail())
//				{
//					Integer *arg = new Integer(value);
//					id = table.size() + 1;
//					rec->IdReset(id);
//					rec->Add(type, arg);
//				}
//				else
//				{
//					in.clear();
//					in.ignore(0);
//				}
//			}
//			else
//			if (type == 'd')
//			{
//				double value;
//				in >> value;
//				if (!in.fail())
//				{
//					Double *arg = new Double(value);
//					id = table.size() + 1;
//					rec->IdReset(id);
//					rec->Add(type, arg);
//				}
//				else
//				{
//					in.clear();
//					in.ignore(0);
//				}
//			}
//			else
//			if (type == 's')
//			{
//				std::string value;
//				if (strloss)
//				{
//					strloss = true;
//					in.get(); 
//				}
//				getline(in, value);
//				String *arg = new String(value);
//				id = table.size() + 1;
//				rec->IdReset(id);
//				rec->Add(type, arg);
//				in.clear();
//				in.ignore(0);
//			}
//			
//		}
//	strloss = true;
//	table.push_back(rec);
//	return *this;
//}

void Table::DeleteRecord(unsigned int  index, std::ostream &out)
{
	index--;
	if (index > table.size() || index<0)
		out << "ID out of range\n";
	else
		table.erase(table.begin() + index);
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

Record& Table::FindRecord(std::string value)
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i]->Find(value))
		{
			return *table[i];
		}
	}
}

void Table::FindRecord(std::string value,std::ostream &out)
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i]->Find(value))
		{
			table[i]->Show(out);
		}
	}
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

void Table::Set(unsigned int colindex, unsigned int rowindex,std::istream &in)
{
	table[rowindex-1]->Set(colindex,in);
}

Table::~Table()
{
	table.clear();
}