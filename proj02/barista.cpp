#include "barista.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
AbstractOrderList::AbstractOrderList(){}

OrangeJuiceOrderList::OrangeJuiceOrderList(vector<OrangeJuice*> OjDrinks){
    OjVector = OjDrinks;
}

vector<Drink*> OrangeJuiceOrderList::getVector() {
    return OjVector;
}
BubbleTeaList::BubbleTeaList(vector<BubbleTea*> BtDrinks){
    BtVector = BtDrinks;
}
vector<Drink*> BubbleTeaList::getVector() {
    return BtVector;
}
Barista::Barista() {}
//baristaType - cool = true , newbie = false
void Barista::outputOrder(vector<Drink*> drinkVector, bool baristaType) {
    for(auto vectorIterator = drinkVector.begin(); 
                    vectorIterator != drinkVector.end(); vectorIterator++) {
        int count = 0;
        string outputStr = "";
        string endOfStr = (baristaType) ? "for" + (*vectorIterator)->getName():
                "of size" + std::to_string((*vectorIterator)->getSize()); 
        do {
            outputStr += (*vectorIterator)->confirmOrder();
            count ++;
            vectorIterator++;
        }
        while((baristaType)?
            (*(vectorIterator-1))->getName()==(*vectorIterator)->getName():
            (*(vectorIterator-1))->getSize() == (*vectorIterator)->getSize());
        cout << "I have " << count << " drinks " << endOfStr << endl;
        vectorIterator--;
    }
}
CoolBarista::CoolBarista() {}
bool sortOnName(Drink* drink1, Drink* drink2) {
    return drink1->getName() < drink2->getName();
}
void CoolBarista::deliverDrinks(AbstractOrderList* abstractList) {
    vector<Drink*> drinkVector = abstractList->getVector();
    /*drink * drinkArray[drinkVector.size()];
    copy(drinkVector.begin(), drinkVector.end(), drinkArray);
    */
    std::sort(drinkVector.begin(), drinkVector.end(), sortOnName);
    outputOrder(drinkVector,true);
    /*for(auto vectorIterator drinkVector.begin(), 
        vectorIterator != drinkVector.end(), vectorIterator++) {
        vectorIterator->confirmOrder();
    }*/
}

bool sortOnSize(Drink* drink1, Drink* drink2) {
    return drink1->getSize() < drink2->getSize();
}

NewbieBarista::NewbieBarista() {}
void NewbieBarista::deliverDrinks(AbstractOrderList * abstractList) {
    vector<Drink*> drinkVector = abstractList->getVector();
    std::sort(drinkVector.begin(), drinkVector.end(), sortOnSize);
    outputOrder(drinkVector,false);
    /*    for(auto vectorIterator drinkVector.begin(), 
        vectorIterator != drinkVector.end(), vectorIterator++) {
        vectorIterator->confirmOrder();
    }
*/
}
