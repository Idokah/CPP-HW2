#include <iostream>
#include "Citizen.h"
#include "UnifiedDistrict.h"
#include "DividedDistrict.h"
#include "ElectionRound.h"
#include "Party.h"

void addDistrict(ElectionRound& electionRound);
void addCitizen(ElectionRound& electionRound);
void addParty(ElectionRound& electionRound);
void setCitizenAsPartyRepresentive(ElectionRound& electionRound);
void printAllDistricts(ElectionRound& electionRound);
void printAllCitizens(ElectionRound& electionRound);
void printAllParties(ElectionRound& electionRound);
void vote(ElectionRound& electionRound);
void showElectionResults(ElectionRound& electionRound);


using namespace std;

const int MAX_STRING_LEN = 100;

int main()
{
    int option = 0;
    int day, month, year;
	cout << "enter elections date DD MM YYYY ";
	cin >> day >> month >> year;
    ElectionRound electionRound(day, month, year);


    while (option != 10) {
        cout << "enter one of the options-" << endl
             << "1 - add district" << endl
             << "2- add citizen" << endl
             << "3- add party" << endl
             << "4- add citizen as party representive" << endl
             << "5- show all districts" << endl
             << "6- show all citizens" << endl
             << "7- show all parties" << endl
             << "8- vote" << endl
             << "9- show election results" << endl
             << "10- exit the program" << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                addDistrict(electionRound);
                break;
            case 2:
                addCitizen(electionRound);
                break;
            case 3:
                addParty(electionRound);
                break;
            case 4:
                setCitizenAsPartyRepresentive(electionRound);
                break;
            case 5:
                printAllDistricts(electionRound);
                break;
            case 6:
                printAllCitizens(electionRound);
                break;
            case 7:
                printAllParties(electionRound);
                break;
            case 8:
                vote(electionRound);
                break;
            case 9:
                showElectionResults(electionRound);
                break;
            case 10:
                cout << "see you soon" << endl;
                break;
        }

    }
}



void addDistrict(ElectionRound &electionRound) {
    char name[MAX_STRING_LEN];
    int representativeNum; 
    bool districtType;
    District* district;
    cout << "enter name, number of representative and district type (0 for divided, 1 for unified)";
    cin >> name >> representativeNum >> districtType;
    if (districtType == 0) district = new UnifiedDistrict(name, representativeNum);
    else district = new DividedDistrict(name, representativeNum);
    electionRound.addDistrict(district);
}


void addCitizen(ElectionRound& electionRound) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    int birthYear, districtNum;
    cout << "enter name, id, birth year and district number ";
    cin >> name >> id >> birthYear >> districtNum;
    if (!electionRound.isValidDistrictId(electionRound.getDistrictLogSize(),districtNum) || electionRound.isCitizenIdIsAlreadyExist(id)) return;
    District* district = electionRound.getDistrictByID(districtNum);
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addParty(ElectionRound& electionRound) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    cout << "enter name and the party head's id ";
    cin >> name >> id;
    Citizen* head = electionRound.getCitizenByID(id);
    if (!electionRound.isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}



void setCitizenAsPartyRepresentive(ElectionRound& electionRound) {
    char representiveId[MAX_STRING_LEN];
    int partyId;
    int districtId;
    cout << "enter representive ID, party ID, district ID ";
    cin >> representiveId >> partyId >> districtId;
    Citizen *citizen = electionRound.getCitizenByID(representiveId);
    if (!electionRound.isValidCitizen("setCitizenAsPartyRepresentive", citizen)||!electionRound.isValidDistrictId(electionRound.getDistrictLogSize(), districtId)) return;
    citizen->setIsPartyMember();
    Party *party = electionRound.getPartyByID(partyId);
    if (!electionRound.isValidParty("setCitizenAsPartyRepresentive", party)) return;
    party->addRepresentive(districtId, citizen);
}


void printAllDistricts(ElectionRound& electionRound) {
    electionRound.printAllDistricts();
}

void printAllCitizens(ElectionRound& electionRound) {
    electionRound.printAllCitizens();
}

void printAllParties(ElectionRound& electionRound) {
    electionRound.printAllParties();
}


void vote(ElectionRound& electionRound){
    char citizenId[MAX_STRING_LEN];
    int partyId;
    cout << "enter citizen ID, party ID";
    cin >> citizenId >> partyId;
    Party* party = electionRound.getPartyByID(partyId);
    if (!electionRound.isValidParty("vote", party)) return;

    Citizen* voter = electionRound.getCitizenByID(citizenId);
    if (voter == NULL) { 
        cout << "there is no such citizen" << endl;
        return;
    };

    District* district=voter->getDistrict();
    district->addVote(voter, partyId);
    party->increaseNumberOfVotes();
}

void showElectionResults(ElectionRound& electionRound){
    District* district;
    Party* party, *winningParty;
    char* headName;
    int numOfExistsPartiesInDistrict, *numOfRepresantivesPerParty=nullptr, *electionResults;
    float *percentagePerParty=nullptr;
    for (int i = 0; i < electionRound.getDistrictLogSize(); ++i) {

        district = electionRound.getDistricts()[i];
        winningParty = electionRound.getPartyByID(district->getWinningParty());
        headName = winningParty->getPartyHead()->getName();
        cout << *district << endl
             << "    head of the winning party- " << headName << endl
             << "    vote percentage- "  << district->getVotePercentage() <<"%"<< endl;
        electionResults = district->getElectionResults();
        percentagePerParty = district->getPercentagePerParty();
        numOfRepresantivesPerParty = district->getNumOfRepresantivesPerParty(numOfExistsPartiesInDistrict);
        winningParty->increaseNumberOfWinningRepresentives(district->getRepresentativeNum());
        for (int j = 0; j < electionRound.getPartiesLogSize(); ++j) {
            cout <<"    "<< *(electionRound.getPartyByID(j+1))<< endl;
            if (j < numOfExistsPartiesInDistrict)
            {
                cout << "        number of voters -" << electionResults[j] << endl
                     << "        percentage of all votes - " << percentagePerParty[j] << "%" << endl;
                if (numOfRepresantivesPerParty[j] > 0) {
                    cout << "        represantives - " << endl;
                    party = electionRound.getPartyByID(j + 1);
                    party->printNRepresantive(i, numOfRepresantivesPerParty[j]);
                }
            }
            else {
                cout << "        number of voters" << " - 0" << endl
                     << "        percentage of all votes - 0%" << endl;
            }
        }
    }

    Party** parties = electionRound.getSortedParties();
    for (int i = 0; i < electionRound.getPartiesLogSize(); i++) {
        cout <<*parties[i]<<endl
             << "   winning number of represantives-  " << parties[i]->getNumberOfWinningRepresantives() << endl
             << "   total number of votes from all districts- "<< parties[i]->getNumberOfVotes() << endl;
    }

    delete[] percentagePerParty;
    delete[] numOfRepresantivesPerParty;
    delete[] parties;
}


