#include"String.h"

String::String()
{
	value = " ";
}

String::String( std::string &val)
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

void String::Set(String val)
{
	 value = val.value;
}

void String::Show()
{
	std::cout << value << std::endl;
}

std::ostream& operator<<(std::ostream& os, const String& dt)
{
	std::cout << dt.value;
	return os;
}