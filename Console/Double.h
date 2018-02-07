#ifndef Double_h_
#define Double_h_

#include"BaseForType.h"

class MYLIBRARY_EXPORT Double : public BaseForType
{
private:
	double value;
public:
	Double();
	Double(double &val);
	Double(const Double &val);
	void Set(const double val);
	void Set(std::istream &in) override;
	void Set(std::string& val) override;
	void Show(std::ostream &out) override;
	double& Get();
	void* Getv() override;
	~Double(){ LOG_INFO("Double object destructor called"); };
	friend std::ostream& operator<<(std::ostream& os, const Double& dt);
};
#endif