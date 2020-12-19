#include "CitizenList.h"

node* CitizenList::createNewNode(Citizen* citizen){
    node* newNode = new node();
    newNode->citizen = citizen;
    newNode->next = NULL;
    return newNode;
}

CitizenList::CitizenList() {
    this->head = NULL;
    this->tail = NULL;
}

CitizenList::~CitizenList()
{
    node* head = this->head;
    node* next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        delete head;
        head=next;
    }
}

void CitizenList::addNode(Citizen* citizen)
{
    node *newNode = this->createNewNode(citizen);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> next = newNode;
        tail = tail->next;
    }
}

void CitizenList::printFirstNRepresantives(const int n)
{
    int i;
    node* curr = this->head;
    for (i = 0; (i < n) && (curr != NULL); i++)
    {
        cout << "           " << *(curr->citizen) << endl;
        curr = curr->next;
    }
    if (i < n) cout << "            there aren't enough represantives" << endl;
}