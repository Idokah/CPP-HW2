#pragma once
#include "District.h"

// TODO protected?
class UnifiedDistrict : public District {
public:
	UnifiedDistrict(char* name, int representativeNum);
	virtual void printType(std::ostream& os) const;
	virtual void printElectionResult(int partiesLogSize, Party** parties);

	void save(ostream& out) const;

	void load(istream& in);

};
