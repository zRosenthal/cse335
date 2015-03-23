#include "SearchVisitor.h"
SearchVisitor::SearchVisitor() {}
SearchVisitor::~SearchVisitor()=default;
void SearchVisitor::reset() {}
void SearchVisitor::setQuery(string q) {
	query = q;
}
void SearchVisitor::visitGroup(Group* groupPtr) {

}
void SearchVisitor::visitEmployee(Employee* empPtr) {
	
}
