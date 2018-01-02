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

void Record::Show(std::ostream &out)
{
	for (unsigned int i = 0; i < record.size(); i++)
	{
		record[i]->Show(out);
	}
}

void Record::IdReset(int newid)
{
	id = newid;
}

void Record::Clear()
{
	for (unsigned int i = 0; i < record.size(); i++)
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

Record::~Record()
{
	record.clear();
}