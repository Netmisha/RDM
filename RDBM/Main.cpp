#include<iostream>

#include"Table.h"

int main()
{

	Record rec;
	rec.Add("str").Add("str2").Add("str3");
	rec.Show(std::cout);
	Table tb;
	tb.Create({"string name","int int","double double"});
	tb.AddRecord({ "name1", "1", "2.2" }).AddRecord({ "name2", "2", "3.2" }).AddRecord({ "name3", "3", "4.2" }).Show(std::cout).Set(2,"double","5.6").Show(std::cout);
	Table tb2;
	tb2.Create({"int int","string str"});
	tb2.AddRecord({ "9", "str" }).AddRecord({ "4", "trs" }).AddColumn("int","int");
	tb2.AddTable(tb);
	tb2.Show(std::cout);
	tb2.AddTable(tb).Show(std::cout);
	Table tb3;
	tb3.AddTable(tb2).Show(std::cout);
	system("pause");
}