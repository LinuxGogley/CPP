#include <iostream>
#ifndef MYDATE_H
#define MYDATE_H
using namespace std;

class myDate
{
	private:
		int mon;
		int day;
		int yr;
		int JulDate;

	public:
		myDate();
		myDate(int M, int D, int Y);
		void display();
		void incrDate(int N);
		void decrDate(int N);
		int daysBetween(myDate D);
		int getMonth();
		int getDay();
		int getYear();
		int dayOfYear();
		string dayOfWeek();
		int JD(int &Y, int &M, int &D);
		void GDate(int JD, int &Y, int &M, int &D);

};
#endif
