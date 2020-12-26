#include "SimpleElectionRound.h"
#include "DividedDistrict.h"

SimpleElectionRound::SimpleElectionRound(int day, int month, int year) : ElectionRound(day, month, year) {
    // TODO - check about represantives number
    District* district = new DividedDistrict(const_cast<char*>("Dummy"), 10);
    this->districts[this->districtsLogSize++] = district;
}

void SimpleElectionRound::addDistrict(District* district)
{
	cout << "im sorry but you cant add district, it a simple election round!" << endl;
}

void SimpleElectionRound::printAllDistricts() const
{
    cout << "im sorry but you dont have any districts, it a simple election round!" << endl;
}

void SimpleElectionRound::save(ostream& out) const
{
    out.write(rcastcc(ELECTION_ROUND_TYPE::simple), sizeof(ELECTION_ROUND_TYPE::simple));
    this->ElectionRound::save(out);
}