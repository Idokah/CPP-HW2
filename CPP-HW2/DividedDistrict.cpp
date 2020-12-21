#include "DividedDistrict.h"

DividedDistrict::DividedDistrict(char* name, int representativeNum) : District(name, representativeNum) {}

void DividedDistrict::printType(std::ostream& os) const
{
	os << "District Type: Divided";
}

void DividedDistrict::printElectionResult(int partiesLogSize, Party** parties)
{
    Party* party;
    int* reprsantivePerParty= this->getNumOfRepresantivesPerParty(partiesLogSize);
    int numOfParties= this->getElectionResultsSize();
    votesPerParty* votersPerParty = this->getPartiesSortedByVotes(this->getElectionResults(), numOfParties);
    cout << "--- all parties heads --- " << endl;
    for (int i = 0; i < numOfParties; i++)
    {
        int numOfRepresantive = reprsantivePerParty[votersPerParty[i].partyIndex];
        party = parties[votersPerParty[i].partyIndex];
        if (numOfRepresantive != 0){
            cout << "    " <<  *(party->getPartyHead()) << endl;
            cout << "        Number of represantives: " << numOfRepresantive << endl;
            party->increaseNumberOfWinningRepresentives(numOfRepresantive);
        }
     }
    delete[] votersPerParty;
    District::printElectionResult(partiesLogSize, parties);
}

votesPerParty* DividedDistrict::getPartiesSortedByVotes(int* electionResult, int electionResultLogSize)
{
    votesPerParty* electionResultIndexesArr = new votesPerParty[electionResultLogSize]; //TODO free this
    for (int i = 0; i < electionResultLogSize; i++)
    {
        electionResultIndexesArr[i] = { i,electionResult[i] };
    }
    mergeSort(electionResultIndexesArr, electionResultLogSize);
    return electionResultIndexesArr;
}



void DividedDistrict::mergeSort(votesPerParty* indexesArr, int size) {
    votesPerParty* temp;
    if (size <= 1) return;
    else {
        mergeSort(indexesArr, size / 2);
        mergeSort(indexesArr + size / 2, size - size / 2);
        temp = new votesPerParty[size];
        merge(indexesArr, indexesArr + size / 2, size / 2, size - size / 2, temp);
        for (int i = 0; i < size; i++) {
            indexesArr[i] = temp[i];
        }

        delete[] temp;
    }
}



void DividedDistrict::merge(votesPerParty* indexesArr1, votesPerParty* indexesArr2, int size1, int size2, votesPerParty* res)
{
    votesPerParty currentValue1;
    votesPerParty currentValue2;
    int i1 = 0, i2 = 0, iRes = 0;
    while (i1 < size1 && i2 < size2)
    {
        currentValue1 = *(indexesArr1 + i1);
        currentValue2 = *(indexesArr2 + i2);
        if (currentValue1.numOfVotes > currentValue2.numOfVotes)
        {
            res[iRes] = indexesArr1[i1];
            iRes++;
            i1++;
        }
        else
        {
            res[iRes] = indexesArr2[i2];
            iRes++;
            i2++;
        }
    }
    while (i1 < size1)
    {
        res[iRes] = indexesArr1[i1];
        iRes++;
        i1++;
    }
    while (i2 < size2)
    {
        res[iRes] = indexesArr2[i2];
        iRes++;
        i2++;
    }
}

