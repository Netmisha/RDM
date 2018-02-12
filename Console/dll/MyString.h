#ifndef String_h
#define String_h

#include"BaseForType.h"
#include<string>


class MYLIBRARY_EXPORT String : public BaseForType
{
private:
	std::string value;
public:
	String();
	String(const std::string &val);
	String(const String &val);
	void Set(const std::string val);
	void Set(std::istream &in) override;
	void Set(std::string& val) override;
	void Show(std::ostream &out) override;
	std::string& Get();
	void* Getv() override;
	~String();
	friend std::ostream& operator<<(std::ostream& os, const String& dt);
};
#endif