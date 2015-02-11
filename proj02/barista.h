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
        getVector();
}
class OrangeJuiceOrderList:public AbstractOrderList {
    private:
        vector<OrangeJuice*> OjVector;
    public:
        OrangeJuiceOrderList(vector<OrangeJuice*>);
}
class BubbleTeaList:public AbstractOrderList {
    private:
        vector<BubbleTea*> BtVector;
    public:
        BubbleTeaList(vector<BubbleTea*>);
}
class Barista {
    public:
        virtual deliverDrinks(AbstractOrderList *) = 0
}
class CoolBarista:public Barista {
    public:
        deliverDrinks(AbstractOrderList *);
}
class NewbieBarista:public Barista {
     public:
        deliverDrinks(AbstractOrderList *);
}

#endif
