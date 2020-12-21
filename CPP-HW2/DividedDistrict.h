#pragma once
#include <iostream>
#include "District.h"
using namespace std;

struct votesPerParty
{
	int partyIndex;
	int numOfVotes;
};

class DividedDistrict : public District {
	public:
		DividedDistrict(char* name, int representativeNum);
		virtual void printType(std::ostream& os) const;
		virtual void printElectionResult(int partiesLogSize, Party** parties);
		votesPerParty* getPartiesSortedByVotes(int* electionResult, int electionResultLogSize);
	private:
		void mergeSort(votesPerParty* indexesArr, int size);
		void merge(votesPerParty* indexesArr1, votesPerParty* indexesArr2, int size1, int size2, votesPerParty* res);
};
