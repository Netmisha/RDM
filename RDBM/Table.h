#ifndef Table_h_
#define Table_h_

#include"Record.h"
#include<vector>
#include<string>
#include<initializer_list>

static unsigned TID = 0;
class Table
{
private:
	int id;
	std::string name;
	std::vector<std::string> colname;
	std::vector<char> coltype;
	std::vector<Record*> table;
public:
	Table();
	Table& Create(std::vector<std::string> names, std::vector<char> coltypes);
	Table& Create(std::initializer_list<std::string> l);
	Table& AddRecord(std::istream &in);
	void DeleteRecord(unsigned int index);
	Record& FindRecord(unsigned int index, std::ostream &out);
	Record& FindRecord(const std::string& value);
	void FindRecords(const std::string& value,std::ostream &out);
	void Show(std::ostream &out);
	void Delete();
	void Set(unsigned int colindex,unsigned int rowindex,std::istream &in);
	~Table();
};
#endif