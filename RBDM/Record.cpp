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

Record& Record::Set(int index)
{
	index--;
	if (index < record.size()&&index>=0)
	{
		record[index]->Set(std::cin);
	}
	return *this;
}

Record::~Record()
{
	record.clear();
}