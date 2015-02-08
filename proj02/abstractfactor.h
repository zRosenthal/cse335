class AbstractOrderList {
    private:
    protected:
        AbstractOrderList();
}
Class OrangeJuiceOrderList:public AbstractOrderList {
    private:
    public:
        OrangeJuiceOrderList(vector<OrangeJuice*>);
}
Class BubbleTeaList:public AbstractOrderList {
    private:
    public:
        BubbleTeaList(vector<BubbleTea*>);
}
Class Barista {

}
Class CoolBarista:public Barista {

}
Class NewbieBarista:public Barista {

}

