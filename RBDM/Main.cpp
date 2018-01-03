#include<iostream>

#include"Table.h"

int main()
{

	/*Table tb;
	std::vector<std::string> names;
	names.push_back("name");
	names.push_back("int");
	names.push_back("int");
	std::vector<char> types;
	types.push_back('s');
	types.push_back('i');
	types.push_back('i');
	tb.Create(names,types);
	tb.AddRecord(std::cin).AddRecord(std::cin).AddRecord(std::cin);
	tb.Show(std::cout);*/
	Record rec;
	String *str = new String;
	str->Set("hello");
	rec.Add('s',str);
	Integer *i = new Integer;
	i->Set(3);
	rec.Add('i',i);
	Double *d = new Double;
	d->Set(4.4);
	rec.Add('d', d);
	rec.Show(std::cout);
	Table tb;
	std::vector<std::string> colnames;
	colnames.push_back("some integer");
	colnames.push_back("name");
	colnames.push_back("some double");
	std::vector<char> coltypes;
	coltypes.push_back('i');
	coltypes.push_back('s');
	coltypes.push_back('d');
	tb.Create(colnames,coltypes);
	tb.AddRecord(std::cin).AddRecord(std::cin).AddRecord(std::cin).AddRecord(std::cin);
	tb.Show(std::cout);
	system("pause");
}