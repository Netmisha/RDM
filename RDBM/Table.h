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
	std::vector<std::string> colname;
	std::vector<char> coltype;
	std::vector<Record*> table;
public:
	Table();
	Table& Create(std::vector<std::string>& names, std::vector<char>& coltypes);
	Table& Create(std::initializer_list<std::string> list);
	Table& AddRecord(std::istream &in);
	Table& AddRecord(std::vector<std::string> slist);
	Table& AddColumn(const std::string& type, const std::string& name);
	Table& DeleteRecord(unsigned int index);
	Record* FindRecord(unsigned int index);
	Record* FindRecord(const std::string& value);
	Table& FindRecords(const std::string& value, std::ostream &out);
	Table& Show(std::ostream &out);
	Table& Delete();
	Table& Set(unsigned int rowindex, unsigned int colindex, std::istream &in);
	Table* Set(unsigned int rowindex, unsigned int colindex, std::string& value);
	Table* Set(unsigned int rowindex, std::string column, std::string value);
	Table& AddTable(const Table& source);
	std::vector<std::string>& GetCName();
	std::vector<char>& GetCType();
	int GetID()const;
	const char* GetName()const;
	unsigned int Size();
	Record* GetRecord(unsigned int index);
	~Table();
};
#endif