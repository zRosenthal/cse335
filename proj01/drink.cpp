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

/*Drink::Drink(string & n,int & s) {
        name = n;
        size = s;
}
*/
//OrangeJuice confirmOrder virtual method
//prints out the order details
void OrangeJuice::confirmOrder() {
    string s = "";
    if(size == 1) {s = "small";}
    else if(size == 2) {s = "medium";}
    else {s = "large";}

    cout << name << " ordered a " << s << " drink of orange juice with " 
         << ((pulp) ? "pulp": "no pulp") << endl; 
}

//BubbleTea confirmOrder virtual method
//prints out the order details
void BubbleTea::confirmOrder() {
    string s = "";
    if(size == 1) {s = "small";}
    else if(size == 2) {s = "medium";}
    else {s = "large";}
    
    string b = "";
    if(size_bub == 1) {b = "small";}
    else if(size_bub == 2) {b = "medium";}
    else {b = "large";}
    cout << name << " ordered a " << s << " drink of bubble tea with " 
         << b << " bubbles" << endl; 
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

OrangeJuice::OrangeJuice(const OrangeJuice & oj) : Drink(oj.name, oj.size) {
    pulp = oj.pulp;
}
BubbleTea::BubbleTea(const BubbleTea & bt) : Drink(bt.name, bt.size) {
    size_bub = bt.size_bub;
    hot = bt.hot;
}
Drink::~Drink() {}
