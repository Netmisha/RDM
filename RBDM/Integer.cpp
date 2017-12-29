#include"Integer.h"

Integer::Integer()
{
	value = 0;
};

Integer::Integer(const long value)
{
	this->value = value;
};

Integer::Integer(const Integer &value)
{
	this->value = value.value;
};

void Integer::Set(long value)
{
	this->value = value;
};

void Integer::Set(Integer value)
{
	this->value = value.value;
};

void Integer::Show()
{
	std::cout << value << std::endl;
};

std::ostream& operator<<(std::ostream& os, const Integer& dt)
{
	std::cout << dt.value;
	return os;
};
