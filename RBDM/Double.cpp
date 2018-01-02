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

void Double::Set(Double val)
{
	 value = val.value;
}

void Double::Show()
{
	std::cout << value << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Double& dt)
{
	std::cout << dt.value;
	return os;
}
