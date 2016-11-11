#include <iostream>
#include "card.h"
#ifndef DECK_H
#define DECK_H

using namespace std;

class Deck
{
    private:
        int size;
        Card storage[51];
    
    public:
        Deck();
        void display();
        Card deal();
        void shuffle();
        int cards_left();
        void reinitialize();
};
#endif
