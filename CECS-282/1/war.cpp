#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
	char choice = 'y';
	int opt = 0;

        Deck myDeck;
	Card myCard;
        
        while (opt != 5)
        {
            	cout << "1) Get a new card deck" << endl;
            	cout << "2) Show all remaining cards" << endl;
            	cout << "3) Shuffle" << endl;
            	cout << "4) Play War" << endl;
            	cout << "5) Exit\n" << endl;

		cout << "Enter option: " << endl;
	    	cin >> opt;

		if (opt==1)
		{
			myDeck.reinitialize();
		}

		else if (opt==2)
		{
			myDeck.display();
		}

		else if (opt==3)
		{
			myDeck.shuffle();
		}

		else if (opt==4)
		{
			while (choice=='y')
			{
				cout << "One for you." << endl;
				
				myCard = myDeck.deal();
				myCard.display();
				
				int comp1 = myCard.getValue();
				myCard.cardPicked();

				cout << "One for me." << endl;
				
				myCard = myDeck.deal();
				myCard.display();

				int comp2 = myCard.getValue();
				myCard.cardPicked();

				if (comp1>comp2)
				{
					cout << "You win!\n" << endl;
				}

				else if (comp1<comp2)
				{
					cout << "You lose!\n" << endl;
				}

				else
				{
					cout << "Tie!\n" << endl;
				}
	
				cout << "You have " << myDeck.cards_left() << " cards left." << endl;

				cout << "Play again? [y/n]: " << endl;
				cin >> choice;
			}

		}

		else if (opt==5)
		{
			cout << "Goodbye!" << endl;
		}

		else
		{
			cout << "Error, try again" << endl;
		}
        
	}

	return 0;
}
