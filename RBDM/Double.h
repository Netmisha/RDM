#ifndef Double_h_
#define Double_h_

#include"Base.h"

class Double :public Base
{
private:
	double value;
public:
	Double();
	Double(double value);
	Double(const Double &value);
	void Set(const double value);
	void Set(Double value);
	void Show();
	~Double(){};
	friend std::ostream& operator<<(std::ostream& os, const Double& dt);
};
#endif