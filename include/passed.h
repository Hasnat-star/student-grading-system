#ifndef PASSED_H
#define PASSED_H


#include <iostream>
#include <string>

using namespace std;

// Node structure to represent each element in the binary tree
class  Node {
	public:
    string data;  // Value of the node
    double priority;  // Priority of the node
    Node* left;  // Pointer to the left child
    Node* right;  // Pointer to the right child

    // Constructor
    Node(string data, double priority) : data(data), priority(priority), left(NULL), right(NULL) {}
};

// Priority queue class using binary tree
class passed {
private:
    Node* root; // Pointer to the root of the binary tree

    // Function to insert a new node recursively
    Node* insertNode(Node* root, string data, double priority) {
        if (root == NULL) {
            return new Node(data, priority);
        }
        if (priority < root->priority) {
            root->left = insertNode(root->left, data, priority);
        } else {
            root->right = insertNode(root->right, data, priority);
        }
        return root;
    }

    // Function to find the node with the highest priority recursively
    Node* findMin(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root->left == NULL) {
            return root;
        }
        return findMin(root->left);
    }

    // Function to delete the node with the highest priority recursively
    Node* deleteMin(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        root->left = deleteMin(root->left);
        return root;
    }
    void deleteAllNodes(Node* root) {
        if (root != NULL) {
            deleteAllNodes(root->left);
            deleteAllNodes(root->right);
            delete root;
        }
        root ==NULL;
    }
        // Function to find the node with the least priority recursively
    Node* findMax(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root->right == NULL) {
            return root;
        }
        return findMax(root->right);
    }
    string peek() {
        if (isEmpty()) {
            return "\nNONE OF THE STUDENT IS PASSED.\n";
        }
        Node* minNode = findMax(root);
        string minValue = "NAME : ";
        minValue.append(minNode->data).append(" , GPA : ").append(to_string(minNode->priority));
        return minValue;
    }
    
public:
    // Constructor
    passed() : root(NULL) {}

    // Destructor (to delete all nodes and free memory)
    ~passed() {
        deleteAllNodes(root);
    }

    // Function to insert an element into the priority queue
    void push(string data, double priority) {
        root = insertNode(root, data, priority);
    }

    // Function to remove and return the highest priority element from the priority queue
    string pop() {
        if (isEmpty()) {
            return "\nNONE OF THE STUDENT IS PASSED.\n";
        }
        Node* minNode = findMin(root);
        string minValue = "NAME : ";
        minValue.append(minNode->data).append(" , GPA : ").append(to_string(minNode->priority));
        return minValue;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return root == NULL;
    }
    // Function to display all nodes in the tree in-order
    void displayInOrder(Node* root) const {
    	
        if (root != NULL) {
            displayInOrder(root->left);
            cout << "Name : " << root->data << ", GPA : " << root->priority << endl;
            displayInOrder(root->right);
        }
		return;
    }
    void showdata(){
    	do{
    	system("pause");
		system("cls");
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 1 TO SHOW PASSED STUDENTS *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 2 TO SHOW STDUENT WITH LOW GRADE  *****";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 3 TO SHOW STDUENT WITH HIGH GRADE *****";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER 4 TO DELETE ALL DATA      *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t*************        ENTER ANY OTHER KEY TO EXIT     *************";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t******************************************************************\n";
		string x=inputc(" ",1);
		char chk = x.at(0);
		system("cls");
		switch(chk)
		{
			case '1':
				{
					cout<<"\nAll passed students are \n\n";
					if (root == NULL){
    					cout<<"\nNone of the student is passed \n";
    					break;
					}
					displayInOrder(root);
					break;
				}
			case '2':
				cout<<"\nStudent with Lowest Grade is \n "<<pop()<<endl;
				break;
			case '3':
				cout<<"\nStudent with the Highest Grade is \n"<<peek()<<endl;
				break;
			case '4':
				deleteAllNodes(root);
				root=NULL;
				cout<<"\nALL DATA IS DELETED \n";
				break;			
			default:
				return;	
		}
		}while(1);
	}
};
#endif
