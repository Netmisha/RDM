#include"String.h"

String::String()
{
	value = " ";
}

String::String(const std::string &val)
{
	 value = val;
}

String::String(const String &val)
{
	 value = val.value;
}

void String::Set(const std::string val)
{
	 value = val;
}

void String::Set(std::istream &in)
{
	in.get();
	std::string temp;
	getline(in, temp);
	value = temp;
}

void String::Set(std::string& val)
{
	value = val;
}

void String::Show(std::ostream &out)
{
	out << value << " ";
}

std::string String::Get()
{
	return value;
}
void* String::Getv()
{
	return (void*)&value;
}
std::ostream& operator<<(std::ostream& os, const String& dt)
{
	os << dt.value;
	return os;
}