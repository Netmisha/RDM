#include"Integer.h"

Integer::Integer()
{
	value = 0;
}

Integer::Integer(int &val)
{
	 value = val;
}

Integer::Integer(const Integer &val)
{
	 value = val.value;
}

void Integer::Set(std::istream &in)
{
	int temp;
	in >> temp;
	value = temp;
}

void Integer::Set(const int val)
{
	 value = val;
}
void Integer::Set(std::string& val)
{
	int temp = atoi(val.c_str());
	value = temp;
}

void Integer::Show(std::ostream &out)
{
	out << value << " ";
}

int& Integer::Get()
{
	return value;
}
void* Integer::Getv(int x )
{
	int *ptr = &value;
	return ptr;
}
std::ostream& operator<<(std::ostream& os, const Integer& dt)
{
	os << dt.value;
	return os;
}
