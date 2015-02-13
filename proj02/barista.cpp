#include "barista.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
AbstractOrderList::AbstractOrderList(){}
AbstractOrderList::~AbstractOrderList() {}
OrangeJuice* OrangeJuiceOrderList::getDrink(int index) {
    return OjVector[index];
}

OrangeJuiceOrderList::OrangeJuiceOrderList(vector<OrangeJuice*> OjDrinks){
    OjVector = OjDrinks;
    size = OjVector.size();
}

OrangeJuiceOrderList::~OrangeJuiceOrderList() {
    for(int i = 0; i < size; i++) {
        delete OjVector[i];
    }
}

int OrangeJuiceOrderList::getSize() {return size;}

BubbleTea* BubbleTeaList::getDrink(int index) {
    return BtVector[index];
}

int BubbleTeaList::getSize() {return size;}

BubbleTeaList::BubbleTeaList(vector<BubbleTea*> BtDrinks){
    BtVector = BtDrinks;
    size = BtVector.size();
}

BubbleTeaList::~BubbleTeaList() {
    for(int i = 0; i < size; i++) {
        delete BtVector[i];
    }
}

Barista::Barista() {}
Barista::~Barista() {}

//baristaType - cool = true , newbie = false
void Barista::outputOrder(vector<Drink*> drinkVector, bool baristaType) {
    map<string,vector<Drink*>> drinkMap; 
    for(auto vectorIterator = drinkVector.begin(); 
                    vectorIterator != drinkVector.end(); vectorIterator++) {

        drinkMap[(!baristaType) ? to_string((*vectorIterator)->getSize()) : 
                (*vectorIterator)->getName()].push_back(*vectorIterator);
}
    for(auto mapIterator = drinkMap.begin(); mapIterator!= drinkMap.end();
                    mapIterator++) {
        int count = 0;
        string outputStr = "";
        string endOfStr = (baristaType) ? "for ": "of size ";
        endOfStr += mapIterator->first;
        for(auto vecIterator = (mapIterator->second).begin(); 
            vecIterator!=(mapIterator->second).end(); vecIterator++ ) {
            outputStr += (*vecIterator)->confirmOrder(); 
            count++;
        }
    
       cout << "I have " << count << " drinks " << endOfStr << endl;
       cout << outputStr << endl;
    } }

CoolBarista::CoolBarista() {}

bool sortOnName(Drink* drink1, Drink* drink2) {
    return drink1->getName() < drink2->getName();
}
void CoolBarista::deliverDrinks(AbstractOrderList* abstractList) {
    cout << "in cool" << endl;
    vector<Drink*> drinkVector;
    for(int i = 0; i < abstractList->getSize(); i++) {
        drinkVector.push_back(abstractList->getDrink(i));
    }
    std::sort(drinkVector.begin(), drinkVector.end(), sortOnName);
    cout << "after drink vector is created" << endl;
    for(int i = 0; i < drinkVector.size(); i++) {
        cout << drinkVector[i]->confirmOrder() << ',';
    }
    cout << endl; 
    outputOrder(drinkVector,true);
}

bool sortOnSize(Drink* drink1, Drink* drink2) {
    return drink1->getSize() < drink2->getSize();
}

NewbieBarista::NewbieBarista() {}
void NewbieBarista::deliverDrinks(AbstractOrderList * abstractList) {
    vector<Drink*> drinkVector;
    for(int i = 0; i < abstractList->getSize(); i++) {
        drinkVector.push_back(abstractList->getDrink(i));
    }
    std::sort(drinkVector.begin(), drinkVector.end(), sortOnSize);
    outputOrder(drinkVector,false);
}
