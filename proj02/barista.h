#ifndef BARISTA_H_
#define BARISTA_H_
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;

class AbstractOrderList {
    private:
    protected:
        AbstractOrderList();
}
class OrangeJuiceOrderList:public AbstractOrderList {
    private:
    public:
        OrangeJuiceOrderList(vector<OrangeJuice*>);
}
class BubbleTeaList:public AbstractOrderList {
    private:
    public:
        BubbleTeaList(vector<BubbleTea*>);
}
class Barista {

}
class CoolBarista:public Barista {

}
class NewbieBarista:public Barista {

}

#endif
