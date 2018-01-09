#include<iostream>

#include"Table.h"

int main()
{
	
	Table tb2;
	tb2.Create({ "srting name", "int int", "double dab" });
	tb2.AddRecord({ "name", "4", "4.4","4" });
	tb2.Show(std::cout);
	Record rec;
	rec.Add("qwe5").Add("2");
	rec.Show(std::cout);
	rec.Set(1,"4");
	rec.Show(std::cout);
	rec.Set(1, "hello");
	rec.Show(std::cout);
	system("pause");
}