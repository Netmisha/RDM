#include<iostream>

#include"Table.h"

int main()
{
	Record rec;
	std::vector<BaseForType*> vec;
	vec.push_back((Integer*)1);
	vec.push_back((Double*)2);
	vec.push_back((String*)"str");
	rec.Create(vec);
	rec.Show(std::cout);
	system("pause");
}