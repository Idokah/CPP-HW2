#pragma once
#include <iostream>
using namespace std;
#include "District.h"

// TODO protected?
class DividedDistrict : public District {
public:
	DividedDistrict(char* name, int representativeNum);
	virtual void printType(std::ostream& os) const;
};
