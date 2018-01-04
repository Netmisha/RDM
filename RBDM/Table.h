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
	//int count;
	std::string name;
	std::vector<std::string> colname;
	std::vector<char> coltype;
	std::vector<Record*> table;
public:
	Table();
	Table& Create(std::vector<std::string> names, std::vector<char> coltypes);
	Table& AddRecord(std::istream &in);
	void DeleteRecord(unsigned int ID, std::ostream &out);
	Record& FindRecord(unsigned int ID, std::ostream &out);
	void Show(std::ostream &out);
	void Delete();
	~Table();
};
#endif