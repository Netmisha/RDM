#include<iostream>

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
	tb2.AddTable(tb).AddColumn("int", "i").Show(std::cout);
	tb2.AddRecord({ "3", "q", "4", "w","3","4.4","3" }).Show(std::cout);
	system("pause");
}
