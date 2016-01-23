#include <iostream>
#include <string>
using namespace std;

int main()
{
	int InputNumber;
	string InputName;
	
	cout << "Enter an integer: ";
	cin >> InputNumber;
	
	// same with string text i.e. string data
	cout << "Enter your name: ";
	cin >> InputName;
	
	/* places the input name and numer from program */
	cout << InputName << " entered " << InputNumber << endl;
	
	return 0;
}
	
