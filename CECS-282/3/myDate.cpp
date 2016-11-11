// Liam Gogley	
// 2016-09-29
// CECS 282 TuTh 7:30pm

#include <iostream>
#include "myDate.h"
using namespace std;

myDate::myDate()
{
	JulDate=2448622;
}

myDate::myDate(int M, int D, int Y)
{
	mon=M;
	day=D;
	yr=Y;
}

void myDate::display()
{
	string sMon;
	int JD=JulDate;
	int Y, M, D;
	GDate(JD, Y, M, D);
	mon=M;
	day=D;
	yr=Y;
	
	bool c=false;

	if (mon==1)
	{
	    sMon="January";
	    c=true;
	}

	else if (mon==2)
	{
	    sMon="February";
	    c=true;
	}

	else if (mon==3)
	{
	    sMon="March";
	}

	else if (mon==4)
	{
	    sMon="April";
	}

	else if (mon==5)
	{
	    sMon="May";
	}

	else if (mon==6)
	{
	    sMon="June";
	    
	}

	else if (mon==7)
	{
	    sMon="July";
	}

	else if (mon==8)
	{
	    sMon="August";
	}

	else if (mon==9)
	{
	    sMon="September";
	}

	else if (mon==10)
	{
	    sMon="October";
	}

	else if (mon==11)
	{
	    sMon="November";
	    c=true;
	}

	else if (mon==12)
	{
	    sMon="December";
	}

	else
	{
	    mon=5;	
	    sMon="May";
	    day=11;
	    yr=1959;
	    JulDate=2448622;
	}

	if (c==true) cout << sMon << " " << day << ", " << yr;
	else cout << sMon << " " << day << ", " << yr << "    ";
}

void myDate::incrDate(int N)
{
	//int temp=JD(yr,mon,day);
	JulDate+=N;
	GDate(JulDate,yr,mon,day);
}

void myDate::decrDate(int N)
{
	int temp=JD(yr,mon,day);
	temp-=N;
	GDate(temp,yr,mon,day);
}

int myDate::daysBetween(myDate D)
{
	int comp = JD(yr,mon,day);

	int y1=D.getYear(),m1=D.getMonth(),d1=D.getDay();
	// get and set year, month, day from D
	
	int comp2 = JD(y1,m1,d1);
	
	return(comp2-comp);
}

int myDate::getMonth()
{
	return mon;
}

int myDate::getDay()
{
	return day;
}

int myDate::getYear()
{
	return yr;
}

int myDate::dayOfYear()
{
	int s1=1;
	int start=JD(yr,s1,s1);
	int current=JD(yr,mon,day);

	current-=start-1;   // set current from difference
			    // remove duplicate January 1st
	
	return current;
}

string myDate::dayOfWeek()
{
	string dow="Florida"; // Day of Week

	int index=JD(yr,mon,day);

	if (index%7==0)
	{
		dow="Monday";
	}

	else if (index%7==1)
	{
		dow="Tuesday";
	}
 
	else if (index%7==2)
	{
		dow="Wednesday";
	}

	else if (index%7==3)
	{
		dow="Thursday";
	}

	else if (index%7==4)
	{
		dow="Friday";
	}

	else if (index%7==5)
	{
		dow="Saturday";
	}

	else if (index%7==6)
	{
		dow="Sunday";
	}

	else
	{
		cout << "ERROR" << endl;
	}

	return dow;
}

int myDate::JD (int &Y, int &M, int &D)
{
	int I,J,K;
	
	I=Y;
	J=M;
	K=D;

	int JD=K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;

	return (JD);
}

void myDate::GDate(int JD, int &Y, int &M, int &D)
{
	int L, N, I, J, K;

	L=JD+68569;
	N=4*L/146097;
	L=L-(146097*N+3)/4;
	I=4000*(L+1)/1461001;
	L=L-1461*I/4+31;
	J=80*L/2447;
	K=L-2447*J/80;
	L=J/11;
	J=J+2-12*L;
	I=100*(N-49)+I+L;

	Y=I;
	M=J;
	D=K;
}
