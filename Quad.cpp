// Liam Gogley

// 2014-09-30
// This program will help solve quadratic equations.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// Stores values of a, b, and c.
double a, b, c;
string again;

cout << "Input numbers to solve quadratic equation: "<< endl;
cout << "ax^2+bx+c=0" << endl;

do
{
cout << endl;

cout << "Enter a: ";
cin >> a;

cout << "Enter b: ";
cin >> b;

cout << "Enter c: ";
cin >> c;

cout << " " << endl;

// Defines parts of function.
double top = sqrt((b*b)-(4*a*c));
double bot = (2*a);

// Declares if imaginary number.
if (bot==0 || top<0)
cout << "Error, non real root(s)." << endl;

// Solves for root.
else
{cout << "Root 1: x=" << (0-(b)+top)/bot << endl;
cout << "Root 2: x=" << (0-(b)-top)/bot << endl;}

// Prompts if user wants to continue.
cout << "Solve again? [Y/n]: ";
cin >> again;

while ((again!="y") && (again!="Y") && (again!="n") && (again!="N"))
{
	cout << "Invalid option." << endl;
	cout << "[Y/n]: ";
	cin >> again;
}
}
while ((again=="y") && (again=="Y") || (again!="n") && (again!="N"));

cout << "Goodbye" << endl;

return 0;
}
