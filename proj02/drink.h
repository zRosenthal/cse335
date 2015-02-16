#ifndef DRINK_H_
#define DRINK_H_
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;
#include<vector>
using std::vector;
//Drink header
class Drink
{
    protected:
        string name;
        int size;
    public:
        Drink(string, int);
        virtual ~Drink()=0;
        virtual string confirmOrder()=0;
        int getSize() {return size;}
        string getName() {return name;} 
};

class BubbleTea:public Drink
{
    private:
		bool hot; //true for hot, false for warm
        int size_bub;
    public:
        BubbleTea(string, int, bool, int);
        ~BubbleTea()=default;
        virtual string confirmOrder();
        BubbleTea & operator=(const BubbleTea &);
        BubbleTea(const BubbleTea &);     
};

class OrangeJuice:public Drink
{
    private:
        bool pulp;
    public:
        OrangeJuice(string, int, bool);
        ~OrangeJuice()=default;
        virtual string confirmOrder();
        OrangeJuice & operator=(const OrangeJuice &);
        OrangeJuice(const OrangeJuice &);
};

//OrderList header
class AbstractOrderList {
    private:
    protected:
        AbstractOrderList();
    public:
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


#endif
