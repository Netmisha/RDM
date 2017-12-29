#include"Double.h"

Double::Double()
{
	value = 0;
};

Double::Double(const double value)
{
	this->value = value;
};

Double::Double(const Double &value)
{
	this->value = value.value;
};

void Double::Set(double value)
{
	this->value = value;
};

void Double::Set(Double value)
{
	this->value = value.value;
};

void Double::Show()
{
	std::cout << value << std::endl;
};

std::ostream& operator<<(std::ostream& os, const Double& dt)
{
	std::cout << dt.value;
	return os;
};
