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

void Integer::Set()
{
	std::cin >> this->value;
}

void Integer::Set(const int val)
{
	 value = val;
}

void Integer::Show(std::ostream &out)
{
	out << value << " ";
}

std::ostream& operator<<(std::ostream& os, const Integer& dt)
{
	std::cout << dt.value;
	return os;
}
