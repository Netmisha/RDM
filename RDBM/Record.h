#ifndef Record_h_
#define Record_h

#include<vector>
#include<string>
#include"Integer.h"
#include"Double.h"
#include"String.h"

static unsigned int ID = 0;

class Record
{
private:
	int id;
	std::vector<BaseForType*> record;
public:
	Record();
	Record& Add(const std::string& value);
	void Show(std::ostream &out);
	void IdReset(int newid);
	Record& Set(unsigned int index, std::istream &in);
	bool Find(const std::string& value);
	int GetId();
	~Record();
};
char TypeFinder(std::string value);
#endif