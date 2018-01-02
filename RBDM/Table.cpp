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

void Table::Show()
{
	Record *ptr;
	for (int i = 0; i < table.size(); i++)
	{
		ptr = table[i];
		ptr->Show();
	}
}