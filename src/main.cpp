#include <iostream>    //  Provides input and output stream operations (cin, cout)

#include <fstream>     // Deals with file stream operations (ifstream for input, ofstream for output).

#include <vector>      // Implements dynamic array container (vector).

#include <cstring>	   // Provides functions for handling C-style strings.

#include <string>      // Includes the C++ string class and related functions.

#include <conio.h>     // Includes console input/output functions like getch.

#include <iomanip>     // Offers input/output manipulators, such as setw.

#include <algorithm>   // Contains algorithms for operations on ranges of elements, like find_if and remove_if.

#include <ctime>       // Includes functionality for working with time and date


#include "admin.h"
using namespace std;







// Main function
int main()
{
	// Create an admin object
	admin A;
	// Load student data from file
	A.loadFile("STUDENTS.txt");
	
	do{
		cout<<endl;
		// Display main menu
		system("pause");
		system("cls");
		system("COLOR 09");
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 1 TO LOGIN AS STUDENT     *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 2 TO LOGIN AS EXAM OFFICER ************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 3 TO LOGIN AS HOD         *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER ANY OTHER KEY TO EXIT     *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		string x=inputc(" ",1);
		char chk = x.at(0);
		system("cls");
		// Switch statement based on user choice
		switch(chk)
		{
			// Case 1: Student Login
			case '1':
				{
					system("COLOR 0E");
					A.stdntchk();
					break;
				}
			// Case 2: Exam Officer Login	
			case '2':
				{
				system("COLOR 0C");	
				string PASS=inputp("\nENTER PASSWORD(5 DIGITS) : ",5);
				if(PASS=="admin"){
					cout<<"\nPASSWORD ACCEPTED\n ";
					
					// Display admin menu
					A.adDisplay();
				}else{
					cout<<"\nWRONG CREDENTIALS RETURNING TO MAIN MENU\n";
				}
				break;
				}
			// Case 3: HOD Login	
			case'3':
				{
				system("COLOR 0B");
				string pas=inputp("\nENTER PASSWORD(3 DIGITS) : ",3);
				if(pas=="hod"){
					cout<<"\nPASSWORD ACCEPTED\n";
					// Display HOD menu
					A.hod();
				}else{
					cout<<"\nWRONG CREDENTIALS RETURNING TO MAIN MENU\n";
				}
				break;
				}
			// Default case: Exit the program
			default:
				exit(EXIT_FAILURE);	
		}
	}while(1);
	return 0;
}
