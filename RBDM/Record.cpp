#include"Record.h"

Record::Record()
{
	id = ++ID;
}

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
}

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
}

void Record::IdReset(int newid)
{
	id = newid;
}

void Record::Clear()
{
	for (unsigned i = 0; i < record.size(); i++)
	{
		if (typeid(*record[i]) == typeid(Integer))
		{
			Integer *temp = new Integer;
			temp = (Integer*)record[i];
			temp->Set(0);
			record.erase(record.begin()+i);
			record.insert(record.begin() + i, 1,temp);
		}
		if (typeid(*record[i]) == typeid(Double))
		{
			Double *temp = new Double;
			temp = (Double*)record[i];
			temp->Set(0);
			record.erase(record.begin() + i);
			record.insert(record.begin() + i, 1, temp);
		}
		if (typeid(*record[i]) == typeid(String))
		{
			String *temp = new String;
			temp = (String*)record[i];
			temp->Set(" ");
			record.erase(record.begin() + i);
			record.insert(record.begin() + i, 1, temp);
		}
	}
}