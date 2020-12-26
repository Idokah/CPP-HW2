#pragma once
#include <iostream>
#include "Citizen.h"

using namespace std;

struct node
{
    Citizen* citizen;
    node *next;

    void save(ostream& out) const;
};

class CitizenList
{
    private:
        node *head,*tail;
        node* createNewNode(Citizen* citizen);
    public:
        CitizenList();
        ~CitizenList();
        void addNode(Citizen* citizen);
        void printFirstNRepresantives(const int n);

        void save(ostream& out) const;
        
        friend ostream& operator<<(ostream&, const CitizenList&);

};