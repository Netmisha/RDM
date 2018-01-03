#include"Table.h"

Table::Table()
{
	id = ++TID;
	name = "table " + std::to_string(id);
}
void Table::AddRecord()
{
	Record *rec = new Record();
	char type;
	int id;
	while (true)
	{
		std::cin >> type;
		if (type == 'i')
		{
			int value;
			std::cin >> value;
			if (!std::cin.fail())
			{
				Integer *arg = new Integer(value);
				id = table.size() + 1;
				rec->IdReset(id);
				rec->Add(type, arg);
			}
			else
			{
				std::cout << "non integer value" << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
		}
		else
		if (type == 'd')
		{
			double value;
			std::cin >> value;
			if (!std::cin.fail())
			{
				Double *arg = new Double(value);
				id = table.size() + 1;
				rec->IdReset(id);
				rec->Add(type, arg);
			}
			else
			{
				std::cout << "non digital value" << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
		}
		else
		if (type == 's')
		{
			std::string value;
			std::cin.get();
			getline(std::cin, value);
			String *arg = new String(value);
			id = table.size() + 1;
			rec->IdReset(id);
			rec->Add(type, arg);
		}
		else
			break;
	}
	table.push_back(rec);
}

void Table::DeleteRecord(unsigned int  ID)
{
	if (ID > table.size()||ID<1)
		std::cout << "ID out of range\n";
	else
		table.erase(table.begin() + ID - 1);
}

Record& Table::FindRecord(unsigned int ID)
{
	if (ID>table.size() || ID < 0)
	{
		if (table.size() == 0)
		{
			Record *rec = new Record;
			std::cout << "Table is empty.\nFirst record was created(empty)\n";
			table.push_back(rec);
			return *table[0];
		}
		std::cout << "ID out of range\n";
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