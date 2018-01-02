#include<iostream>

#include"Table.h"

int main()
{
	Table tb;
	tb.ArrRecord();
	tb.ArrRecord();
	tb.Show();
	tb.Clear();
	tb.Show();
	tb.Delete();
	tb.Show();
	system("pause");
}