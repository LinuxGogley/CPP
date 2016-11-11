#include <iostream>
#include <ctime>
#include "deck.h"
#include "card.h"

using namespace std;

Deck::Deck()
{
        size = 51;

        for (int i=0; i<=size; i++)
        {
		if (0<=i && i<=12)
		{
			int p=i+1;
			storage[i].setCard('D',p);
		}

		else if (12<i && i<=25)
		{
			int j=i-12;
			storage[i].setCard('S',j);
		}

		else if (25<i && i<=38)
		{
			int k=i-25;
			storage[i].setCard('H',k);
		}

		else if (38<i && i<=51)
		{
			int q=i-38;
			storage[i].setCard('C',q);
		}

	}

}

void Deck::display()
{
	for (int i=0; i<=size; i++)
	{
		storage[i].display();
	}
}

void Deck::shuffle()
{
	int a,b;
	int count = 0;

	srand(time(NULL));
	while (count<53)
	{
		a=rand()%52;
		b=rand()%52;
		Card c1;
		c1=storage[a];
		storage[a]=storage[b];
		storage[b]=c1;
		count++;
	}
}

Card Deck::deal()
{
	int top=size;
	size--;
	return storage[top];
}

int Deck::cards_left()
{
	return (size+1);
}

void Deck::reinitialize()
{
	size=51;
}
