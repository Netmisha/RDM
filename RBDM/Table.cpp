#include"Table.h"

Table::Table()
{
	id = ++TID;
	name = "table " + std::to_string(id);
}
void Table::ArrRecord()
{
	Record *rec = new Record();
	char type;
	int id;
	while (true)
	{
		std::cin >> type;
		if (type == 'i')
		{
			long value;
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

void Table::DeleteRecord(unsigned  ID)
{
	if (ID > table.size()||ID<1)
		std::cout << "ID out of range\n";
	else
		table.erase(table.begin() + ID - 1);
}

Record& Table::FindRecord(unsigned ID)
{
	return *table[ID];
}

void Table::Show()
{
	Record *ptr;
	for (unsigned i = 0; i < table.size(); i++)
	{
		ptr = table[i];
		ptr->Show();
	}
}

void Table::Clear()
{
	for (unsigned i = 0; i < table.size(); i++)
	{
		Record *temp = new Record;
		temp = (Record*)table[i];
		temp->Clear();
		table.erase(table.begin()+i);
		table.insert(table.begin()+i,1,temp);
	}
}

void Table::Delete()
{
	table.clear();
}