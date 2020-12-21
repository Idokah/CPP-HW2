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

void voteMOCK(ElectionRound& electionRound, char* citizenId, int partyId);
void addDistrictMOCK(ElectionRound& electionRound, char* name, int representativeNum, int type);
void addCitizenMOCK(ElectionRound& electionRound, char* name, char* id, int districtNum);
void addPartyMOCK(ElectionRound& electionRound, char* name, char* id);
void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, char* representiveId, int partyId, int districtId);

using namespace std;

const int MAX_STRING_LEN = 100;

int main()
{
    int option = 0;
    int day=1, month=1, year=1;
	//cout << "enter elections date DD MM YYYY ";
	//cin >> day >> month >> year;
    ElectionRound electionRound(day, month, year);
    addDistrictMOCK(electionRound, const_cast<char*>("A"), 4,1);
    addDistrictMOCK(electionRound, const_cast<char*>("B"), 10,1);
    addDistrictMOCK(electionRound, const_cast<char*>("C"), 2,0);

    addCitizenMOCK(electionRound, const_cast<char*>("A1"), const_cast<char*>("11"), 1);
    addCitizenMOCK(electionRound, const_cast<char*>("A2"), const_cast<char*>("12"), 1);
    addCitizenMOCK(electionRound, const_cast<char*>("A3"), const_cast<char*>("13"), 1);
    addCitizenMOCK(electionRound, const_cast<char*>("A4"), const_cast<char*>("14"), 1);
    addCitizenMOCK(electionRound, const_cast<char*>("A5"), const_cast<char*>("15"), 1);

    addCitizenMOCK(electionRound, const_cast<char*>("B1"), const_cast<char*>("21"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B2"), const_cast<char*>("22"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B3"), const_cast<char*>("23"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B4"), const_cast<char*>("24"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B5"), const_cast<char*>("25"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B6"), const_cast<char*>("26"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B7"), const_cast<char*>("27"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B8"), const_cast<char*>("28"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B9"), const_cast<char*>("29"), 2);
    addCitizenMOCK(electionRound, const_cast<char*>("B10"), const_cast<char*>("210"), 2);

    addCitizenMOCK(electionRound, const_cast<char*>("C1"), const_cast<char*>("31"), 3);
    addCitizenMOCK(electionRound, const_cast<char*>("C2"), const_cast<char*>("32"), 3);

    addPartyMOCK(electionRound, const_cast<char*>("one"), const_cast<char*>("12"));
    addPartyMOCK(electionRound, const_cast<char*>("two"), const_cast<char*>("21"));
    addPartyMOCK(electionRound, const_cast<char*>("three"), const_cast<char*>("22"));

    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("11"), 1, 1);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("14"), 1, 1);

    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("23"), 2, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("24"), 2, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("25"), 2, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("26"), 2, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("15"), 2, 1);

    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("31"), 3, 3);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("32"), 3, 3);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("27"), 3, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("28"), 3, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("29"), 3, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("210"), 3, 2);
    setCitizenAsPartyRepresentiveMOCK(electionRound, const_cast<char*>("13"), 3, 1);


    printAllDistricts(electionRound);
    printAllParties(electionRound);
    printAllCitizens(electionRound);


    voteMOCK(electionRound, const_cast<char*>("13"), 1);
    voteMOCK(electionRound, const_cast<char*>("14"), 1);
    voteMOCK(electionRound, const_cast<char*>("15"), 1);

    voteMOCK(electionRound, const_cast<char*>("23"), 2);
    voteMOCK(electionRound, const_cast<char*>("24"), 2);
    voteMOCK(electionRound, const_cast<char*>("25"), 2);
    voteMOCK(electionRound, const_cast<char*>("11"), 2);


    voteMOCK(electionRound, const_cast<char*>("31"), 3);
    voteMOCK(electionRound, const_cast<char*>("32"), 3);
    voteMOCK(electionRound, const_cast<char*>("26"), 3);
    voteMOCK(electionRound, const_cast<char*>("27"), 3);
    voteMOCK(electionRound, const_cast<char*>("28"), 3);
    voteMOCK(electionRound, const_cast<char*>("29"), 3);
    voteMOCK(electionRound, const_cast<char*>("210"), 3);


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




void voteMOCK(ElectionRound& electionRound, char* citizenId, int partyId) {
    Citizen* voter = electionRound.getCitizenByID(citizenId);
    District* district = voter->getDistrict();
    district->addVote(voter, partyId);
    Party* party = electionRound.getPartyByID(partyId);
    if (!electionRound.isValidParty("vote", party)) return;
    party->increaseNumberOfVotes();
}


void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, char* representiveId, int partyId, int districtId) {
    Citizen* citizen = electionRound.getCitizenByID(representiveId);
    if (!electionRound.isValidCitizen("setCitizenAsPartyRepresentive", citizen)) return;
    citizen->setIsPartyMember();
    Party* party = electionRound.getPartyByID(partyId);
    if (!electionRound.isValidParty("setCitizenAsPartyRepresentive", party)) return;
    party->addRepresentive(districtId, citizen);
}
void addDistrictMOCK(ElectionRound& electionRound, char* name, int representativeNum, int districtType) {
    District* district;
    if (districtType == 0) district = new UnifiedDistrict(name, representativeNum);
    else district = new DividedDistrict(name, representativeNum);
    electionRound.addDistrict(district);
}



void addCitizenMOCK(ElectionRound& electionRound, char* name, char* id, int districtNum) {
    int birthYear = 1992;
    District* district = electionRound.getDistrictByID(districtNum);
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addPartyMOCK(ElectionRound& electionRound, char* name, char* id) {

    Citizen* head = electionRound.getCitizenByID(id);
    if (!electionRound.isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}


void addDistrict(ElectionRound &electionRound) {
    char name[MAX_STRING_LEN];
    int representativeNum; 
    bool districtType;
    District* district;
    cout << "enter name, number of representative and district type (1 for divided, 0 for unified)";
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
        cout << "--------------" << *district << " -------------------" << endl;
        district->printElectionResult(electionRound.getPartiesLogSize(),electionRound.getPartiesArr());
    }
    cout << "-------------- Summary -------------------" << endl;
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


