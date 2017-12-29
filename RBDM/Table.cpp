#include"Table.h"

Table::Table()
{
	id = ++TID;
	name = "table " + std::to_string(id);
};
void Table::ArrRecord()
{
	Record *rec = new Record();
	char type;

	while (true)
	{
		std::cin >> type;
		if (type == 'i')
		{
			long value;
			std::cin >> value;
			if (!std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				Integer *arg = new Integer(value);
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
				std::cin.clear();
				std::cin.ignore();
				Double *arg = new Double(value);
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
			std::cin >> value;
			String *arg = new String(value);
			rec->Add(type, arg);
		}
		else
			break;
	}
	table.push_back(rec);
};