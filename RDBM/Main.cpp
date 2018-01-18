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
	XMLDecl();
	Table tb3;
	BuildTable(tb3, std::cout, 1);
	tb3.AddColumn("integer","number");
	vec.push_back("5");
	tb3.AddRecord(vec);
	AddStructure(tb3);
	AddData(tb3);
	tb3.Show(std::cout);
	system("pause");
}
