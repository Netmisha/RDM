#ifndef Integer_h_
#define Integer_h_

#include"BaseForType.h"

class Integer : public BaseForType
{
private:
	int value;
public:
	Integer();
	Integer(int &val);
	Integer(const Integer &val);
	void Set(const int val) ;
	void Set(std::istream &in)override;
	void Set(std::string& val)override;
	void Show(std::ostream &out) override;
	int& Get();
	~Integer(){};
	friend std::ostream& operator<<(std::ostream& os, const Integer& dt);
};
#endif