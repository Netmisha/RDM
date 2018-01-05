#include<iostream>

#include"Table.h"

int main()
{
	//Table tb;
	//std::vector<std::string> colnames;
	//colnames.push_back("name");
	//colnames.push_back("some integer");
	//colnames.push_back("some double");
	//std::vector<char> coltypes;
	//coltypes.push_back('s');
	//coltypes.push_back('i');
	//coltypes.push_back('d');
	//tb.Create(colnames,coltypes);
	//tb.AddRecord(std::cin).AddRecord(std::cin);// .AddRecord(std::cin).AddRecord(std::cin);
	//tb.Show(std::cout);
	//tb.DeleteRecord(2, std::cout);
	//tb.Show(std::cout);
	//tb.FindRecord(1, std::cout).Set(1);
	//tb.Show(std::cout);
	//tb.Set(1, 1);
	//tb.Show(std::cout);
	/*tb.FindRecord("qwe",std::cout);*/
	Record rec;
	rec.Add("hello").Add("3").Add("3.3");
	std::cout<<rec.Find("3")<<std::endl;
	rec.Show(std::cout);
	Table tb;
	std::vector<std::string> names;
	std::vector<char> types;
	names.push_back("string");
	names.push_back("int");
	names.push_back("double");
	types.push_back('s');
	types.push_back('i');
	types.push_back('d');
	tb.Create(names,types);
	tb.AddRecord(std::cin);
	tb.AddRecord(std::cin);
	tb.Show(std::cout);
	std::cout << std::endl;
	tb.FindRecord("3",std::cout);
	system("pause");
}