#ifndef BaseTypes_h_
#define BaseTypes_h_

#include<iostream>

class Base
{
public:
	virtual ~Base(){};
	virtual void Set(){};
	virtual void Show(){};
	friend std::ostream& operator<<(std::ostream& os, const Base& dt){ return os; };
};
#endif