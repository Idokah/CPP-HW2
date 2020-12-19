#include "Party.h"

char* getString(char* input);

Party::Party(){}

Party::Party(char* name, Citizen* head) : sizeRepresentivesArr(1), numberOfVotes(0),numberOfWinningRepresantives(0)
{
	this->name = getString(name);
	this->partyHead=head;
	this->id = this->generateID();
	this->representivesArr= new CitizenList[sizeRepresentivesArr];
}

Party::Party(const Party& other)
{
    *this = other;
}

void Party::operator=(const Party& other) {
    this->id = other.id;
    this->name = getString(other.name);
    this->sizeRepresentivesArr = other.sizeRepresentivesArr;
    this->partyHead = other.partyHead;
    this->representivesArr= new CitizenList[other.sizeRepresentivesArr];
    this->numberOfVotes = other.numberOfVotes;
    this->numberOfWinningRepresantives=other.numberOfWinningRepresantives;
    memcpy(this->representivesArr, other.representivesArr, sizeof(CitizenList) * other.sizeRepresentivesArr);
}

Party::~Party() {
   delete[] name;
   delete[] representivesArr;
}

Citizen* Party::getPartyHead(){ return this->partyHead; }

int Party::generateID()
{
	static int id = 0;
	return ++id;
}

int Party::getID() const { return this->id; }

void Party::addRepresentive(const int districtId, Citizen* newRepresentive)
{
    if (this->sizeRepresentivesArr < districtId ){
        this->increaseArrSize(districtId);

    }
	this->representivesArr[districtId-1].addNode(newRepresentive);
}

void Party::increaseArrSize(const int newSize) {
    CitizenList* newArr = new CitizenList[newSize * 2];
    for (int i = 0; i < this->sizeRepresentivesArr; i++)
    {
        newArr[i] = this->representivesArr[i];
    }
    this->sizeRepresentivesArr = newSize * 2;
    delete[] this->representivesArr;
    this->representivesArr = newArr;
}
char* Party::getName() { return this->name; }

char* Party::getName() const { return this->name; }

void Party::increaseNumberOfVotes() { this->numberOfVotes++; }

int Party::getNumberOfVotes() { return this->numberOfVotes; }

char* Party::getPartyHeadName() const { return this->partyHead->getName(); }

void Party::printNRepresantive(const int districtID,const int n)
{ 
    if (districtID >= sizeRepresentivesArr) {
        cout << "            there aren't enough represantives" << endl;
        return;
    }
    representivesArr[districtID].printFirstNRepresantives(n); 
}

void Party::increaseNumberOfWinningRepresentives(const int n) { this->numberOfWinningRepresantives+=n; }

int Party::getNumberOfWinningRepresantives(){ return this->numberOfWinningRepresantives; }

ostream& operator<<(ostream& os, const Party& party)
{
    os << "Party Name: " << party.getName() << ", head name : " << party.getPartyHeadName();
    return os;
}
