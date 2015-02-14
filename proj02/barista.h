#ifndef BARISTA_H_
#define BARISTA_H_
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include "drink.h"
class AbstractOrderList {
    private:
    protected:
        AbstractOrderList();
    public:
        //virtual vector<Drink*> getVector()=0; 
        virtual Drink* getDrink(int)=0;         
        virtual int getSize()=0;
        virtual ~AbstractOrderList() {};
};
class OrangeJuiceOrderList:public AbstractOrderList {
    private:
        int size;
        vector<OrangeJuice*> OjVector;
    public:
        OrangeJuiceOrderList(vector<OrangeJuice*>);
        ~OrangeJuiceOrderList() = default;
        OrangeJuice* getDrink(int);
        int getSize();
};
class BubbleTeaList:public AbstractOrderList {
    private:
        int size;
        vector<BubbleTea*> BtVector;
    public:
        BubbleTeaList(vector<BubbleTea*>);
        ~BubbleTeaList() = default;
        BubbleTea* getDrink(int);
        int getSize();
};
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
