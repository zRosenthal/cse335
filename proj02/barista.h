#ifndef BARISTA_H_
#define BARISTA_H_
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include "drink.h"
using namespace std;
class Barista {
    protected:
        void outputOrder(vector<Drink*>,bool);
    public:
        Barista();
        virtual ~Barista() {};
        virtual void deliverDrinks(AbstractOrderList *) = 0;

};
class CoolBarista:public Barista {
    public:
        CoolBarista();
        ~CoolBarista() = default;
        void deliverDrinks(AbstractOrderList *);
};
class NewbieBarista:public Barista {
    public:
        NewbieBarista();
        ~NewbieBarista() = default;
        void deliverDrinks(AbstractOrderList *);     
};
#endif
