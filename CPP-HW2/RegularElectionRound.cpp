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

void RegularElectionRound::printAllDistricts()
{
	for (int i = 0; i < districtsLogSize; ++i) {
		cout << *(districts[i]) << endl;
	}
}