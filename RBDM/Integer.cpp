#include"Integer.h"

Integer::Integer()
{
	value = 0;
};

Integer::Integer(long &val)
{
	 value = val;
};

Integer::Integer(const Integer &val)
{
	 value = val.value;
};

void Integer::Set(const long val)
{
	 value = val;
};

void Integer::Set(Integer val)
{
	 value = val.value;
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
