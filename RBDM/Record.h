#ifndef Record_h_
#define Record_h

#include<vector>
#include<string>
#include"Integer.h"
#include"Double.h"
#include"String.h"

static int ID = 0;

class Record
{
private:
	int id;
	std::vector<Base*> record;
	int count;
public:
	Record();
	void Add(char type, void* value);
	void Show();
	~Record(){};
};
#endif