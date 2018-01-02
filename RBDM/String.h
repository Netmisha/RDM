#ifndef String_h
#define String_h

#include"BaseForType.h"
#include<string>

class String : public BaseForType
{
private:
	std::string value;
public:
	String();
	String(std::string &value);
	String(const String &value);
	void Set(const std::string value);
	void Set() override;
	void Show(std::ostream &out) override;
	~String(){};
	friend std::ostream& operator<<(std::ostream& os, const String& dt);
};
#endif