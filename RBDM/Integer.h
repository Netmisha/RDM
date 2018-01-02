#ifndef Integer_h_
#define Integer_h_

#include"BaseForType.h"

class Integer : public BaseForType
{
private:
	int value;
public:
	Integer();
	Integer(int &value);
	Integer(const Integer &value);
	void Set(const int value) ;
	void Set()override;
	void Show(std::ostream &out) override;
	~Integer(){};
	friend std::ostream& operator<<(std::ostream& os, const Integer& dt);
};
#endif