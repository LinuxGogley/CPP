#include <iostream>
#include <math.h>
using namespace std;

int A = 0;
int B = 0;
int C = 0;
int Result1 = 0;
int Result2 = 0;

void Quadratic ()
{ 	
	cout << "Integer A: ";
	cin >> A;
	
	cout << "Integer B: ";
	cin >> B;
	
	cout << "Integer C: ";
	cin >> C;
	
	if (A = 0)
	  then (cout << "Error." << endl;
	    return 0;);
	
	Result1 = (-B+(sqrt((B*B)- 4*A*C)))/(2*A);
	Result2 = (-B-(sqrt((B*B)- 4*A*C)))/(2*A);
	
	cout << "x1 = " << Result1 << endl;
	cout << "x2 = " << Result2 << endl;
}
int main()
{
	cout << "Enter your integers." << endl;
	
	Quadratic();
	
	return 0;
}