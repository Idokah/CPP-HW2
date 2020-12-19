#include "DividedDistrict.h"

DividedDistrict::DividedDistrict(char* name, int representativeNum) : District(name, representativeNum) {}

void DividedDistrict::printType(std::ostream& os) const
{
	os << "District Type: Divided";
}
