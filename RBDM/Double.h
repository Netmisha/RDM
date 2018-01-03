#ifndef Double_h_
#define Double_h_

#include"BaseForType.h"

class Double : public BaseForType
{
private:
	double value;
public:
	Double();
	Double(double &value);
	Double(const Double &value);
	void Set(const double value);
	void Set(std::istream &in) override;
	void Show(std::ostream &out) override;
	~Double(){};
	friend std::ostream& operator<<(std::ostream& os, const Double& dt);
};
#endif