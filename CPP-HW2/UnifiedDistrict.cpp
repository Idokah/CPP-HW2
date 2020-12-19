#include "UnifiedDistrict.h"

UnifiedDistrict::UnifiedDistrict(char* name, int representativeNum) : District(name, representativeNum){}



void UnifiedDistrict::printType(std::ostream& os) const
{
	os << "District Type: Unified";
}