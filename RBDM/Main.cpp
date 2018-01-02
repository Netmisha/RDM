#include<iostream>

#include"Table.h"

int main()
{
	Table tb;
	tb.AddRecord();
	Record rc;
	rc = tb.FindRecord(0);
	rc.Show(std::cout);
	system("pause");
}