#pragma once
#include <iostream>
#include "Citizen.h"

using namespace std;

struct node
{
    Citizen* citizen;
    node *next;
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
};