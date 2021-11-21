
#include <bits/stdc++.h>
using namespace std;
 
// A linked list node
class Node{
public:
    int data;
    Node* next;
};
 
// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the
// list.
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}

void findNumber(Node* node,int key){
    bool check = false;
    while (node != NULL)
    {
        if(node->data ==key){
            cout << "Found at"<<node->data;
            check =true;
        }
        //cout << node->data << " ";
        node = node->next;
    }
    if(!check){
        cout<<key<<"Not Found";
    }
}
 
// This function prints contents of
// linked list starting from the
// given node
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
 
// Driver code
int main()
{
    	int choice, number,numberTosearch,numberTodelete;
     
    // Start with the empty list
    Node* head = NULL;
 
    // Add elements in linked list
    do{
        	cout << endl;
		cout << "Please enter an option:\n"
			<< "1. Add number to the list\n"
			<< "2. Delete number from list\n"
			<< "3. Search for a number in the list\n"
			<< "4. Print the list\n"
			<< "5. Exit.\n"
			<< "Choose an option: ";
		cin >> choice;
		
		switch(choice){
		    case 1:
		    	cout << "Enter a number to add to the list: ";
		     	cin >> number;
		     	push(&head,number);
		     	
		     	printList(head);
		    break;
		    case 2:
		    	cout << "Enter a number to Delete: ";
		     	cin >> numberTodelete;
		     	deleteNode(&head, numberTodelete);
		     	
		     	printList(head);
		    break;
		    case 3:
		    	cout << "Enter a number to Search: ";
		     	cin >> numberTosearch;
		     	findNumber(head, numberTosearch);
		     	
		     	//printList(head);
		    break;
		    case 4:
		    cout<<"Number Present In the List are\n";
		    printList(head);
		    break;
		}

    } while(choice !=6);
   
     
    return 0;
}