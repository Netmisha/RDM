#include<iostream>

#include"Table.h"

int main()
{
	Table tb;
	tb.ArrRecord();
	tb.ArrRecord();
	tb.Show();
	Record rc;
	rc = tb.FindRecord(0);
	rc.Show();
	system("pause");
}