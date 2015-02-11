#ifndef BARISTA_H_
#define BARISTA_H_
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;
#include<vector>
using std::vector;
class AbstractOrderList {
    private:
    protected:
        AbstractOrderList();
    public:
        virtual vector<Drink*>* getVector()=0;
}
class OrangeJuiceOrderList:public AbstractOrderList {
    private:
        vector<OrangeJuice*> OjVector;
    public:
        OrangeJuiceOrderList(vector<OrangeJuice*>);
        vector<OrangeJuice*>* getVector();
}
class BubbleTeaList:public AbstractOrderList {
    private:
        vector<BubbleTea*> BtVector;
    public:
        BubbleTeaList(vector<BubbleTea*>);
        vector<BubbleTea*>* getVector();
}
class Barista {
    public:
        Barista();
        virtual deliverDrinks(AbstractOrderList *) = 0

}
class CoolBarista:public Barista {
    Private:
       bool sortOn(Drink*, Drink*);
    public:
        CoolBarista();
        deliverDrinks(AbstractOrderList *);
}
class NewbieBarista:public Barista {
   Private:
        bool sortOn(Drink*, Drink*);  
    public:
        NewbieBarista();
        deliverDrinks(AbstractOrderList *);
       
}

#endif
