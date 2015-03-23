#include <iostream>
using namespace std;
class ABase {
    public:
        ABase() {}
        void printPublic() {
            cout << "Public" << endl;
        }
    protected:
        void printProtected() {
            cout << "Protected" << endl;
        }
    private:
        void printPrivate() {
            cout << "Private" << endl;
        }
};
class CDerived : private ABase {
    public:
        CDerived() {}
        void printC() {printProtected();}
};
int main() {
    CDerived cObj;
    cObj.printC();
}

