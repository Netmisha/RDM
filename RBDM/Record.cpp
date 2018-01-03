#include"Record.h"

Record::Record()
{
	id = ++ID;
}

Record& Record::Add(char type, void* value)
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
	return *this;
}

void Record::Show(std::ostream &out)
{
	for (unsigned int i = 0; i < record.size(); i++)
	{
		record[i]->Show(out);
	}
	out << "\n";
}

void Record::IdReset(int newid)
{
	id = newid;
}

void Record::Set(int index)
{
	if (index < record.size())
	{
		record[index]->Set(std::cin);
	}
}

Record::~Record()
{
	record.clear();
}