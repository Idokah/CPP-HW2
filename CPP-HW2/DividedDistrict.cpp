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
        party = votersPerParty->size > i ? parties[votersPerParty[i].partyIndex] : parties[i];
        if (numOfRepresantive != 0)
        {
            cout << "    " <<  *(party->getPartyHead()) << endl;
            cout << "        Number of represantives: " << numOfRepresantive << endl;
            party->increaseNumberOfWinningRepresentives(numOfRepresantive);
        }
     }
    delete[] votersPerParty;
    District::printElectionResult(partiesLogSize, parties);
}

void DividedDistrict::save(ostream& out) const
{
    this->District::save(out);
    out.write(rcastcc(DISTRICT_TYPE::divided), sizeof(DISTRICT_TYPE::divided));
}

