#ifndef Table_h_
#define Table_h_

#include"Record.h"
#include<vector>
#include<string>

static unsigned TID = 0;
class Table
{
private:
	int id;
	std::string name;
	std::vector<Record*> table;
public:
	Table();
	void AddRecord();
	void DeleteRecord(unsigned int ID);
	Record& FindRecord(unsigned int ID);
	void Show(std::ostream &out);
	void Clear();
	void Delete();
	~Table();
};
#endif