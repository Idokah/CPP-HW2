#include "UnifiedDistrict.h"

UnifiedDistrict::UnifiedDistrict(char* name, int representativeNum) : District(name, representativeNum){}


void UnifiedDistrict::printType(std::ostream& os) const
{
	os << "District Type: Unified";
}

void UnifiedDistrict::printElectionResult(int partiesLogSize, Party** parties)
{
	Party* winningParty;
    char* headName;
    winningParty = parties[this->getWinningParty()-1];
    headName = winningParty->getPartyHead()->getName();
    cout << "--- the winning party head --- " << endl;
    cout << "    head of the winning party- " << headName << endl
        << "    vote percentage- " << this->getVotePercentage() << "%" << endl;
    winningParty->increaseNumberOfWinningRepresentives(this->getRepresentativeNum());
	District::printElectionResult(partiesLogSize, parties);
}
