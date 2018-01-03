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

Record& Record::Create(std::vector<BaseForType*> vec)
{
	Record *temp = new Record;
	char type;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (typeid(vec[i]) == typeid(int))
			type = 'i';
		if (typeid(vec[i]) == typeid(double))
			type = 'd';
		if (typeid(vec[i]) == typeid(std::string))
			type = 's';
		temp->Add(type,vec[i]);
	}
	return *temp;
}

Record::~Record()
{
	record.clear();
}