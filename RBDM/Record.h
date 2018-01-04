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
	Record& Add(char type,void *value);
	void Show(std::ostream &out);
	void IdReset(int newid);
	Record& Set(int index);
	bool Find(char type,std::string value);
	~Record();
};
#endif