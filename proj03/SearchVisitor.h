#ifndef SVISIT
#define SVISIT
#include<string>
#include "PrintVisitor.h"
using namespace std;
class SearchVisitor:public Visitor {
        public:
            void setQuery(string);
            SearchVisitor();
            ~SearchVisitor();
};
#endif
