#pragma once
#include <iostream>
#include "Citizen.h"
#include "District.h"
#include "Party.h"

class ElectionRound
{
	public:
		ElectionRound(const int day, const int month,const int year);
        ElectionRound(ElectionRound& electionRound) = delete;
        void operator=(const ElectionRound& other) = delete;
        ~ElectionRound();
		virtual void addDistrict(District* district);
		void addCitizen(Citizen* citizen);
		void addParty(Party* party);
		Citizen* getCitizenByID(const char* representiveID);
        Party* getPartyByID(int partyID);
        District* getDistrictByID(const int districtID);
        int getDistrictLogSize();
        int getPartiesLogSize();
        District** getDistricts();
		Party** getPartiesArr();
        virtual void printAllDistricts();
        void printAllCitizens();
        void printAllParties();
        Party** getSortedParties();
		bool isCitizenIdIsAlreadyExist(const char* citizenID);
		bool isValidCitizen(const char* action, Citizen* citizen);
		bool isValidParty(const char* action, Party* party);
		bool isValidDistrictId(const int districtsLogSize, const int districtId);
private:
		struct Date {
			const int year;
            const int month;
            const int day;
		};
		Date date;
		// voters
		Citizen** votersBook;
		int votersLogSize;
		int votersPhySize;
		void increaseVotersArrSize();

		// parties
		Party** parties;
		int partiesLogSize;
		int partiesPhySize;
		void increasePartiesArrSize();
		
        void mergeSort(Party** pointersArr, int size);
		void merge(Party** pointersArr1, Party** pointersArr2, int size1, int size2, Party** res);
protected:
	// districts
	int districtsLogSize;
	int districtsPhySize;
	District** districts;
	void increaseDistrictsArrSize();


};

