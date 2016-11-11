#include <iostream>
#include <cstring>
#include <cstdlib>
#include "myDate.h"
using namespace std;

/* 
 Liam Gogley
 2016-10-13
*/

// Student structure
struct Student
{
    char name[30];
    char grade;
    string hometown;
    myDate BDay;
    int ID;
};

// Generate Functions
int genID();
char genGrade();
myDate genBday();

// Sort Functions
void swap(Student **x, Student **y);
void sortbyID(Student *A[]);
void sortbyName(Student *A[]);
void sortbyGrade(Student *A[]);
void sortbyBday(Student *A[]);
void sortbyHTown(Student *A[]);

// Additional Functions
void printStudentPtr(Student *A[], int size);
void printClass(Student A[], int size);

int main()
{
	Student MC[10];
	Student *cptr[10];
	Student *gptr[10];
	Student *hptr[10];
	Student *nptr[10];
	Student *bdptr[10];
    
	int choice, size=10;
	bool run=false;
	int def=0;

	const char ripley[30]="Ellen Ripley\0";
	const char rambo[30]="John Rambo\0";
	const char ash[30]="Ash Williams\0";
	const char luke[30]="Luke Skywalker\0";
	const char rocky[30]="Rocky Balboa\0";
	const char devito[30]="Danny DeVito\0";
	const char linus[30]="Linus Torvalds\0";
	const char frodo[30]="Frodo Baggins\0";
	const char tesla[30]="Nikola Tesla\0";
	const char bruce[30]="Bruce Lee\0";

	string hmtwn[10]={"Nostromo","Bowie","SMart","Tatooine","Philly","New Jersey","Helsinki","Bag End","Serbia","Hong Kong"};

	strcpy(MC[0].name,ripley);
	strcpy(MC[1].name,rambo);
	strcpy(MC[2].name,ash);
	strcpy(MC[3].name,luke);
	strcpy(MC[4].name,rocky);
	strcpy(MC[5].name,devito);
	strcpy(MC[6].name,linus);
	strcpy(MC[7].name,frodo);
	strcpy(MC[8].name,tesla);
	strcpy(MC[9].name,bruce);
	
	Student *ptr[10];
	for (int i=0; i<10; i++)
	{
		ptr[i]=nptr[i];
	}

	Student *A[10];
	myDate BD;

	for (int i=0; i<10; i++)
	{
		MC[i].grade=genGrade();
		BD=genBday();
		MC[i].BDay=BD;
		MC[i].ID=genID();
		MC[i].hometown=hmtwn[i];

		gptr[i] = &MC[i];
		bdptr[i] = &MC[i];
		nptr[i] = &MC[i];
		hptr[i] = &MC[i];
		cptr[i] = &MC[i];
		A[i] = &MC[i];
	}

	

	do{
    	run=false;

    	cout << "1 for unsorted, 2 for ID sort," << endl;
    	cout << "3 for name sort, 4 for birthday sort," << endl;
    	cout << "5 for grade sort, 6 for home town sort, and 7 to exit: " << endl;
    	cin >> choice;

    	if (choice==1) {run=true; def=1;} // Unsorted
    	else if (choice==2) {run=true; sortbyID(A); def=2;} // ID
    	else if (choice==3) {run=true; sortbyName(A); def=3;} // Name
    	else if (choice==4) {run=true; sortbyBday(A); def=4;} // Bday
    	else if (choice==5) {run=true; sortbyGrade(A); def=5;} // Grade
    	else if (choice==6) {run=true; sortbyHTown(A); def=6;} // Home town
    	else {cout << "Try again." << endl; run=false; def=0;}

    	if (run==true){
    		// Prints out header
    		cout << "Student ID" << "\t";
		cout <<	"Name" << "\t\t";
		cout <<	"Birthday" << "\t\t";
		cout <<	"Grade" << "\t";
		cout << "Home Town" << endl;
		if (def==2) printStudentPtr(A,size);	
		else if (def==3) printStudentPtr(A,size);		
		else if (def==4) printStudentPtr(A,size);		
		else if (def==5) printStudentPtr(A,size);		
		else if (def==6) printStudentPtr(A,size);			
		else printClass(MC,size);
	}
	}while (choice!=7);

    return 0;
}


void printStudentPtr(Student *A[], int size){
    for(int i = 0; i < size; i++)
    {
        cout << A[i]->ID << "\t\t" ;
	cout << A[i]->name << "\t";
        A[i]->BDay.display(); cout << "\t";
        cout << A[i]->grade << "\t";
	cout << A[i]->hometown << endl;
    }
}

void printClass(Student A[], int size){
    for(int i = 0; i < size; i++)
    {
        cout << A[i].ID << "\t\t";
	cout << A[i].name << "\t";
        A[i].BDay.display(); cout << "\t";
        cout << A[i].grade << "\t";
	cout << A[i].hometown << endl;
    }
}

void swap(Student **x, Student **y)
{
    Student *temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void sortbyID(Student *A[])
{
	//int adjust=sizeof(IDptr)/sizeof(IDptr[0]);
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<9; j++)
		{
			if(A[j]->ID > A[j+1]->ID) swap(A[j], A[j+1]);
		}
	}
}

void sortbyName(Student *A[])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<9; j++)
		{
			if ((strcmp(A[j]->name, A[j+1]->name) > 0)) swap(A[j], A[j+1]);
		}	
	}
}

void sortbyGrade(Student *A[])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<9; j++)
		{
			if(A[j]->grade > A[j+1]->grade) swap(A[j], A[j+1]);
		}
	}
}

void sortbyBday(Student *A[])
{
	myDate D1;
	myDate D2;
	int comp;
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<9; j++)
		{
			D1=A[j]->BDay; D2=A[j+1]->BDay;
			comp=D1.daysBetween(D2);
			if(comp<0) swap(A[j], A[j+1]);
		}	
	}
}

void sortbyHTown(Student *A[])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<9; j++)
		{
			if(A[j]->hometown.compare(A[j+1]->hometown) > 0) swap(A[j], A[j+1]);
		}
	}
}

char genGrade()
{
    int whichG = rand()%5;
    char grd;

    if (whichG==0) grd='A';
    else if (whichG==1) grd='B';
    else if (whichG==2) grd='C';
    else if (whichG==3) grd='D';
    else grd='F';

    return grd;
}

int genID()
{
    int assign;
    assign = rand()%8999;
    assign+=1000;
    return assign;
}

myDate genBday()
{
    int assign;
    assign = (rand()%1095); // Days between value

    myDate BD;
    BD.incrDate(assign);
    return BD;
}
