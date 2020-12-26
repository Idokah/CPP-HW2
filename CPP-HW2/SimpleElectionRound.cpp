#include "SimpleElectionRound.h"
#include "DividedDistrict.h"
// TODO
SimpleElectionRound::SimpleElectionRound()
{
}

SimpleElectionRound::SimpleElectionRound(int day, int month, int year) : ElectionRound(day, month, year) {
    // TODO - check about represantives number
    District* district = new DividedDistrict(const_cast<char*>("Dummy"), 10);
    this->districts[this->districtsLogSize++] = district;
}

SimpleElectionRound::SimpleElectionRound(istream& in)
{
    this->load(in);
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
    int type = (int)ELECTION_ROUND_TYPE::simple;
    out.write(rcastcc(&type), sizeof(type));
    this->ElectionRound::save(out);
}