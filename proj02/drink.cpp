#include "drink.h"
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::ostream;
#include <string>
using std::string;
//Drink constructor, take a string and int
//intiailize name and size attributes
Drink::Drink(string n, int s) {
    name = n;
    size = s;
}
//retrurns corresponding string for each size
/*string Drink::getSize() {
    if (size==1) {return "small";}
    else if (size==2) {return "medium";}
    else {return "large";}
}*/
//OrangeJuice constructor takes a string, integer and a bool
//passes the string and integer to the Drink constructor
//intializes pulp attribute
OrangeJuice::OrangeJuice(string n, int s, bool p) : Drink( n, s)  {
    pulp = p;
}
//BubbleTea constructor takes a string, int, bool and another int
//passes the string and integer to the Drink constructor
//intializes hot and size_bub attributes
BubbleTea::BubbleTea(string n, int s, bool temp, int bs) : Drink(n, s)  {
        hot = temp;
        size_bub = bs;
}
//OrangeJuice confirmOrder virtual method
//prints out the order details
string OrangeJuice::confirmOrder() {
    string s = "";
    string str = "";
    if(size == 1) {s = "small";}
    else if(size == 2) {s = "medium";}
    else {s = "large";}

    str =  name + " ordered a " + s + " drink of orange juice with " 
         + ((pulp) ? "pulp\n": "no pulp\n");
    return str;
}

//BubbleTea confirmOrder virtual method
//prints out the order details
string BubbleTea::confirmOrder() {
    string s = "";
    if(size == 1) {s = "small";}
    else if(size == 2) {s = "medium";}
    else {s = "large";}
    string str = ""; 
    string b = "";
    if(size_bub == 1) {b = "small";}
    else if(size_bub == 2) {b = "medium";}
    else {b = "large";}
    str = name + " ordered a " + s + " drink of bubble tea with " 
         + b + " bubbles\n"; 
    return str;
}
//OrangeJuice: overloaded '='
//takes an OrangeJuice object and sets all attributes 
//of the lhs to the same as the rhs oj object
OrangeJuice & OrangeJuice::operator=(const OrangeJuice & rhs) {
    name = rhs.name;
    size = rhs.size;
    pulp = rhs.pulp;
    return *this;
}
//BubbleTea: overloaded '='
//takes an BubbleTea object and sets all attributes
//of the lhs to the same as the rhs BubbleTea object
BubbleTea & BubbleTea::operator=(const BubbleTea & rhs) {
    name = rhs.name;
    size = rhs.size;
    size_bub = rhs.size_bub;
    hot = rhs.hot;
    return *this;    
}
//OrangeJuice copy constructor copies OrangeJuice object
OrangeJuice::OrangeJuice(const OrangeJuice & oj) : Drink(oj.name, oj.size) {
    pulp = oj.pulp;
}
//BubbleTea copy constructor copies bubbletea object
BubbleTea::BubbleTea(const BubbleTea & bt) : Drink(bt.name, bt.size) {
    size_bub = bt.size_bub;
    hot = bt.hot;
}
/*empty implementation because c++ 11 requires all destructors (including pure
virtual destructors) to have an implementation (even if it is blank)*/
Drink::~Drink() {}

//AbstractOrderList constructor
AbstractOrderList::AbstractOrderList(){}

//getDrink function
//returns the ptr at index 'index' of OjVector
//Params: int - the index of ptr you want to be returned
OrangeJuice* OrangeJuiceOrderList::getDrink(int index) {
    return OjVector[index];
}

//OrangeJuiceOrderList constructor
//calls AbstractOrderList constructor
//intializes OjVector and size
//Params: vector of OrangeJuice pts
OrangeJuiceOrderList::OrangeJuiceOrderList(vector<OrangeJuice*> OjDrinks) : AbstractOrderList() {
    OjVector = OjDrinks;
    size = OjVector.size();
}

//getSize getter functions
//returns the size of the Orderlist
//Params: none
int OrangeJuiceOrderList::getSize() {return size;}

//getDrink function
//returns the ptr at index 'index' BtVector
//Params: int - the index of ptr you want to be returned
BubbleTea* BubbleTeaList::getDrink(int index) {
    return BtVector[index];
}

//getSize getter function
//returns the size of the OrderList
//Params: none
int BubbleTeaList::getSize() {return size;}

//BubbleTea constructor
//calls AbstractOrderList constructor
//intiailizes BtVector and size
//Params: vector of BubbleTea ptrs
BubbleTeaList::BubbleTeaList(vector<BubbleTea*> BtDrinks) : AbstractOrderList(){
    BtVector = BtDrinks;
    size = BtVector.size();
}

