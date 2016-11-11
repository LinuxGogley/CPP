#include <iostream>
#ifndef CARD_H
#define CARD_H

using namespace std;

class Card
{
    public:
        void display();
	Card();
        Card(char s, int r);
        int getValue();
        void cardPicked();
	void setCard(char s, int r);

    private:
        int rank;
        char suit;
}; 
#endif
