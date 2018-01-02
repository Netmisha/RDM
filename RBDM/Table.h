#ifndef Table_h_
#define Table_h_

#include"Record.h"
#include<vector>
#include<string>

static int TID = 0;
class Table
{
private:
	int id;
	std::string name;
	std::vector<Record*> table;
public:
	Table();
	void ArrRecord();
	void DeleteRecord(unsigned ID);
	Record& FindRecord(unsigned ID);
	void Show();
	void Clear();
	void Delete();
	~Table(){};
};
#endif