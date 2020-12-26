#pragma once
#pragma once
#include <iostream>
#include "ElectionRound.h"
#include "Citizen.h"
#include "District.h"
#include "Party.h"

class RegularElectionRound : public ElectionRound {
	public:
		RegularElectionRound(int day, int month, int year);
		virtual void addDistrict(District* district);
		virtual void printAllDistricts() const;
		void save(ostream& out) const;
	private:
};

