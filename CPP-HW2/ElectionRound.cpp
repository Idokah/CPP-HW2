#include "ElectionRound.h"
#include "District.h"

ElectionRound::ElectionRound(const int day, const int month, const int year) : date({ day, month, year }), districtsLogSize(0), districtsPhySize(1), votersLogSize(0), votersPhySize(1), partiesPhySize(1), partiesLogSize(0)
{
	this->parties = new Party*[partiesPhySize];
    this->districts = new District*[districtsPhySize];
    this->votersBook = new Citizen*[votersPhySize];
}

ElectionRound::~ElectionRound()
{
    for (int i = 0; i < this->votersLogSize; ++i) {
        delete this->votersBook[i];
    }
    delete[] this->votersBook;

    for (int i = 0; i < this->partiesLogSize; ++i) {
        delete this->parties[i];
    }
    delete[] this->parties;

    for (int i = 0; i < this->districtsLogSize; ++i) {
        delete this->districts[i];
    }
    delete[] this->districts;
}

District** ElectionRound::getDistricts(){ return this->districts; }

int ElectionRound::getDistrictLogSize(){ return this->districtsLogSize; }

int ElectionRound::getPartiesLogSize(){ return this->partiesLogSize; }

void ElectionRound::addDistrict(District* district)
{
	if (this->districtsLogSize == this->districtsPhySize)
	{
		this->increaseDistrictsArrSize();
	}
	this->districts[this->districtsLogSize++] = district;
}

void ElectionRound::increaseDistrictsArrSize() {
	this->districtsPhySize *= 2;
	District** newDistricts = new District*[districtsPhySize];
	for (int i = 0; i < districtsLogSize; i++)
	{
		newDistricts[i] = this->districts[i];
	}
    delete[] this->districts;
    this->districts = newDistricts;
}

void ElectionRound::addCitizen(Citizen* citizen)
{
	if (this->votersLogSize == this->votersPhySize)
	{
		this->increaseVotersArrSize();
	}
	this->votersBook[this->votersLogSize++] = citizen;
	citizen->getDistrict()->increaseCitizenNum();
}

void ElectionRound::increaseVotersArrSize() {
	this->votersPhySize *= 2;
	Citizen** newVotersBook = new Citizen*[votersPhySize];
	for (int i = 0; i < this->votersLogSize; i++)
	{
		newVotersBook[i] = this->votersBook[i];
	}
	delete[] this->votersBook;
	this->votersBook = newVotersBook;
}

void ElectionRound::addParty(Party* party)
{
	if (this->partiesLogSize == this->partiesPhySize)
	{
		this->increasePartiesArrSize();
	}
	this->parties[this->partiesLogSize++] = party;
}

void ElectionRound::increasePartiesArrSize() {
	this->partiesPhySize *= 2;
	Party** newParties = new Party*[partiesPhySize];
	for (int i = 0; i < this->partiesLogSize; i++)
	{
		newParties[i] = this->parties[i];
	}
    delete[] this->parties;
    this->parties = newParties;
}

Citizen* ElectionRound::getCitizenByID(const char* representiveID)
{
	for (int i = 0; i < votersLogSize; ++i)
	{
		if (strcmp(this->votersBook[i]->getID(), representiveID) == 0)
			return this->votersBook[i];
	}

	return nullptr;
}

Party* ElectionRound::getPartyByID(int partyId)
{
    for (int i = 0; i < this->partiesLogSize; ++i)
    {
        if (this->parties[i]->getID() == partyId)
            return this->parties[i];
    }

    return nullptr;
}

District* ElectionRound::getDistrictByID(const int districtID)
{
    for (int i = 0; i < this->districtsLogSize; ++i)
    {
        if (this->districts[i]->getID() == districtID)
            return this->districts[i];
    }

    return nullptr;
}

void ElectionRound::printAllDistricts()
{
    for (int i = 0; i < districtsLogSize; ++i) {
        cout<<*(districts[i])<<endl;
    }
}

void ElectionRound::printAllCitizens()
{
    for (int i = 0; i < votersLogSize; ++i) {
        cout<<*(votersBook[i])<<endl;
    }
}

void ElectionRound::printAllParties()
{
    for (int i = 0; i < partiesLogSize; ++i) {
        cout << *(parties[i])<<endl;
    }
}


Party** ElectionRound::getSortedParties()
{
    Party** partiesPointers = new Party*[this->partiesLogSize];
    for (int i = 0; i < this->partiesLogSize; ++i) {
        partiesPointers[i] = this->parties[i];
    }
    mergeSort(partiesPointers, this->partiesLogSize);
    return partiesPointers;
}

bool ElectionRound::isCitizenIdIsAlreadyExist(const char* citizenID)
{
    for (int i = 0; i < votersLogSize; i++)
    {
        if (strcmp(citizenID, votersBook[i]->getID()) == 0)
        {
            cout << "this ID is already exist." << endl;
            return true;
        }
            
    }
    return false;
}

void ElectionRound::mergeSort(Party** pointersArr, int size) {
    Party** temp;
    if (size <= 1) return;
    else {
        mergeSort(pointersArr, size/2);
        mergeSort(pointersArr + size/2, size - size/2);
        temp = new Party*[size];
        merge(pointersArr,pointersArr + size/2,size/2, size - size/2, temp);
        for (int i=0; i < size; i++){
            pointersArr[i] = temp[i];
        }

        delete[] temp;
    }
}



void ElectionRound::merge(Party** pointersArr1, Party** pointersArr2,int size1,int size2,Party** res)
{
    Party* currentValue1;
    Party* currentValue2;
    int i1=0,i2=0,iRes=0;
    while (i1<size1 && i2<size2)
    {
        currentValue1=*(pointersArr1+i1);
        currentValue2=*(pointersArr2+i2);
        if (currentValue1->getNumberOfWinningRepresantives() > currentValue2->getNumberOfWinningRepresantives())
        {
            res[iRes] = pointersArr1[i1];
            iRes++;
            i1++;
        }
        else
        {
            res[iRes] = pointersArr2[i2];
            iRes++;
            i2++;
        }
    }
    while (i1<size1)
    {
        res[iRes] = pointersArr1[i1];
        iRes++;
        i1++;
    }
    while (i2<size2)
    {
        res[iRes] = pointersArr2[i2];
        iRes++;
        i2++;
    }
}


// ------------------------ validation function -----------------------

bool ElectionRound::isValidCitizen(const char* action, Citizen* citizen) {
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

bool ElectionRound::isValidParty(const char* action, Party* party) {
    if (party == NULL) {
        cout << action << " -there is no such party." << endl;
        return false;
    }
    return true;
}

bool ElectionRound::isValidDistrictId(const int districtsLogSize, const int districtId)
{
    if (districtId > districtsLogSize)
    {
        cout << "There is no such District." << endl;
        return false;
    }
    return true;
}
