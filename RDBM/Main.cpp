#include<iostream>

#include"Table.h"

int main()
{
	
	Table tb2;
	tb2.Create({ "srting name", "int int","double dab" });
	tb2.AddRecord(std::cin).AddRecord(std::cin);
	tb2.Show(std::cout);
	system("pause");
}