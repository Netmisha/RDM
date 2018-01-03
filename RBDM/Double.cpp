#include"Double.h"

Double::Double()
{
	value = 0;
}

Double::Double(double &val)
{
	 value = val;
}

Double::Double(const Double &val)
{
	 value = val.value;
}

void Double::Set(const double val)
{
	 value = val;
}

void Double::Set(std::istream &in)
{
	in >> this->value;
}

void Double::Show(std::ostream &out)
{
	out << value << " ";
}

std::ostream& operator<<(std::ostream& os, const Double& dt)
{
	os << dt.value;
	return os;
}
