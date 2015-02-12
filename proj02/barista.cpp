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
//baristaType - cool = true , newbie = false
Barista::outputOrder(vector<drink*>* drinkVector, bool baristaType) {
    for(auto vectorIterator = drinkVector.begin(); 
                    vectorIterator != drinkVector.end(); vectorIterator++) {
        int count = 0;
        string outputString = "";
        endOfStr = (baristaType) ? "for" + vectorIterator->name:
                "of size" + vectorIterator->size; 
        while((baristaType)?(vectorIterator-1)->name==vectorIterator->name:
                        (vectorIterator-1)->size == vectorIterator->size) {
            outputStr += vectorIterator->confirmOrder;
            count ++;
            vectorIterator++;
        }
        do {
            outputStr += vectorIterator->confirmOrder;
            count ++;
            vectorIterator++;
        } 
        cout << "I have " << count << " drinks " << endOfStr << endl;
        vectorIterator--;
    }
}
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
    outputOrder(drinkVector,"Cool");
    /*for(auto vectorIterator drinkVector.begin(), 
        vectorIterator != drinkVector.end(), vectorIterator++) {
        vectorIterator->confirmOrder();
    }*/
}

bool NewbieBarista::sortOn(Drink* drink1, Drink* drink2) {
    return drink1->size < drink2->size;
}

NewbieBarista::NewbieBarista() {
    vector<drink*>* drinkVector = AbstractOrderList->getVector();
    std::sort(drinkVector.begin(), drinkVector.end(), sortOn);
    outputOrder(drinkVector,"Newbie");
    /*    for(auto vectorIterator drinkVector.begin(), 
        vectorIterator != drinkVector.end(), vectorIterator++) {
        vectorIterator->confirmOrder();
    }
*/
}
