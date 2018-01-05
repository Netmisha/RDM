#include"Record.h"
#include<cstdlib>
Record::Record()
{
	id = ++ID;
}

Record& Record::Add(std::string value)
{
	char type;
	int ival;
	double dval;
	int checki = 1;;
	for (int i = 0; i < value.size(); i++)
	{
		if (isdigit(value[i]))
			checki *= 1;
		else
			checki = 0;
		checki *= checki;
	}
	int checkd1 = 1;
	int checkd2 = 0;
	for (int i = 0; i < value.size(); i++)
	{
		if (isdigit(value[i]))
		{
			checkd1 *= 1;
		}
		else if (value[i] != '.'&& checkd2)
		{
			checkd2++;
		}
		else
			checkd1 = 0;
		checkd1 *= checkd1;
	}
	if (checkd1&&checkd2 == 1)
	{
		type = 'd';
		dval = atof(value.c_str());
	}
	else if (checki)
	{
		type = 'i';
		ival = atoi(value.c_str());
	}
	else
	{
		type = 's';
	}
	switch (type)
	{
	case 'i':
	{
		Integer *cell = new Integer(ival);
		record.push_back(cell);
		break;
	}
	case 'd':
	{
				Double *cell = new Double(dval);
		record.push_back(cell);
		break;
	}
	case 's':
	{
		String *cell = new String(value);
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
	out << std::endl;
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

bool Record::Find(char type,std::string value)
{
	bool check = false;
	for (int i = 0; i < record.size(); i++)
	{
		switch (type)
		{
		case 'i':
		{
					Integer *temp = (Integer*)record[i];
					if (std::to_string(temp->Get()) == value)
						check = true;
					break;
		}
		case 'd':
		{
					Double *temp = (Double*)record[i];
					if (std::to_string(temp->Get()) == value)
						check = true;
					break;
		}
		case 's':
		{
					String *temp = (String*)record[i];
					if (temp->Get() == value)
						check = true;
					break;
		}
		default:
		{
				   check = false;
				   break;
		}
		}
	}
	return check;
}
Record::~Record()
{
	record.clear();
}