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
	double temp;
	in >> temp;
	value = temp;
}

void Double::Set(std::string& val)
{
	double temp = atof(val.c_str());
	value = temp;
}
void Double::Show(std::ostream &out)
{
	out << value << " ";
}

double& Double::Get()
{
	return value;
}

void* Double::Getv()
{
	return (void*)&value;
}
std::ostream& operator<<(std::ostream& os, const Double& dt)
{
	os << dt.value;
	return os;
}
