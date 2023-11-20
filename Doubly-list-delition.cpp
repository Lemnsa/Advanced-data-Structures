// A C++code to perform all deletion operations on Linked List*/

#include <bits/stdc++.h>

using namespace std;

/* A class to create nodes */

class Node

{

public:

int data;

Node* next;

Node* prev;

};

/*A Function to delete a node in a Linked List.*/

void deleteNode(Node** head, Node* del)

{

/* base case */

if (*head == NULL || del == NULL)

return;

/* If head node is the node to be deleted */

if (*head == del)

*head = del->next;

/* Change next only if node to be

deleted is NOT the last node */

if (del->next != NULL)

del->next->prev = del->prev;

/* Change prev only if node to be

deleted is NOT the first node */

if (del->prev != NULL)

del->prev->next = del->next;

/* Finally, free the memory occupied by del*/

free(del);

return;

}

/* A function to insert a node at the beginning of the list*/

void push(Node** head, int newdata)

{

/* create newnode */

Node* newnode = new Node();

/* put in the data */

newnode->data = newdata;

/* link the new node's next to head

and previous as NULL */

newnode->next = (*head);

newnode->prev = NULL;

/* link the head node's prev to new node */

if ((*head) != NULL)

(*head)->prev = newnode;

/* changing head */

(*head) = newnode;

}

/* Function to print nodes in a given linked list

This function is the same as printList() of singly linked list */

void printList(Node* node)

{

while (node != NULL)

{

cout << node->data << " ";

node = node->next;

}

}

int main()

{

/* Start with the empty list */

Node* head = NULL;

/* Let us create the linked list 2<->3<->5<->7 */

push(&head, 7);

push(&head, 5);

push(&head, 3);

push(&head, 2);

cout << "Original Linked list ";

printList(head);

/* delete nodes from the linked list */

deleteNode(&head, head); /*delete first node*/

deleteNode(&head, head->next); /*delete middle node*/

deleteNode(&head, head->next); /*delete last node*/

/* Modified linked list will be NULL<-5->NULL */

cout << "\nModified Linked list ";

printList(head);

return 0;

}


