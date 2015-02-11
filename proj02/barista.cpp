#include "barista.h"
#include<string>
#include<vector>
#include<iostream>

AbstractOrderList::AbstractOrderList(){}

OrangeJuiceOrderList::OrangeJuiceOrderList(vector<OrangeJuice*> OjDrinks){
    OjVector = OjDrinks;
}

BubbleTeaOrderList::BubbleTeaOrderList(vector<BubbleTea*> BtDrinks){
    BtVector = BtDrinks;
}
Barista::Barista() {
}
CoolBarista::CoolBarista() {
}
NewbieBarista::NewbieBarista() {
}

