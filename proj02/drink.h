#ifndef DRINK_H_
#define DRINK_H_
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;

class Drink
{
    protected:
        std::string name;
        int size;
    public:
        Drink(string, int);
        virtual ~Drink()=0;
        virtual void confirmOrder()=0;

};

class BubbleTea:public Drink
{
    private:
		bool hot; //true for hot, false for warm
        int size_bub;
    public:
        BubbleTea(string, int, bool, int);
        ~BubbleTea()=default;
        virtual void confirmOrder();
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
        virtual void confirmOrder();
        OrangeJuice & operator=(const OrangeJuice &);
        OrangeJuice(const OrangeJuice &);
};

#endif
