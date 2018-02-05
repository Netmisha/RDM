#ifndef Record_h_
#define Record_h

#include<vector>
#include<string>
#include"Integer.h"
#include"Double.h"
#include"MyString.h"

static unsigned int ID = 0;

class MYLIBRARY_EXPORT Record
{
private:
	int id;
public:
	std::vector<BaseForType*> record;
	Record();
	Record& Add(const std::string& value);
	Record& Show(std::ostream &out);
	Record& Set(unsigned int index, std::istream &in);
	Record& Set(unsigned int index, std::string value);
	bool Find(const std::string& value);
	int GetId();
	~Record();
};
char TypeFinder(std::string value);
#endif