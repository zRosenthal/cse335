#include "barista.h"
#include<string>
#include<vector>
#include<iostream>

AbstractOrderList::AbstractOrderList(){}

OrangeJuiceOrderList::OrangeJuiceOrderList(vector<OrangeJuice*> OjDrinks){
    OjVector = OjDrinks;
}

vector<OrangeJuice*>* OrangeJuiceOrderList::getVector() {
    return &OjVector;
}
BubbleTeaOrderList::BubbleTeaOrderList(vector<BubbleTea*> BtDrinks){
    BtVector = BtDrinks;
}
vector<BubbleTea*>* BubbleTeaOrderList::getVector() {
    return &BtVector;
}
Barista::Barista() {}
CoolBarista::CoolBarista() {}
CoolBarista::sortOn(Drink* drink1, Drink* drink2) {
    return drink1->name < drink2->name;
}
CoolBarista::deliverDrinks(AbstractOrderList*) {
    vector<drink*> drinkVector = AbstractOrderList->getVector();
    /*drink * drinkArray[drinkVector.size()];
    copy(drinkVector.begin(), drinkVector.end(), drinkArray);
    */
    std::sort(drinkVector.begin(), drinkVector.end(), sortOn);
    for(auto vectorIterator drinkVector.begin(), 
        vectorIterator != drinkVector.end(), vectorIterator++) {
        vectorIterator->confirmOrder();
    }
}

bool NewbieBarista::sortOn(Drink* drink1, Drink* drink2) {
    return drink1->size < drink2->size;
}

NewbieBarista::NewbieBarista() {
    vector<drink*> drinkVector = AbstractOrderList->getVector();
    std::sort(drinkVector.begin(), drinkVector.end(), sortOn);
    for(auto vectorIterator drinkVector.begin(), 
        vectorIterator != drinkVector.end(), vectorIterator++) {
        vectorIterator->confirmOrder();
    }
}
