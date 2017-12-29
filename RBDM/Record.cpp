#include"Record.h"

Record::Record()
{
	id = ++ID;
};

void Record::Add(char type, void* value)
{
	switch (type)
	{
	case 'i':
	{
		Integer *cell = (Integer*)value;
		record.push_back(cell);
		break;
	}
	case 'd':
	{
		Double *cell = (Double*)value;
		record.push_back(cell);
		break;
	}
	case 's':
	{
		String *cell = (String*)value;
		record.push_back(cell);
		break;
	}
	default:
		break;
	}
};

void Record::Show()
{
	for (int i = 0; i < record.size(); i++)
	{
		if (typeid(*record[i]) == typeid(Integer))
			std::cout << *(Integer*)record[i] << " ";
		if (typeid(*record[i]) == typeid(Double))
			std::cout << *(Double*)record[i] << " ";
		if (typeid(*record[i]) == typeid(String))
			std::cout << *(String*)record[i] << " ";
	}
	std::cout << std::endl;
};