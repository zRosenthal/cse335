#include "barista.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
//barsita constructor
Barista::Barista() {}

//output order helper function abstracted for use with coolbarista and newbie
//barista classes
//iterates through drinkvector pushing all the Drink pointers to a map where
//the key is either name or size depending on if cool or newbie is using it
//the value is a vector of all drinks pointers with the same name or size as 
//the key
//Once the map is built we iterate through the map, concatenating a string
//of the output from calling the outputOrder function on each Drink pointer
//contained within the vector contained in the value of of a key,value pair
//endOfStr is formed as the suffix to the string that will be outputed to the 
//console which includes the size/name (depending on cool or newbie barista)
//after iterating thorugh one key,value pair (all drinks assosiated with said
//key) we output the correct information to the user
//baristaType - cool = true , newbie = false
//Params: Const Refrence to a vector of drink pointers
//bool baristaType ^^
void Barista::outputOrder(const vector<Drink*> & drinkVector, bool baristaType) {
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

//CoolBarista constructor
CoolBarista::CoolBarista() : Barista() {}

//helper function called when sorting drink objects to determine ordering
//Params: 2 drink ptrs
bool sortOnName(Drink* drink1, Drink* drink2) {
    return drink1->getName() < drink2->getName();
}

//deliverDrinks fucntion 
//makes a vector of all drinks in the OrderList
//calls sort function and uses sortOnName to determine ordering
//calls outputOrder function passing the drinkVector in 
//passes true as second argument inorder for the outputOrder function 
//to process the correct output (name instead of size)
//Params: AbstractOrderList ptr
void CoolBarista::deliverDrinks(AbstractOrderList* abstractList) {
    vector<Drink*> drinkVector;
    for(int i = 0; i < abstractList->getSize(); i++) {
        drinkVector.push_back(abstractList->getDrink(i));
    }
    std::sort(drinkVector.begin(), drinkVector.end(), sortOnName);
    outputOrder(drinkVector,true);
}
//helper function called when sorting drink objects to determine ordering
//Params: 2 drink ptrs
bool sortOnSize(Drink* drink1, Drink* drink2) {
    return drink1->getSize() < drink2->getSize();
}
//NewbieBarista constructor
NewbieBarista::NewbieBarista() : Barista() {}

//deliverDrinks fucntion 
//makes a vector of all drinks in the OrderList
//calls sort function and uses sortOnName to determine ordering
//calls outputOrder function passing the drinkVector in 
//passes true as second argument inorder for the outputOrder function 
//to process the correct output (name instead of size)
//Params: AbstractOrderList
void NewbieBarista::deliverDrinks(AbstractOrderList * abstractList) {
    vector<Drink*> drinkVector;
    for(int i = 0; i < abstractList->getSize(); i++) {
        drinkVector.push_back(abstractList->getDrink(i));
    }
    std::sort(drinkVector.begin(), drinkVector.end(), sortOnSize);
    outputOrder(drinkVector,false);
}
