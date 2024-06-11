#ifndef STUDENT_H
#define STUDENT_H

#include "input.h"

#include <iostream>    //  Provides input and output stream operations (cin, cout)

#include <fstream>     // Deals with file stream operations (ifstream for input, ofstream for output).

#include <vector>      // Implements dynamic array container (vector).

#include <cstring>	   // Provides functions for handling C-style strings.

#include <string>      // Includes the C++ string class and related functions.

#include <conio.h>     // Includes console input/output functions like getch.

#include <iomanip>     // Offers input/output manipulators, such as setw.

#include <algorithm>   // Contains algorithms for operations on ranges of elements, like find_if and remove_if.

#include <ctime>       // Includes functionality for working with time and date.

using namespace std;


// Class representing a student
class  student{
		string name,fatherName,rollNo,time,password;
		
		double gpa,oopt,oopp,fa,ps,cps,dldt,dldp;
		
			
	public:
		
		// Parameterized constructor to initialize a student
		student(string);


		// Function to display the student's information
		void layout();
		
		// Function to display student information with formatted output
		void display() const;
		
		// Function to display detailed information about a student
		void show() const;
		
		// Function to display only password and roll number
		void showpass() const;
		
		// Overloading << operator for output stream
		friend ostream& operator <<(ostream&,const student&);
		
		// Overloading >> operator for input stream
		friend istream& operator >>(istream&,student&);
		
		// Function to get marks for a specific subject
		double subjectMarks(string);
		
		// Default constructor
		student(){}
		
		// Destructor
		~student(){}
		
		// Getter function for Roll Number
		string RollNo() const
		{
			return rollNo;
		}
		string Name() const
		{
			return name;
		}
		
		double Gpa() const
		{
			return gpa;
		}
		// Getter function for Password
		string Pass() const
		{
			return password;
		}
		
		// Function to get current time
		string currentTime(){
			
			// Get the current time
			time_t now = std::time(0);
			
			// Convert the time to a string
			string x= string(ctime(&now));
			
			// Remove the trailing newline character if it exists
			if(x.back()=='\n'){
				x.pop_back();
			}
			
			// Return the formatted time string
			return x;
		}
};





// Member function to display student information
void student::display() const
{
	// Displaying the values of each field for the current student object
	cout<<setw(12)<<rollNo<<setw(22)<<name<<setw(22)<<fatherName<<setw(22)<<oopt<<setw(16)<<oopp<<setw(16);
	cout<<fa<<setw(16)<<ps<<setw(16)<<cps<<setw(16)<<dldt<<setw(16)<<dldp<<setw(16)<<gpa<<setw(16)<<gpa<<setw(30)<<time<<setw(16)<<"\n";
	return;
}




// Overloaded << operator for streaming student object to output stream
ostream& operator <<(ostream& os, const student& my)
{
	// Stream the values of each member variable to the output stream
    os << my.rollNo<< '\n' << my.name << '\n' << my.fatherName << '\n' << my.password << '\n'  
       << my.gpa << '\n' << my.oopt << '\n' << my.oopp << '\n' << my.fa << '\n' << my.ps << '\n' << my.cps << '\n' 
       << my.dldt << '\n' << my.dldp << '\n' << my.time << '\n';
    return os;		// Return the output stream for chaining
}




// Overloaded >> operator for reading student object from input stream
istream& operator >>(istream& is,student& my)
{
	// Read each member variable from the input stream
	getline(is, my.rollNo);			// Read roll number as a string
	getline(is, my.name);			// Read name as a string
	getline(is, my.fatherName);		// Read father's name as a string
	getline(is, my.password);		// Read password as a string
	is>>my.gpa;						// Read GPA as a double
	is>>my.oopt;					// Read OOP theory marks as a double
	is>>my.oopp;					// Read OOP practical marks as a double
	is>>my.fa;						// Read Financial Accounting marks as a double
	is>>my.ps;						// Read Probability & Statistics marks as a double
	is>>my.cps;						// Read Communication and Presentation Skills marks as a double
	is>>my.dldt;					// Read DLD theory marks as a double
	is>>my.dldp;					// Read DLD practical marks as a double
	is.ignore(123,'\n');			// Ignore extra characters up to the newline character
	getline(is, my.time);			// Read update time as a string
	return is;		// Return the input stream for chaining
}




// Display detailed information about the student and their subject marks
void student::show() const
{
	// Display the result updation time
	cout<<"\nRESULT UPDATION TIME IS : "<<time
		<<"\n\nROLL NUMBER : "<<rollNo      // Display the student's roll number
		<<"\nNAME        : "<<name          // Display the student's name
		<<"\nFATHER NAME : "<<fatherName    // Display the student's father's name
		<<"\n\n\tSUBECTS MARKS ARE \n"
		<<"\n\tCPS       : "<<cps           // Display marks for Communication and Presentation Skills
		<<"\n\tDLD(P)    : "<<dldp          // Display marks for Digital Logic Design (Practical)
		<<"\n\tDLD(T)    : "<<dldt          // Display marks for Digital Logic Design (Theory)
		<<"\n\tFA        : "<<fa            // Display marks for Financial Accounting
		<<"\n\tOOP(P)    : "<<oopp          // Display marks for Object-Oriented Programming (Practical)
		<<"\n\tOOP(T)    : "<<oopt          // Display marks for Object-Oriented Programming (Theory)
		<<"\n\tPS        : "<<ps            // Display marks for Probability & Statistics
		<<"\n\tTOTAL GPA : "<<gpa           // Display the total GPA
		<<endl;
	return;
}




// Display confidential information about the student (Roll number, Name, Password)
void student::showpass() const
{
	 // Display the actual values with proper formatting
	cout<<setw(30)<<rollNo           // Display the student's roll number
		<<setw(30)<<name    		 // Display the student's name
		<<setw(30)<<password<<endl;  // Display the student's password
		return;
}




// Calculate the total marks for a specific subject based on different components
double student::subjectMarks(string x)
{
	// Declare variables to store marks for assignment, quiz, OHT1, OHT2, and final exam
	double asgnNo,quizNo,oht1No,oht2No,FinalNo;
	
	// Display the name of the subject
	cout<<x<<endl;
	
	// Input and validate marks for assignment (out of 60)
	do{
		asgnNo=input("\nENTER ASSIGNMET MARKS(OUT OF 60) : ");
	}while(asgnNo < 0 || asgnNo > 60);
	
	// Convert assignment marks to a scale of 10
	asgnNo = (asgnNo/60)*10;
	cout<<endl;
	// Input and validate marks for quiz (out of 60)
	do{
		quizNo=input("\nENTER QUIZ MARKS(OUT OF 60)      : ");
	}while(quizNo < 0 || quizNo > 60);
	
	// Convert quiz marks to a scale of 10
	quizNo = (quizNo/60)*10;
	cout<<endl;
	// Input and validate marks for OHT1 (out of 30)
	do{
		oht1No=input("\nENTER OHT 1 MARKS(OUT OF 30)     : ");
	}while(oht1No < 0 || oht1No > 30);
	
	// Convert OHT1 marks to a scale of 15
	oht1No = (oht1No/30)*15;
	cout<<endl;
	// Input and validate marks for OHT2 (out of 30)
	do{
		oht2No=input("\nENTER OHT 2 MARKS (OUT OF 30)    : ");
	}while(oht2No < 0 || oht2No > 30);
	
	// Convert OHT2 marks to a scale of 15
	oht2No = (oht2No/30)*15;
	cout<<endl;
	// Input and validate marks for the final exam (out of 50)
	do{
		FinalNo=input("\nENTER FINAL MARKS(OUT OF 50)     : ");
	}while(FinalNo < 0 || FinalNo > 50);
	cout<<endl;
	// Calculate and return the total marks for the subject
	return (asgnNo+quizNo+oht1No+oht2No+FinalNo); 
}




// Constructor for the student class that initializes object with provided roll number
student::student(string x)
{
	// Assign the provided roll number to the student object
	rollNo=x;	
	cout<<endl;
	// Prompt the user to enter the name of the student and assign it to the object                                
	name=inputs("ENTER THE NAME OF THE STUDENT : ");
	cout<<endl;
	// Prompt the user to enter the father's name and assign it to the object
	fatherName=inputs("ENTER FATHER'S NAME   : ");
	cout<<endl;
	// Prompt the user to enter a password for the student (6 digits) and assign it to the object
	password=inputc("ENTER PASSWORD FOR STUDENT(6 DIGITS) : ",6);
	cout<<endl;
	// Prompt the user to enter marks for different subjects and assign them to respective variables
	oopt=subjectMarks("\nENTER OOP(OBJECT ORIENTATED PROGRAMMING) THEORY MARKS \n");
	oopp=subjectMarks("\nENTER OOP(OBJECT ORIENTATED PROGRAMMING) PRACTICAL MARKS \n");
	fa=subjectMarks("\nENTER FINANCIAL ACCOUNTING MARKS \n");
	ps=subjectMarks("\nENTER PROBABILITY & STATISTICS MARKS \n");
	cps=subjectMarks("\nENTER COMMUNICATION AND PRESENTATION SKILLS MARKS \n");
	dldt=subjectMarks("\nENTER DLD(DIGITAL LOGIC DESIGN) THEORY MARKS \n");
	dldp=subjectMarks("\nENTER DLD(DIGITAL LOGIC DESIGN) PRACTICAL MARKS \n");
	
	// Calculate GPA based on the obtained marks in different subjects
	gpa=(((oopt+oopp+fa+ps+cps+dldt+dldp)/700)*4);
	
	
	// Assign the current time to the 'time' variable
	time=currentTime();
}




// Function to display a formatted layout for presenting student details
void student::layout()
{
	// Clear the console screen
	system("cls");
	
	// Print column headers with appropriate formatting
	cout<<setw(12)<<"ROLL NUMBER"<<setw(22)<<"NAMES"<<setw(22)<<"FATHER NAME"<<setw(22)<<"OOP(T)"<<setw(16)<<"OOP(P)"
		<<setw(16)<<"FA"<<setw(16)<<"P&S"<<setw(16)<<"CPS"<<setw(16)<<"DLD(T)"<<setw(16)<<"DLD(P)"<<setw(16)<<"GPA"
		<<setw(16)<<"CGPA"<<setw(17)<<"UPDATE TIME"<<setw(16)<<"\n\n\n";
		
	return;		// Return from the function
}



#endif
