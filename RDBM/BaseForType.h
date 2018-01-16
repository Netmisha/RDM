#ifndef BaseForType_h_
#define BaseForType_h_

#include<iostream>

class BaseForType
{
public:
	virtual ~BaseForType(){};
	virtual void Set(std::istream &in) = 0;
	virtual void Set(std::string& value) = 0;
	virtual void Show(std::ostream &out) = 0;
	virtual void* Getv() = 0;
};
#endif