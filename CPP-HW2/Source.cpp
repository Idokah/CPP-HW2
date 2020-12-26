#include <iostream>
#include "Citizen.h"
#include "UnifiedDistrict.h"
#include "DividedDistrict.h"
#include "SimpleElectionRound.h"
#include "RegularElectionRound.h"
#include "Party.h"

enum class DISTRICT_TYPE {
    unified = 0,
    divided = 1
};

enum class ELECTION_ROUND_TYPE {
    regular = 0,
    simple = 1
};

void addDistrict(ElectionRound& electionRound);
void addCitizen(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType);
void addParty(ElectionRound& electionRound);
void setCitizenAsPartyRepresentive(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType);
void printAllDistricts(ElectionRound& electionRound);
void printAllCitizens(ElectionRound& electionRound);
void printAllParties(ElectionRound& electionRound);
void vote(ElectionRound& electionRound);
void showElectionResults(ElectionRound& electionRound);
bool isValidCitizen(const char* action, Citizen* citizen);
bool isValidParty(const char* action, Party* party);
bool isValidDistrictId(const int districtsLogSize, const int districtId);

void voteMOCK(ElectionRound& electionRound, char* citizenId, int partyId);
void addDistrictMOCK(ElectionRound& electionRound, char* name, int representativeNum, DISTRICT_TYPE type);
void addCitizenMOCK(ElectionRound& electionRound, char* name, char* id, int districtNum, ELECTION_ROUND_TYPE electionRoundType);
void addPartyMOCK(ElectionRound& electionRound, char* name, char* id);
void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, char* representiveId, int partyId, int districtId, ELECTION_ROUND_TYPE electionRoundType);

using namespace std;

enum class OPTIONS {
     addDistrict=1,
     addCitizen=2,
     addParty=3,
     addCitizenAsPartyRepresentive=4,
     showAllDistricts=5,
     showAllCitizens=6,
     showAllParties=7,
     vote=8,
     showElectionResults=9,
     exit=10
};



const int MAX_STRING_LEN = 100;

int main()
{
    OPTIONS option=OPTIONS::showElectionResults;
    int day = 1, month = 1, year = 1, electionRoundTypeNum = 0;
    ELECTION_ROUND_TYPE electionRoundType;
    int optionNum;
	//cout << "enter elections date DD MM YYYY ";
	//cin >> day >> month >> year;

    //cout << "enter elections round type (0 for regular, 1 for simple)";
    //cin >> electionRoundType;
    electionRoundType = (ELECTION_ROUND_TYPE)electionRoundTypeNum;



    ElectionRound* electionRound;
    if (electionRoundType == ELECTION_ROUND_TYPE::regular) electionRound = new RegularElectionRound(day, month, year);
    else electionRound = new SimpleElectionRound(day, month, year);


    addDistrictMOCK(*electionRound, const_cast<char*>("A"), 4,DISTRICT_TYPE::divided);
    addDistrictMOCK(*electionRound, const_cast<char*>("B"), 10, DISTRICT_TYPE::divided);
    addDistrictMOCK(*electionRound, const_cast<char*>("C"), 2, DISTRICT_TYPE::unified);

    addCitizenMOCK(*electionRound, const_cast<char*>("A1"), const_cast<char*>("11"), 1, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("A2"), const_cast<char*>("12"), 1, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("A3"), const_cast<char*>("13"), 1, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("A4"), const_cast<char*>("14"), 1, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("A5"), const_cast<char*>("15"), 1, electionRoundType);

    addCitizenMOCK(*electionRound, const_cast<char*>("B1"), const_cast<char*>("21"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B2"), const_cast<char*>("22"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B3"), const_cast<char*>("23"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B4"), const_cast<char*>("24"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B5"), const_cast<char*>("25"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B6"), const_cast<char*>("26"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B7"), const_cast<char*>("27"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B8"), const_cast<char*>("28"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B9"), const_cast<char*>("29"), 2, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("B10"), const_cast<char*>("210"), 2, electionRoundType);

    addCitizenMOCK(*electionRound, const_cast<char*>("C1"), const_cast<char*>("31"), 3, electionRoundType);
    addCitizenMOCK(*electionRound, const_cast<char*>("C2"), const_cast<char*>("32"), 3, electionRoundType);

    addPartyMOCK(*electionRound, const_cast<char*>("one"), const_cast<char*>("12"));
    addPartyMOCK(*electionRound, const_cast<char*>("two"), const_cast<char*>("21"));
    addPartyMOCK(*electionRound, const_cast<char*>("three"), const_cast<char*>("22"));

    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("11"), 2, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("14"), 1, 1, electionRoundType);

    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("23"), 2, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("24"), 2, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("25"), 2, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("26"), 2, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("15"), 2, 1, electionRoundType);

    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("31"), 3, 3, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("32"), 3, 3, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("27"), 3, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("28"), 3, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("29"), 3, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("210"), 3, 2, electionRoundType);
    setCitizenAsPartyRepresentiveMOCK(*electionRound, const_cast<char*>("13"), 3, 1, electionRoundType);


    printAllDistricts(*electionRound);
    printAllParties(*electionRound);
    printAllCitizens(*electionRound);


    voteMOCK(*electionRound, const_cast<char*>("13"), 2);
    voteMOCK(*electionRound, const_cast<char*>("14"), 1);
    voteMOCK(*electionRound, const_cast<char*>("15"), 1);

    voteMOCK(*electionRound, const_cast<char*>("23"), 2);
    voteMOCK(*electionRound, const_cast<char*>("24"), 2);
    voteMOCK(*electionRound, const_cast<char*>("25"), 2);
    voteMOCK(*electionRound, const_cast<char*>("11"), 2);


    voteMOCK(*electionRound, const_cast<char*>("31"), 3);
    voteMOCK(*electionRound, const_cast<char*>("32"), 3);
    voteMOCK(*electionRound, const_cast<char*>("26"), 3);
    voteMOCK(*electionRound, const_cast<char*>("27"), 3);
    voteMOCK(*electionRound, const_cast<char*>("28"), 3);
    voteMOCK(*electionRound, const_cast<char*>("29"), 3);
    voteMOCK(*electionRound, const_cast<char*>("210"), 3);


    while (option != OPTIONS::exit) {
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

        cin >> optionNum;
        option = (OPTIONS)optionNum;

        switch (option)
        {
            case OPTIONS::addDistrict :
                addDistrict(*electionRound);
                break;
            case OPTIONS::addCitizen:
                addCitizen(*electionRound, electionRoundType);
                break;
            case OPTIONS::addParty:
                addParty(*electionRound);
                break;
            case OPTIONS::addCitizenAsPartyRepresentive:
                setCitizenAsPartyRepresentive(*electionRound, electionRoundType);
                break;
            case OPTIONS::showAllDistricts:
                printAllDistricts(*electionRound);
                break;
            case OPTIONS::showAllCitizens:
                printAllCitizens(*electionRound);
                break;
            case OPTIONS::showAllParties:
                printAllParties(*electionRound);
                break;
            case OPTIONS::vote:
                vote(*electionRound);
                break;
            case OPTIONS::showElectionResults:
                showElectionResults(*electionRound);
                break;
            case OPTIONS::exit:
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
    if (!isValidParty("vote", party)) return;
    party->increaseNumberOfVotes();
}

void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, char* representiveId, int partyId, int districtId, ELECTION_ROUND_TYPE electionRoundType) {
    districtId = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtId : 1;
    Citizen* citizen = electionRound.getCitizenByID(representiveId);
    if (!isValidCitizen("setCitizenAsPartyRepresentive", citizen) || !isValidDistrictId(electionRound.getDistrictLogSize(), districtId)) return;
    citizen->setIsPartyMember();
    Party* party = electionRound.getPartyByID(partyId);
    if (!isValidParty("setCitizenAsPartyRepresentive", party)) return;
    party->addRepresentive(districtId, citizen);
}

void addDistrictMOCK(ElectionRound& electionRound, char* name, int representativeNum, DISTRICT_TYPE districtType) {
    District* district;
    if (districtType == DISTRICT_TYPE::unified) district = new UnifiedDistrict(name, representativeNum);
    else district = new DividedDistrict(name, representativeNum);
    electionRound.addDistrict(district);
}

void addCitizenMOCK(ElectionRound& electionRound, char* name, char* id, int districtNum, ELECTION_ROUND_TYPE electionRoundType) {
    int birthYear = 1992;
    if (electionRound.isCitizenIdIsAlreadyExist(id)) return;
    districtNum = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtNum : 1;
    District* district = electionRound.getDistrictByID(districtNum);
    if (electionRoundType == ELECTION_ROUND_TYPE::regular && !isValidDistrictId(electionRound.getDistrictLogSize(), districtNum)) return;
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addPartyMOCK(ElectionRound& electionRound, char* name, char* id) {

    Citizen* head = electionRound.getCitizenByID(id);
    if (!isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void addDistrict(ElectionRound &electionRound) {
    char name[MAX_STRING_LEN];
    int representativeNum; 
    int districtTypeNum;
    DISTRICT_TYPE districtType;
    District* district;
    cout << "enter name, number of representative and district type (1 for divided, 0 for unified)";
    cin >> name >> representativeNum >> districtTypeNum;
    districtType = (DISTRICT_TYPE)districtTypeNum;
    if (representativeNum <= 0) {
        cout << "Sorry a district have a positive number of represenative number" << endl;
        return;
    }
    if (districtType == DISTRICT_TYPE::unified) district = new UnifiedDistrict(name, representativeNum);
    else district = new DividedDistrict(name, representativeNum);
    electionRound.addDistrict(district);
}

void addCitizen(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    int birthYear, districtNum;
    cout << "enter name, id, birth year, district number";
    cin >> name >> id >> birthYear >> districtNum;
    districtNum = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtNum : 1;
    District* district = electionRound.getDistrictByID(districtNum);
    if (electionRound.isCitizenIdIsAlreadyExist(id) || !isValidDistrictId(electionRound.getDistrictLogSize(), districtNum)) return;
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addParty(ElectionRound& electionRound) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    cout << "enter name and the party head's id ";
    cin >> name >> id;
    Citizen* head = electionRound.getCitizenByID(id);
    if (!isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void setCitizenAsPartyRepresentive(ElectionRound& electionRound, ELECTION_ROUND_TYPE electionRoundType) {
    char representiveId[MAX_STRING_LEN];
    int partyId;
    int districtId;
    cout << "enter representive ID, party ID, district ID ";
    cin >> representiveId >> partyId >> districtId;
    districtId = (electionRoundType == ELECTION_ROUND_TYPE::regular) ? districtId : 1;
    Citizen *citizen = electionRound.getCitizenByID(representiveId);
    if (!isValidCitizen("setCitizenAsPartyRepresentive", citizen) || !isValidDistrictId(electionRound.getDistrictLogSize(), districtId)) return;
    citizen->setIsPartyMember();
    Party *party = electionRound.getPartyByID(partyId);
    if (!isValidParty("setCitizenAsPartyRepresentive", party)) return;
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
    if (!isValidParty("vote", party)) return;

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


// ------------------------ validation function -----------------------


bool isValidCitizen(const char* action, Citizen* citizen)  {
    if (citizen == NULL) {
        cout << action << " -there is no such citizen." << endl;
        return false;
    }
    if (citizen->getIsPartyMember()) {
        cout << action << " -already set as represantive or head." << endl;
        return false;
    }
    return true;
}

bool isValidParty(const char* action, Party* party)  {
    if (party == NULL) {
        cout << action << " -there is no such party." << endl;
        return false;
    }
    return true;
}

bool isValidDistrictId(const int districtsLogSize, const int districtId) 
{
    if (districtId > districtsLogSize)
    {
        cout << "There is no such District." << endl;
        return false;
    }
    return true;
}
