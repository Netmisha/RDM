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
	
public:
	std::vector<BaseForType*> record;
	Record();
	Record& Add(std::string value);
	void Show(std::ostream &out);
	void IdReset(int newid);
	Record& Set(int index,std::istream &in);
	bool Find(std::string value);
	int GetId();
	~Record();
};
#endif