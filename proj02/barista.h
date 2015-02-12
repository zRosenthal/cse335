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
        virtual vector<Drink*> getVector()=0; 
};
class OrangeJuiceOrderList:public AbstractOrderList {
    private:
        vector<OrangeJuice*> OjVector;
    public:
        OrangeJuiceOrderList(vector<OrangeJuice*>);
        vector<Drink*> getVector();
};
class BubbleTeaList:public AbstractOrderList {
    private:
        vector<BubbleTea*> BtVector;
    public:
        BubbleTeaList(vector<BubbleTea*>);
        vector<Drink*> getVector();
};
class Barista {
    protected:
        void outputOrder(vector<Drink*>,bool);
    public:
        Barista();
        virtual void deliverDrinks(AbstractOrderList *) = 0;

};
class CoolBarista:public Barista {
    private:
     //  bool sortOn(Drink*, Drink*);
    public:
        CoolBarista();
        void deliverDrinks(AbstractOrderList *);
};
class NewbieBarista:public Barista {
    private:
    //    bool sortOn(Drink*, Drink*);  
    public:
        NewbieBarista();
        void deliverDrinks(AbstractOrderList *);     
};
#endif
