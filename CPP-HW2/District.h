#pragma once
#include <iostream>
#include "Party.h"
#include "Enums.h"

using namespace std;

#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>

class Citizen;



struct votesPerParty
{
    int partyIndex;
    int numOfVotes;
    int size;
};

class District
{
	public:
		District();
		District(char* name, int representativeNum);
		District(const District& other);
		void operator=(const District& other);
		void increaseCitizenNum();
		~District();
        void addVote(Citizen* voter, const int partyNum);
        int getID();
        char* getName();
        char* getName() const;
        int getElectionResultsSize();
        int getRepresentativeNum();
        int getRepresentativeNum() const;
        int getWinningParty();
        int* getNumOfRepresantivesPerParty(int& numOfExistsPartiesInDistrict);
        float* getPercentagePerParty();
        float getVotePercentage();
        void mergeSort(votesPerParty* indexesArr, int size);
        void merge(votesPerParty* indexesArr1, votesPerParty* indexesArr2, int size1, int size2, votesPerParty* res);
        virtual void save(ostream& out) const;
        int* getElectionResults();
        friend ostream& operator<<(ostream&, const District&);
        virtual void printType(std::ostream& os) const;
        virtual void printElectionResult(int partiesLogSize, Party** parties);
        votesPerParty* getPartiesSortedByVotes(int* electionResult, int electionResultLogSize);
    private:


		char *name;
		int id;
		int citizenNum;
		float votersPercentage;
		int representativeNum;
		int generateID();
        int voteCount;
        //// ---- election results functionality ----
        int* electionResults;  // the index represent the (party ID - 1) and the value the number of citizens that vote for it.
        int electionResultsSize;
        void increaseArrSize(int*& arr,int &currSize, const int newSize);
        void addToElectionResult(const int partyNum);
};