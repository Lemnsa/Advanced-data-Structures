/* A c++ program to perform all insertion operations*/

#include <bits/stdc++.h>

using namespace std;

// A class to create nodes

class Node

{

public:

int data;

Node* next;

Node* prev;

};

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

/* A function to insert a node after a given node */

void insertAfter(Node* prevnode, int newdata)

{

/*1. check if the given prevnode is NULL */

if (prevnode == NULL)

{

cout<<"given previous node can't be null";

return;

}

/* 2. allocate new node */

Node* newnode = new Node();

/* 3. put in the data */

newnode->data = newdata;

/* 4. Make new node's next as prevnode's next */

newnode->next = prevnode->next;

/* 5. Make the prevnode's next as newnode */

prevnode->next = newnode;

/* 6. Make prevnode as newnode's prev */

newnode->prev = prevnode;

/* 7. Change previous of newnode's next node */

if (newnode->next != NULL)

newnode->next->prev = newnode;

}

/* A function to insert at the end of the list */

void append(Node** head, int newdata)

{

/* create newnode */

Node* newnode = new Node();

Node* last = *head;

/* put in the data */

newnode->data = newdata;

/*This newnode is going to be the last node, so

we will make next of it as NULL*/

newnode->next = NULL;

/* check if the Linked List is empty, then make the new

node as head */

if (*head == NULL)

{

newnode->prev = NULL;

*head = newnode;

return;

}

/* Else traverse till the last node */

while (last->next != NULL)

last = last->next;

/* Change the next of last node */

last->next = newnode;

/* Make last node as new node's prev */

newnode->prev = last;

return;

}

// A function to print the list

void printList(Node* node)

{

while (node != NULL)

{

cout<<" "<<node->data<<" ";

node = node->next;

}

}

int main()

{

/* Start with the empty list */

Node* head = NULL;

// Insert 6 at the last

append(&head, 6); //6->NULL

// Insert 7 at the beginning

push(&head, 7); //7->6->NULL

// Insert 1 at the beginning

push(&head, 1); //1->7->6->NULL

// Insert 4 at the end

append(&head, 4); //1->7->6->4->NULL

// Insert 8, after 7

insertAfter(head->next, 8); //1->7->8->6->4->NULL

cout << "Created DLL is: ";

printList(head);

return 0;

}


