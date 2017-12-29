#ifndef Integer_h_
#define Integer_h_

#include"Base.h"

class Integer :public Base
{
private:
	long value;
public:
	Integer();
	Integer(long value);
	Integer(const Integer &value);
	void Set(const long value);
	void Set(Integer value);
	void Show();
	~Integer(){};
	friend std::ostream& operator<<(std::ostream& os, const Integer& dt);
};
#endif