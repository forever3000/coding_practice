// Simple C++ program to print 
// next greater elements in a 
// given array 
#include <iostream>
#include <stack>

using namespace std; 
  
class Node {
    public:
        int data;
        Node *next;
};

void Push (Node **headRef, int value) {
    // Allocate new node
    Node *new_node = new Node();

    // Assign the data for new node
    new_node->data = value;

    // Make the next of node as headRef
    new_node->next = (*headRef);

    // Move the headRef point to node
    (*headRef) = new_node;
}

void InsertAfter (Node *preNode, int value) {
    if (preNode == NULL) {
        cout << "the given previous node can not be NULL" << endl;
    }

    // Allocate new node
    Node *new_node = new Node();

    // Assign the data for new node
    new_node->data = value;

    // Make the new node next as the previous node next
    new_node->next = preNode->next;

    // Move the next of the previous node as new node
    preNode->next = new_node;
}

void Append (Node **headRef, int value) {
    // Allocate new node
    Node *new_node = new Node();

    // Assign the data for new node
    new_node->data = value;

    // Make the next of new node as NULL
    new_node->next = NULL;

    // If the linked list is empty, then make the new node as head 
    if ((*headRef) == NULL) {
        (*headRef) = new_node;
        return;
    }

    // Else traverse till the last node
    Node *last = *headRef;

    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node as new node
    last->next = new_node;
}

void PrintLinkedList (Node *node) {
    while (node != NULL) {
        cout << node ->data <<endl;
        node = node->next;
    }
}
  
// Driver Code 
int main() 
{ 
    Node *head = NULL;

    Push(&head, 10);
    Push(&head, 9);
    Push(&head, 7);
    Push(&head, 3);
    Push(&head, 6);
    InsertAfter(head, 8);
    Append(&head, 15);
    PrintLinkedList(head);

    return 0; 
}
