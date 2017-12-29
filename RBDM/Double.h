#ifndef Double_h_
#define Double_h_

#include"Base.h"

class Double :public BaseForType
{
private:
	double value;
public:
	using BaseForType::Set;
	Double();
	Double(double &value);
	Double(const Double &value);
	void Set(const double value);
	virtual void Set(Double value);
	void Show() override;
	~Double(){};
	friend std::ostream& operator<<(std::ostream& os, const Double& dt);
};
#endif