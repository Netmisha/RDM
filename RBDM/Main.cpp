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
	Integer *x = new Integer;
	Integer *y = new Integer;
	x->Set(-3);
	y->Set(3);
	rec.Add('i',x);
	rec.Add('i', y);
	std::cout<<rec.Find('i', "-3");
	system("pause");
}