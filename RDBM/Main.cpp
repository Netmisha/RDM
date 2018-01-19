#include<iostream>
#include"XML.h"
#include"Table.h"

int main()
{
	Table tb;
	tb.Create({"string name","int int","double double"});
	tb.AddRecord({ "name1", "1", "2.2" }).AddRecord({ "name2", "2", "3.2" }).AddRecord({ "name3", "3", "4.2" }).Show(std::cout);
	tb.Set(2, "double", "5.6");
	tb.Show(std::cout);
	Table tb2;
	tb2.Create({"int int","string str"});
	tb2.AddRecord({ "9", "str" }).AddRecord({ "4", "trs" }).AddColumn("int","int").Show(std::cout);
	std::cout << std::endl;
	tb2.AddTable(tb).AddColumn("int", "i").Show(std::cout);
	std::cout << std::endl;
	tb2.AddRecord({ "3", "q", "4", "w","3","4.4","3" }).Show(std::cout);
	std::cout << std::endl;
	tb2.FindRecord(2);
	tb2.Show(std::cout);
	std::vector<std::string> vec;
	vec.push_back("name4");
	vec.push_back("4");
	vec.push_back("4.4");
	tb.AddRecord(vec);
	tb.Show(std::cout);
	std::cout << "----------------------------\n";
	//XMLDecl();
	Table tb3;
	Table tb4;
	tb4.Create({ "int int", "string str" });
	tb4.AddRecord({ "1", "str" }).AddRecord({ "2", "str2" });
	BuildTable(tb3, 2);
	tb3.AddRecord({ "3", "q", "4", "w", "3", "4.4", "3" });
	AddData(tb3);
	Table tb5;
	BuildTable(tb5,4);
	tb5.AddTable(tb2);
	AddData(tb);
	AddStructure(tb);
	AddData(tb2);
	AddStructure(tb2);
	AddData(tb3);
	AddStructure(tb3);
	AddData(tb4);
	AddStructure(tb4);
	AddData(tb5);
	AddStructure(tb5);
	tb3.AddTable(tb3);
	tb3.AddColumn("int","some_int");
	AddData(tb3);
	AddStructure(tb3);
	Clear();
	system("pause");
}
