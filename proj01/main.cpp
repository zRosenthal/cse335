#include <vector>
#include <iostream>
#include "drink.h"

int main(int argc, char** argv) {
    //creates a structure to hold the drink orders
    std::vector<Drink*> partyOrder;
    
    OrangeJuice CharzardOJ("Charzard", 3, true);
    OrangeJuice copyOj = OrangeJuice("NotCharzard", 2, false);
    //assign operator test
    copyOj=CharzardOJ;
    
    BubbleTea AmyBubbleTea(BubbleTea("Amy", 3, true, 1));
    //copy constructor test 
    BubbleTea copyBubbles = AmyBubbleTea;
    
    //adds drinks to the order 
    partyOrder.push_back(&AmyBubbleTea);
    partyOrder.push_back(&copyBubbles);
    partyOrder.push_back(&copyOj);
    partyOrder.push_back(&CharzardOJ);
    partyOrder.push_back(new BubbleTea("Tommy", 2, true, 3));
    partyOrder.push_back(new OrangeJuice("Tommy", 3, false));
    partyOrder.push_back(new OrangeJuice("Bob", 2, true));
    partyOrder.push_back(new BubbleTea("Billy", 3, true, 3));
    partyOrder.push_back(new OrangeJuice("Jake", 2, true));
    partyOrder.push_back(new BubbleTea("Lily", 1, true, 2));
    partyOrder.push_back(new OrangeJuice("Pikachu", 1, true));
    partyOrder.push_back(new BubbleTea("Ash", 1, true, 2));
    partyOrder.push_back(new BubbleTea("Cyborg", 2, true, 3));
    partyOrder.push_back(new BubbleTea("Anonymous Guy", 2, true, 1));

    //confirms each drink in the order
    for (unsigned int i=0; i<partyOrder.size(); i++) {
        partyOrder[i]->confirmOrder();
        std::cout << std::endl;
    }
    
    //cleans up memory 
    for (unsigned int i=4; i<partyOrder.size(); i++) {
        delete partyOrder[i];
    }
    partyOrder.clear(); 
    return 0;
}
