#ifndef BaseTypes_h_
#define BaseTypes_h_

#include<iostream>

class BaseForType
{
public:
	virtual ~BaseForType(){};
	virtual void Set(){};
	virtual void Show(){};
	friend std::ostream& operator<<(std::ostream& os, const BaseForType& dt){ return os; };
};
#endif