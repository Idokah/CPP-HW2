#include "RegularElectionRound.h"

RegularElectionRound::RegularElectionRound(int day, int month, int year) : ElectionRound(day, month, year) {}

void RegularElectionRound::addDistrict(District* district)
{
	if (this->districtsLogSize == this->districtsPhySize)
	{
		this->increaseDistrictsArrSize();
	}
	this->districts[this->districtsLogSize++] = district;
}

void RegularElectionRound::printAllDistricts () const
{
	for (int i = 0; i < districtsLogSize; ++i) {
		cout << *(districts[i]) << endl;
	}
}

void RegularElectionRound::save(ostream& out) const
{
	out.write(rcastcc(ELECTION_ROUND_TYPE::regular), sizeof(ELECTION_ROUND_TYPE::regular));
	this->ElectionRound::save(out);
}
