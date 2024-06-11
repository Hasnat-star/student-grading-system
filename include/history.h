#ifndef HISTORY_H
#define HISTORY_H

#include<iostream>


using namespace std;

class node{
	public:
	string data;
	node* next;
	node(string d){
		data=d;
		next=NULL;
	}
};

class History{
	private:
		node *top;
		int size;
	public:
		History(){
			top=NULL;
			size=0;
		}	
	~History(){
		while(!isEmpty()){
			pop();
		}
	}
	
	void push(string d,string x,string y,string t){
		d.append(x).append(y).append(t);
		node *newnode = new node(d);
		newnode->next=top;
		top=newnode;
		size++;
	}	
	
	void pop(){
		if(isEmpty()){
			cout<<"\nHistory is Empty \n";
			return;
		}
		
		node *temp=top;
		top=top->next;
		cout<<"last deleted activity is \n";
		cout<<temp->data<<endl;
		delete temp;
		size--;
	}
	string peek(){
		if(isEmpty()){
			return "\nHistory is Empty \n";
		}
		return top->data;
	}
	bool isEmpty(){
		return size==0;
	}
	
	void display() {
		if(isEmpty()){
			cout<<"\nHistory is Empty \n";
			return;
		}
        node* current = top;
        cout << "\nHistory is \n\n";
        while (current != NULL) {
            std::cout << current->data << endl;
            current = current->next;
        }
        std::cout << std::endl;
    }
    
        // Delete all data in the stack
void deleteAll() {
        // Pop all elements until the stack is empty
        while (!isEmpty()) {
    	node *temp=top;
		top=top->next;
		delete temp;
		size--;
        }
    }
    
        // Save data to a file
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        node* current = top;
        while (current != NULL) {
            file << current->data << endl;
            current = current->next;
        }

        file.close();
    }

    // Read data from a file and write it back into the stack
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        deleteAll(); // Clear existing data from the stack

        string line;
        while (getline(file, line)) {
            push(line, " ", " ", " "); // Assuming x, y, t are empty for now
        }

        file.close();
    }
    
    void showHistory(){
    	
	do{
		
		system("pause");
		system("cls");
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 1 TO SHOW ALL HISTORY     *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 2 TO CHECK LAST ACTIVITY  *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 3 TO DELETE THE LAST ACTIVITY *********";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 4 TO CLEAR HISTORY        ************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER ANY OTHER KEY TO EXIT     *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		string x=inputc(" ",1);
		char chk = x.at(0);
		system("cls");
		switch(chk)
		{
			case '1':
				display();
				break;
			case '2':
				cout<<"\nLast performed activity is \n"<<peek()<<endl;
				break;
			case '3':
				pop();
				saveToFile("history.txt");
				break;
			case '4':
				deleteAll();
				saveToFile("history.txt");
				cout<<"\nALL HISTORY IS CLEARED\n\b";
				break;	
			default:
				return;	
		}
	}while(1);

}
	
};



#endif
