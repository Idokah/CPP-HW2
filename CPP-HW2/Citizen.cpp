#include "Citizen.h"
#include "District.h"
#include <iostream>

using namespace std;

int MAX_STRING_LEN = 100;

char* getString(const char* input) {
	int inputLen = strlen(input);
	char* str = new char[inputLen + 1];
	memcpy(str, input, inputLen);
	str[inputLen] = '\0';
	return str;
}
// TODO
Citizen::Citizen() {}

Citizen::Citizen(char* name, char* id, unsigned int birthYear, District* district) : isPartyMember(false), isAlreadyVote(false) {
    this->name = getString(name);
    this->id = getString(id);
    this->birthYear = birthYear;
    this->district = district;
}

Citizen::Citizen(const Citizen& other) {
    *this = other;
}

Citizen::~Citizen() {
    delete[] name;
    delete[] id;
}

char* Citizen::getName() { return this->name; }

char* Citizen::getName() const { return this->name; }

bool Citizen::setIsPartyMember() {
    this->isPartyMember = true;
    return true;
}

bool Citizen::setIsAlreadyVote() {
    this->isAlreadyVote = true;
    return true;
}

bool Citizen::getIsPartyMember() const { return this->isPartyMember;}

bool Citizen::getIsAlreadyVote() const { return this->isAlreadyVote;}

Citizen& Citizen::operator=(const Citizen& other){
    this->name = getString(other.name);
    this->id = getString(other.id);
    this->birthYear = other.birthYear;
    *(this->district) = *(other.district);
    this->isPartyMember = other.isPartyMember;
    this->isAlreadyVote = other.isAlreadyVote;
    return *this;
}

char* Citizen::getID() const { return this->id; }

District* Citizen::getDistrict(){ return this->district;}

District* Citizen::getDistrict() const{ return this->district; }

ostream& operator<<(ostream& os, const Citizen& citizen)
{
    os << "Citizen name: " << citizen.getName() << ", District: " << citizen.getDistrict()->getName() << ", Citizen ID: " << citizen.getID();
    return os;
}

void Citizen::save(ostream& out) const
{
    int nameLen = strlen(this->name);
    out.write(rcastcc(&nameLen), sizeof(nameLen));
    out.write(rcastcc(&this->name), sizeof(char) * nameLen);

    int idLen = strlen(this->id);
    out.write(rcastcc(&idLen), sizeof(idLen));
    out.write(rcastcc(this->name), sizeof(char) * idLen);

    this->district->save(out);

    out.write(rcastcc(&this->birthYear), sizeof(this->birthYear));
    out.write(rcastcc(&this->isPartyMember), sizeof(this->isPartyMember));
    out.write(rcastcc(&this->isAlreadyVote), sizeof(this->isAlreadyVote));

}