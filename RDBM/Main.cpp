#include<iostream>

#include"Table.h"

int main()
{

	Table tb2;
	tb2.Create({ "srting name", "int int", "double dab" });
	tb2.AddRecord({ "name", "4", "4.4" });
	tb2.AddRecord({ "name2", "41", "41.4" });
	tb2.Show(std::cout);
	tb2.AddColumn("string", "int").Set(1, 4, "qwe");
	tb2.Show(std::cout);
	Table tb;
	tb.Create({ "string na_me", "int int" });
	tb.AddRecord({ "name 'add sad'", "2" }).Show(std::cout);
	Table tb3;
	tb3.Create({ "int int", "int int" });
	tb3.AddRecord({"smth 1", "smth 2"}).Show(std::cout);
	system("pause");
}