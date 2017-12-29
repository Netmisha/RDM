#include<iostream>
#include"Record.h"

int main()
{
	Integer *i = new Integer;
	Double *d = new Double;
	String *str = new String;
	i->Set(3);
	i->Show();
	d->Set(4.4);
	d->Show();
	str->Set("hello");
	str->Show();
	Record rec;
	rec.Add('i', i);
	rec.Add('s', str);
	rec.Add('d', d);
	rec.Show();
	system("pause");
}