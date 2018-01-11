#include<iostream>

#include"Table.h"

int main()
{

	Record rec;
	rec.Add("str").Add("str2").Add("str3");
	rec.Show(std::cout);
	Table tb;
	tb.Create({"string name","int int","double double"});
	tb.AddRecord({ "name1", "1", "2.2" }).AddRecord({ "name2", "2", "3.2" }).AddRecord({ "name3", "3", "4.2" });
	tb.Show(std::cout);
	tb.Set(3,"int","5.6");
	tb.Show(std::cout);
	system("pause");
}