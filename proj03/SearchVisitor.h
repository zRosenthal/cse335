#ifndef SVISIT
#define SVISIT
#include<string>
class SearchVisitor:public Visitor {
        public:
            void setQuery(string);
            SearchVisitor();
            ~SearchVisitor();
};
#endif
