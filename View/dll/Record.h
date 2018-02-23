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
	Record& Add(const std::string value);
	Record& Show(std::ostream &out);
	Record& Set(unsigned int index, std::istream &in);
	Record& Set(unsigned int index, std::string value);
	Record& Delete(unsigned int index);
	bool Find(const std::string value);
	int GetId();
	void ChangeID(int x);
	~Record();
};
MYLIBRARY_EXPORT char TypeFinder(const std::string value);
#endif