#ifndef String_h
#define String_h

#include"Base.h"
#include<string>

class String :public Base
{
private:
	std::string value;
public:
	String();
	String(std::string value);
	String(const String &value);
	void Set(const std::string value);
	void Set(String value);
	void Show();
	~String(){};
	friend std::ostream& operator<<(std::ostream& os, const String& dt);
};
#endif