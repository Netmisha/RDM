#include<iostream>

#include"Table.h"

int main()
{
	Table tb;
	std::vector<std::string> names;
	std::vector<char> types;
	names.push_back("string");
	names.push_back("int");
	names.push_back("double");
	//names.push_back("double");
	types.push_back('s');
	types.push_back('i');
	types.push_back('d');
	//types.push_back('d');
	tb.Create(names,types);
	tb.AddRecord(std::cin);
	tb.AddRecord(std::cin);
	tb.Show(std::cout);
	std::cout << std::endl;
	tb.FindRecords("3",std::cout);
	tb.DeleteRecord(1);
	tb.Show(std::cout);
	Table tb2;
	tb2.Create({ "srting name", "int int" });
	tb2.Show(std::cout);
	system("pause");
}