#include"String.h"

String::String()
{
	value = " ";
};

String::String(const std::string value)
{
	this->value = value;
};

String::String(const String &value)
{
	this->value = value.value;
};

void String::Set(std::string value)
{
	this->value = value;
};

void String::Set(String value)
{
	this->value = value.value;
};

void String::Show()
{
	std::cout << value << std::endl;
};

std::ostream& operator<<(std::ostream& os, const String& dt)
{
	std::cout << dt.value;
	return os;
};