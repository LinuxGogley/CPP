#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card::Card()
{
	suit='Z';
	rank=99;
}

Card::Card(char s, int r)
{
	suit=s;
	rank=r;
}

void Card::setCard(char s, int r)
{
        suit=s;
	rank=r;
}

void Card::cardPicked()
{
        string name1, name2;
        
	if (suit=='C')
	{
		name2="Clubs";
	}

	else if (suit=='D')
	{
		name2="Diamonds";
	}

	else if (suit=='S')
	{
		name2="Spades";
	}

	else if (suit=='H')
	{
		name2="Hearts";
	}

	if (rank==1)
	{
		name1="Ace";
	}

	else if (rank>1 && rank<11)
	{
                int temp = rank;
		name1 = to_string(temp);
	}

	else if (rank==11)
	{
		name1="Jack";
	}

	else if (rank==12)
	{
		name1="Queen";
	}

	else if (rank==13)
	{
		name1="King";
	}

	cout << name1 << " of " << name2 << endl;
        cout << endl;
}

int Card::getValue()
{
        return rank;
}

void Card::display()
{
	string edge=" ---------";
	// card value display top and bottom
	string v1, v2, 
	// card face display sections
               f1, f2, f3, f4, f5;

	// D = Diamond
	if (suit=='D')
	{
		f1="|    *    |";
		f2="|   ***   |";
		f3="|  *****  |";
		f4="|   ***   |";
		f5="|    *    |";
	}

	else if (suit=='S')
	{
		f1="|    *    |";
		f2="|  *****  |";
		f3="|****+****|";
		f4="| ** | ** |";
		f5="|   ---   |";
	}

	else if (suit=='H')
	{
		f1="| **   ** |";
		f2="|**** ****|";
		f3="| ******* |";
		f4="|  *****  |";
		f5="|    *    |";
	}

	else if (suit=='C')
	{
		f1="|   .*.   |";
		f2="| . *** . |";
		f3="|.**.+.**.|";
		f4="| *  |  * |";
		f5="|   ---   |";
	}

	else
	{
		f1="| E |";
		f2="| R |";
		f3="| R |";
		f4="| O |";
		f5="| R |";
	}

	// 1 = Ace
	if (rank==1)
	{
		v1="|A        |";
		v2="|        A|";
	}

	else if (rank==2)
	{
		v1="|2        |";
		v2="|        2|";
	}

	else if (rank==3)
	{
		v1="|3        |";
		v2="|        3|";
	}

	else if (rank==4)
	{
		v1="|4        |";
		v2="|        4|";
	}

	else if (rank==5)
	{
		v1="|5        |";
		v2="|        5|";
	}

	else if (rank==6)
	{	
		v1="|6        |";
		v2="|        6|";
	}

	else if (rank==7)
	{
		v1="|7        |";
		v2="|        7|";
	}

	else if (rank==8)
	{
		v1="|8        |";
		v2="|        8|";
	}

	else if (rank==9)
	{
		v1="|9        |";
		v2="|        9|";
	}

	else if (rank==10)
	{
		v1="|10       |";
		v2="|       10|";
	}

	else if (rank==11)
	{
		v1="|J        |";
		v2="|        J|";
	}

	else if (rank==12)
	{
		v1="|Q        |";
		v2="|        Q|";
	}

	else if (rank==13)
	{
		v1="|K        |";
		v2="|        K|";
	}

	else
	{
		v1="| ! |";
		v2="| ! |";
	}

	cout << edge << endl;
	cout << v1 << endl;
	cout << f1 << endl;
	cout << f2 << endl;
	cout << f3 << endl;
	cout << f4 << endl;
	cout << f5 << endl;
	cout << v2 << endl;
	cout << edge << endl;
}	
