#include "District.h"
#include "Citizen.h"
#include <math.h>
#include <iostream>

using namespace std;

char* getString(char* input);

District::District() {}

District::District(char *name, int representativeNum):
        votersPercentage(0), electionResultsSize(1), voteCount(0), citizenNum(0) {
	this->name = getString(name);
	this->id = this-> generateID();
	this->representativeNum = representativeNum;
    this->electionResults =new int[electionResultsSize];
    for (int i = 0; i < this->electionResultsSize ; ++i) {
        this->electionResults[i]=0;
    }
}

int District::getID() { return this->id; }

char* District::getName() { return this->name; }
char* District::getName() const { return this->name; }

int District::getRepresentativeNum(){return this->representativeNum; }
int District::getRepresentativeNum() const { return this->representativeNum; }

int* District::getElectionResults(){ return this->electionResults; }

void District::printType(std::ostream& os) const
{
}

District::District(const District& other)
{
    *this = other;
}

void District::operator=(const District& other)
{
    this->voteCount=other.voteCount;
    this->name = getString(other.name);
    this->id = other.id;
    this->citizenNum=other.citizenNum;
    this->votersPercentage = other.votersPercentage;
    this->electionResults = new int[other.electionResultsSize];
    this->electionResultsSize=other.electionResultsSize;
    memcpy(this->electionResults, other.electionResults, sizeof(int) * other.electionResultsSize);
    this->representativeNum = other.representativeNum;
}

District::~District()
{
    delete[] name;
    delete[] this->electionResults;
}

int District::generateID()
{
	static int id = 0;
	return ++id;
}


void District::addVote(Citizen* voter, const int partyNum)
{
    if (! voter->getIsAlreadyVote()) {
        this->addToElectionResult(partyNum);
        voter->setIsAlreadyVote();
        this->voteCount ++;
        this->votersPercentage= (static_cast<float>(this->voteCount) / static_cast<float>(this->citizenNum)) * 100;
    } else {
        cout << "already voted!" << endl;
    }
}

void District::addToElectionResult(const int partyNum)
{
    if (this->electionResultsSize < partyNum ){
        this->increaseArrSize(this->electionResults,this->electionResultsSize, partyNum);

    }
    this->electionResults[partyNum-1]++;
}

void District::increaseArrSize(int*& arr, int &currSize, const int newSize) {
    int* newArr = new int[newSize];
    for (int i = 0; i < currSize; i++)
    {
        newArr[i] = arr[i];
    }
    for (int i = currSize; i<newSize; i++)
    {
        newArr[i]=0;
    }
    delete[] arr;
    currSize = newSize;
    arr = newArr;
}

void District::increaseCitizenNum()
{
    this->citizenNum++;
}

int District::getWinningParty(){
    int maxIndex = 0, max = 0;
    for (int i = 0; i < this->electionResultsSize; ++i) {
        if (this->electionResults[i] > max){
            max = this->electionResults[i];
            maxIndex = i;
        }
    }
    return (maxIndex + 1);
}

int *District::getNumOfRepresantivesPerParty(int& numOfExistsPartiesInDistrict){
    float *percentagePerParty = this->getPercentagePerParty();
    int *numOfRepresantivesPerParty = new int[electionResultsSize];
    for (int i = 0; i < this->electionResultsSize; ++i) {
        numOfRepresantivesPerParty[i] = round(percentagePerParty[i] * this->representativeNum / 100);
    }
    numOfExistsPartiesInDistrict = this->electionResultsSize;
    return numOfRepresantivesPerParty;
}


float* District::getPercentagePerParty()
{
    float *percentagePerParty = new float[electionResultsSize]; //// the index represent the (party ID - 1) and the value is the percentage.

    for (int i = 0; i < electionResultsSize; ++i)
    {
        percentagePerParty[i] = (this->voteCount == 0) ? 0 : (static_cast<float>(this->electionResults[i]) / static_cast<float>(this->voteCount)) * 100;
    }
    return percentagePerParty;
}

float District::getVotePercentage()
{
    return ((this->citizenNum==0)? 0 : static_cast<float>(this->voteCount) / static_cast<float>(this->citizenNum)) * 100;
}


ostream& operator<<(ostream& os, const District& district)
{
    os << "District Name: " << district.getName() << ", num of representative: " << district.getRepresentativeNum();
    district.printType(os);
    return os;
}
