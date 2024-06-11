#ifndef INPUT_H
#define INPUT_H

#include <iostream>    //  Provides input and output stream operations (cin, cout)

#include <conio.h>     // Includes console input/output functions like getch.


using namespace std;
// Function to get a double input with input validation and simple error handling
double input(string);



// Function to get a string input
string inputc(string,int);



// Function to get a password input with masking
string inputp(string,int);



// Function to get a non-empty string input
string inputs(string);






// Function to get a valid double input from the user
double input(string y)
{
	cout<<y;    // Display the prompt message
	char x;
	vector<char> pass;
// Loop to continuously read input until a valid double is entered
	while (true) {
	    x = getch();
	
	    // Check if the character is a digit and not Enter
	    if ((isdigit(x)) && !(x == '\r')) {
	        cout << x;
	        pass.push_back(x);
	    }
	
	    // Check if Backspace is pressed and the input is not empty
	    if (x == '\b' && !pass.empty()) {
	        cout << "\b \b";
	        pass.pop_back();
	    }
	
	    // Check if Enter is pressed and the input is not empty
	    if (x == '\r' && !pass.empty()) {
	        break; // Break out of the loop if Enter is pressed with a non-empty input
	    }
	}

	return stod(string(pass.begin(),pass.end()));
	
}




// Function to get a password input from the user with masking
string inputp(string y,int q)
{
	cout<<y;     // Display the prompt message
	char x;
	vector<char> pass;
	
	// Loop until 'Enter' key is pressed
	for(int i=0; ;)
	{
		x=getch();     // Get a character without echoing it to the console
		
		
		// Check if the character is a printable character  and within the allowed limit (q)
		if (isalnum(x) && isprint(x) && (i < q)&&(!(x=='\r')))
		{
			cout<<"*";    // Display an asterisk to mask the entered character
			pass.push_back(x);    // Store the character in the password vector
			i++;
		}
		
		// Check if backspace key is pressed and there are characters in the password
		if(x == '\b' && !pass.empty())
		{
			cout<<"\b \b";    // Erase the last character on the screen
			pass.pop_back();  // Remove the last character from the password vector
			i--;
		}
		
		// Check if 'Enter' key is pressed
		if(x == '\r' && !pass.empty())
		{
			break;   // Exit the loop when 'Enter' key is pressed
		}	
	}
	return string(pass.begin(),pass.end());   // Return the entered password as a string
}




// Function to get a masked character input from the user with specified length
string inputc(string y, int q)
{
    cout << y;        // Display the prompt message
    char x;
    vector<char> pass;
    
    // Loop until 'Enter' key is pressed
    for(int i =0; ; )
    {
        x = getch();   // Get a character without echoing it to the console
        
        // Check if the character is a printable character (letter or digit) and within the allowed limit (q)
       	if (isalnum(x) && isprint(x) && (i < q)&&(!(x=='\r')))
        {
            cout << x;   // Display the character to the console
            pass.push_back(x);  // Store the character in the password vector
            i++;
        }
        
        // Check if backspace key is pressed and there are characters in the password
        if (x == '\b' && !pass.empty())
        {
            cout << "\b \b";   // Erase the last character on the screen
            pass.pop_back();   // Remove the last character from the password vector
            i--;
        }
        
        // Check if 'Enter' key is pressed
        if (x == '\r'&& !pass.empty())
        {
            break;  // Exit the loop when 'Enter' key is pressed
        }
    }
    
    return string(pass.begin(), pass.end());  // Return the entered characters as a string
}




// Function to get non-empty string input from the user
string inputs(string y)
{
    cout << y;  // Display the prompt message
    char x;
    vector<char> pass;
    for (int i=0; ; )
    {
    	x=getch();
    	if((isalpha(x)||isspace(x))&&(!(x=='\r')))
    	{
    		cout<<x;
    		pass.push_back(x);
    		i++;
		}
		if(x=='\b' && !pass.empty())
		{
			cout<<"\b \b";
			pass.pop_back();
			i--;
		}
		if(x=='\r'&& !pass.empty())
		{
			break;
		}
		
	}
    return string(pass.begin(),pass.end());
}

#endif
