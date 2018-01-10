#include<iostream>

#include"Table.h"

int main()
{
	
	Table tb2;
	tb2.Create({ "srting name", "int int", "double dab" });
	tb2.AddRecord({ "name", "4", "4.4"});
	tb2.AddRecord({ "name2", "41", "41.4" });
	tb2.Show(std::cout);
	tb2.AddColumn("string", "int").Set(1,4,"qwe");
	tb2.Show(std::cout);
	system("pause");
}