#ifndef ADMIN_H
#define ADMIN_H
#include "student.h"
#include "passed.h"
#include "history.h"
#include <iostream>    //  Provides input and output stream operations (cin, cout)

#include <fstream>     // Deals with file stream operations (ifstream for input, ofstream for output).

#include <vector>      // Implements dynamic array container (vector).

#include <cstring>	   // Provides functions for handling C-style strings.

#include <string>      // Includes the C++ string class and related functions.

#include <conio.h>     // Includes console input/output functions like getch.

#include <iomanip>     // Offers input/output manipulators, such as setw.

#include <algorithm>   // Contains algorithms for operations on ranges of elements, like find_if and remove_if.



using namespace std;


// Class representing an admin, derived from student class
class admin:public student
{
		// vector to store student objects into it
		vector<student>students;
		
	public:
		History historyData;
		passed passStudent;
		// Default constructor
		admin(){}
		
		// Destructor
		~admin(){}
		
		// Function to remove a student
		void removeStudent();
		
		// Function to add a student
		void addStudent();
		
		// Function to modify a student's information
		void modifyStudent();	
		
		// Function to search for a student by roll number
		void searchRollNo() const;
		
		// Function to save student data to a file
		void saveToFile(const string&);
		
		// Function to load student data from a file
		void loadFile(const string&);
		
		// Function to display admin menu
		void adDisplay();
		
		// Function for Head of Department (HOD) menu
		void hod();

		// Function for student login check
		void stdntchk();
};


// Function to remove a student from the list based on their roll number
void admin::removeStudent()
{
	char chk;
	do{
		// Prompt the admin to enter the student's roll number for removal
		string regNo = to_string(int(input("\nENTER STUDENT'S ROLL NUMBER : ")));
		
		// Find the student with the specified roll number in the list
	  	auto it = find_if(students.begin(), students.end(), [&](const student& s)
	   		{
	        	return s.RollNo() == regNo;
	    	});
	
		// Check if the student was found
	    if (it != students.end())
	    {
	    string z=inputc("\n\nSTUDENT WITH PROVIDED ROLL NUMBER FOUNDED\nIF YOU WANT TO REMOVE HIM PRESS(Y) : ",1);	
		    if(z=="y"||z=="Y"){
		    	
		    	// Remove the student from the list
		        students.erase(it);
		        cout << "\nStudent with roll number " << regNo << " has been removed.\n";
		        historyData.push("Student with roll number ",regNo," is removed at : ",currentTime());
		        historyData.saveToFile("hisrtory.txt");
		    }else{
		    	cout<<"\nPROCESS IS BEING CANCELLED\n";
			}
	    }
	    else
	    {
	    	
	    	// Display a message if the student is not found
	        cout << "\nStudent with roll number " << regNo << " does not exist.\n";
	    }
	    
	    cout<<"IF YOU LIKE TO REMOVE OTHER STUDENTS PRESS(y) : ";
	    cin>>chk;
	}while(chk=='y'||chk=='Y');
	
	return;   // Return from the function
}




// Function to add a new student to the list
void admin::addStudent()
{
	cout<<endl;
	// Variables for user input and student roll number
	string chk;
	string rNo;
	do{
		// Prompt the admin to enter the student's roll number
		rNo=to_string(int(input("\nENTER THE STUDENTS ROLL NUMBER : ")));
		
		// Check if the student with the entered roll number already exists
		auto it =find_if(students.begin(),students.end(),[&](const student& s)
		{
			return s.RollNo()==rNo;
		});
		
		// Display a message if the student already exists, otherwise break from the loop
		if(it != students.end())
		{
			cout<<"\nSTUDENTS WITH ROLL NUMBER "<<rNo<<" ALREADY EXISTS\n";
		}else{
			break;
		}
	}while(1);
	
	// Create a new student object with the entered roll number
	student s(rNo);
	
	// Add the new student to the list
	students.push_back(s);
	historyData.push("New student of roll number ",rNo," is added at ",currentTime());
	historyData.saveToFile("history.txt");
	// Display a success message
	cout<<"\nSTUDENT ADDED SUCCESSFULLY \n";
	
	// Prompt the admin if they want to add more students
	chk=inputs("\nIF YOU WANT TO ADD MORE STUDENTS PRESS(y) : ");
	cout<<endl;
	 // If the admin wants to add more students, recursively call the function, else return
	if(chk=="y"||chk=="Y"){
		addStudent();
	}else{
		return;
	}
}




// Function to modify student information
void admin::modifyStudent()
{
	string z;
	
	// Repeat the modification process until the admin decides to exit
	do{
		
		 // Prompt the admin to enter the roll number of the student to be modified
		string rno =to_string(int(input("\nENTER THE REGISTRATION NUMBER OF STUDENT TO MODIFY : ")));
		
		// Find the student with the entered roll number
		auto it = find_if(students.begin(),students.end(),[&](const student& s)
		{
			return s.RollNo()==rno;
		});
		
		// Check if the student with the entered roll number exists
		if(it != students.end())
		{
			cout<<"\nSTUDENT WITH PROVIDED ROLL NUMBER FOUNDED\n";
			
			// Create a new student object with the entered roll number	
			student news(rno);
			historyData.push("Data of roll number ",rno," is modified at ",currentTime());
			historyData.saveToFile("history.txt");
			// Replace the existing student with the new student information
			*it = news;
		}else{
			cout<<"\nSTUDENT WITH THE ROLL NUMBER "<<rno<<" NOT FOUND\n";
		}
		
		// Prompt the admin if they want to modify more students
		z =inputc("\nIF YOU WANT TO MODIFY MORE STUDENTS PRESS(y) : ",1);
		cout<<endl;
		
	}while((z=="y"||z=="Y"));
}




// Function to search for a student by roll number and display their information
void admin::searchRollNo() const
{
	char chk;
	
	// Repeat the search process until the admin decides to exit
	do{
		
		// Prompt the admin to enter the roll number of the student to be searched
		string rno=to_string(int(input("\nENTER THE ROLL NUMBER TO SEARCH : ")));
		
		// Find the student with the entered roll number
		auto it =find_if(students.begin(),students.end(),[&](const student& s)
		{
			return s.RollNo()==rno;
		});
		
		// Check if the student with the entered roll number exists
		if(it != students.end())
		{
			
			// Display the information of the found student
			it->show();
		}else{
			cout<<"\nSTUDENT WITH ROLL NUMBER "<<rno<<" DOES NOT EXIST\n";
		}
		
		// Prompt the admin if they want to search for more students
		cout<<"\n\nIF YOU WANT TO SEARCH MORE STUDENTS PRESS(y) :";
		
		cin>>chk;
		
	}while(chk=='y'||chk=='Y');
	

	
	return;
}




// Function to save the information of all students to a file
void admin::saveToFile(const string& filename) 
{
	
	// Open the file for writing, truncating its content if it already exists
    ofstream ofile(filename, ios::out | ios::trunc);
    
    // Check if the file is successfully opened
    if (!ofile.is_open())
    {
        cout << "\nERROR WHILE OPENING FILE\n";
        return;
    }
    
    // Loop through each student and write their information to the file
    for (const auto& s : students)
    {
        ofile<<s;
    }
    
    // Close the file after writing
    ofile.close();
}




// Function to load student information from a file
void admin::loadFile(const string& filename)
{
	
	// Open the file for reading
    ifstream ifile(filename, ios::in);
    
    // Check if the file is successfully opened
    if (!ifile.is_open())
    {
        cout << "\nERROR WHILE OPENING FILE\n";
        return;
    }
    
    // Clear the existing student data
    students.clear();
    
    // Temporary variable to store each student's information
    student temp;
    // Read student information from the file until the end is reached
    while (ifile>>temp)
    {
    	if(temp.Gpa()>2.000000){
    		passStudent.push(temp.Name(),temp.Gpa());
    	}
    	// Add the read student to the vector of students
        students.push_back(temp);
    }
    
    // Close the file after reading
    ifile.close();
}




// Function to display the admin menu and perform corresponding actions
void admin::adDisplay()
{	historyData.readFromFile("history.txt");
	historyData.push("login as Exam Officer at ",currentTime()," "," ");
	historyData.saveToFile("history.txt");
	do
	{
		
		// Display the admin menu
		system("pause");
		system("cls");
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 1 TO ADD STUDENTS RESULTS *************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 2 TO REMOVE STUDENTS      *************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 3 TO MODIFY STUDENTS      *************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 4 TO SEARCH BY ROLL NUMBER ************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 5 TO DISPLAY ALL STUDENTS *************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 6 TO REMOVE ALL STUDENTS DATA *********"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 7 TO SHOW STUDENTS PASSWORD ***********"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 8 TO CHECK THE HISTORY    *************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER ANY OTHER KEY TO EXIT     *************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		string x=inputc(" ",1);
		char chk = x.at(0);
		system("cls");
		
		// Switch statement based on user choice
		switch(chk)
		{
			case'1':
				{
					// Add a new student and save to file
					addStudent();
					saveToFile("STUDENTS.txt");
					break;
				}
			case'2':
				{
				
					// Remove a student and save to file
					removeStudent();
					saveToFile("STUDENTS.txt");
					break;
				}
			case'3':
				{
				
					// Modify a student's information and save to file
					modifyStudent();
					saveToFile("STUDENTS.txt");
					break;
				}
			case'4':
				{
					
					// Search for a student by roll number
					searchRollNo();
					break;
				}
			case'5':
				{
					
					// Display all students' information
					layout();
					for (const auto& s : students)
					{
	                	s.display();
	         		}
         		}
				break;
			case'6':
				{
					
					// Remove all students' data and save to file
					if(students.empty()){
						cout<<"\nYOU DIDNOT HAVE ANY STUDENTS DATA RETURNING TO MENU\n";
						break;
					}
					string z=inputc("\nARE YOU REALLY WANT TO REMOVE ALL STUDENTS DATA \nIF YES PRESS(Y) : ",1);
					if(z=="y"||z=="Y"){
						
						students.clear();
						historyData.push("All students data is removed at ",currentTime()," "," ");
						historyData.saveToFile("history.txt");
						saveToFile("STUDENTS.txt");
						cout<<"\nSUCCESSFULLY CLEAR THE DATA OF STUDENTS \n";
					}else{
						cout<<"\nPROCESS IS CANCELLED \n";
					}
					break;
				}
			case'7':
				{
					 // Show students' roll numbers, names, and passwords
					cout<<setw(30)<<"ROLL NUMBER"
						<<setw(30)<<"NAME"
						<<setw(30)<<"PASSWORD"<<endl<<endl;
					for (const auto& s : students)
					{
	                	s.showpass();
	         		}
					break;	
				}
			case'8':
				historyData.showHistory();
				break;	
			default:
				return;
		}
	}while(1);
}




// Function for Head of Department (HOD) actions
void admin::hod()
{
	historyData.push("log in as HOD at ",currentTime()," "," ");
	historyData.saveToFile("history.txt");
	do{
		// Display HOD menu
		system("pause");
		system("cls");
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 1 TO SEARCH BY ROLL NUMBER ************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 2 TO DISPLAY ALL STUDENTS *************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 3 TO Check PASSED STUDENTS ************"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
			<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER ANY OTHER KEY FOR MAIN MENU ***********"
			<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		string x=inputc(" ",1);
		char chk = x.at(0);
		system("cls");
		// Switch statement based on HOD's choice
		switch(chk)
		{
			case'1':
				
				// Search for a student by roll number
				searchRollNo();
				break;
			case'2':
				
				// Display all students' information
				layout();
				for (const auto& s : students)
				{
                	s.display();
         		}
				break;
			case'3':
				passStudent.showdata();
				break;	
			default:
				return;		
		}
	}while(1);	
}




// Function to verify student credentials and display information upon successful login
void admin::stdntchk()
{
	int x=0;
	do{
		
		// Display welcome message and prompt for credentials
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n"
		<<"\t\t\t\t\t\t\t\t\t\t\t*************        WELCOME TO GRADING ELEGANCE       ***********\n\n";
		string rno=to_string(int(input("\nENTER YOUR ROLL NUMBER : ")));
		string pass=inputp("\nENTER YOUR PASSWORD(6 DIGITS) : ",6);
		
		// Check if provided credentials match any student's records
		auto it =find_if(students.begin(),students.end(),[&](const student& s)
				{
					return ((s.RollNo()==rno)&&(s.Pass()==pass));
				});
				
				// If credentials are valid, display student information and return
				if(it != students.end())
				{
					historyData.push("Student with roll number ",rno," login at ",currentTime());
					historyData.saveToFile("history.txt");
					it->show();
					system("pause");
					return;
				}else{
					
					// If incorrect credentials (up to 3 attempts), provide feedback
					x++;
					if(x<3)
					cout<<"\n\nWRONG CREDENTIALS ENTER AGAIN\n";	
				}
	}while(x<3);
}	


#endif
