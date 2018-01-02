#include<iostream>

#include"Table.h"

int main()
{
	Table tb;
	tb.ArrRecord();
	tb.ArrRecord();
	tb.ArrRecord();
	tb.ArrRecord();
	tb.DeleteRecord(-1);
	tb.Show();
	tb.DeleteRecord(9);
	tb.Show();
	tb.DeleteRecord(1);
	tb.Show();
	system("pause");
}