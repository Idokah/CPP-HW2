#pragma once
#include "Citizen.h"
#include "CitizenList.h"
#include <iostream>
using namespace std;

class Party {
	public:
		Party();
		Party(char* name, Citizen* head);
		Party(const Party& other);
		~Party();
		int getID() const;
        void addRepresentive(const int districtId, Citizen* newRepresentive);
        void operator=(const Party& other);
        Citizen* getPartyHead();
        char* getName();
        char* getName() const;
		char* getPartyHeadName() const;
		void printNRepresantive(const int districtID,const int n); ////prints the first n represantives of the party in district - districtID
		int getNumberOfVotes();
		void increaseNumberOfVotes();
        void increaseNumberOfWinningRepresentives(const int n);
        int getNumberOfWinningRepresantives();

		friend ostream& operator<<(ostream&, const Party&);

    private:
		char* name;
		Citizen* partyHead;
		int id;
		CitizenList* representivesArr;
        int sizeRepresentivesArr;
		int generateID();
        void increaseArrSize(const int newSize);
		int numberOfVotes;
		int numberOfWinningRepresantives;
    };

