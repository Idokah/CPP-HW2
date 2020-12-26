#pragma once
#include <iostream>
using namespace std;

#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>


class District;

class Citizen
{
    public:
		Citizen();
        Citizen(char* name, char* id, unsigned int birthYear, District* district);
		Citizen(const Citizen& other);
		~Citizen();
		char* getID() const;
		Citizen& operator=(const Citizen& other);
        District* getDistrict();
        District* getDistrict() const;
		char* getName();
		char* getName() const;
		bool setIsPartyMember();
		bool getIsPartyMember() const;
        bool setIsAlreadyVote();
        bool getIsAlreadyVote() const;

		friend ostream& operator<<(ostream&, const Citizen&);
		void save(ostream& out) const;
    private:
		char* name;
		char* id;
		int birthYear;
		District* district;
		bool isPartyMember; ////head or represantive
        bool isAlreadyVote;


};