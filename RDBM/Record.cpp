#include"Record.h"
#include<cstdlib>
Record::Record()
{
	id = ++ID;
}

Record& Record::Add(const std::string &value)
{
	int ival;
	double dval;
	char type=TypeFinder(value);
	switch (type)
	{
	case 'i':
	{
		if (TypeFinder(value) == 'i')
		{
			ival = atoi(value.c_str());
			Integer *cell = new Integer(ival);
			record.push_back(cell);
		}
		else
		{
			record.push_back((Integer*)0);
		}
		break;
	}
	case 'd':
	{
		if (TypeFinder(value) == 'd' || TypeFinder(value) == 'i')
		{
			dval = atof(value.c_str());
			Double *cell = new Double(dval);
			record.push_back(cell);
		}
		else
		{
			record.push_back((Double*)0);
		}
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



Record& Record::Set(unsigned int index, std::istream &in)
{
	index--;
	if (index < record.size()&&index>=0)
		record[index]->Set(in);
	return *this;
}
Record& Record::Set(unsigned int index,std::string value)
{
	index--;
	char type;
	if (typeid(*record[index]) == typeid(Integer))
		type = 'i';
	else if (typeid(*record[index]) == typeid(Double))
		type = 'd';
	else
		type = 's';
	if ((TypeFinder(value) == 'i' || TypeFinder(value) == 'd')&& type=='i')
	{
		if (index < record.size() && index >= 0)
		{
			int temp = atoi(value.c_str());
			record[index]->Set(std::to_string(temp));
		}
	}
	else if ((TypeFinder(value) == 'i' || TypeFinder(value) == 'd') && type == 'd')
	{
		if (index < record.size() && index >= 0)
		{
			double temp = atof(value.c_str());
			record[index]->Set(std::to_string(temp));
		}
	}else	if (TypeFinder(value) == type || type == 's')
	{
		if (index < record.size() && index >= 0)
		{
			record[index]->Set(value);
		}
	}
	return *this;
}
bool Record::Find(const std::string& value)
{
	char type=TypeFinder(value);
	bool check = false;
	for (unsigned int i = 0; i < record.size(); i++)
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

int Record::GetId()
{
	return id;
}
Record::~Record()
{
	record.clear();
}

char TypeFinder(std::string value)
{
	char type;
	int checki = 1;
	int checkd1 = 1;
	int checkd2 = 0;
	for (unsigned int i = 0; i < value.size(); i++)
	{
		if (isdigit(value[i]))
		{
			checki *= 1;
			checkd1 *= 1;
		}
		else if (value[i] == '.')
		{
			checkd2++;
		}
		else
		{
			checki = 0;
			checkd1 = 0;
		}
		checki *= checki;
		checkd1 *= checkd1;
	}
	if (checkd1==1&&checkd2 == 1)
	{
		type = 'd';
	}
	else if (checki)
	{
		type = 'i';
	}
	else
	{
		type = 's';
	}
	return type;
}