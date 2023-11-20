//A c++ code to insert a node

//in singly linked list

#include <bits/stdc++.h>

using namespace std;

//A class to create node

class Node {

public:

    int data;

    Node* next;

};

//insert a node at the beginning

void push(Node** head, int newdata)

{

//create newnode

    Node* newnode = new Node();

    newnode->data = newdata;//put in data

    newnode->next = (*head);//link newnode with head

    (*head) = newnode;//changing head

}

//A function to delete a node

void deleteNode(Node** head, int key)

{

    Node* temp = *head;//creating temp node

    Node* prev = NULL;//creating prev node

//checking if node to be deleted is head the node

    if (temp != NULL && temp->data == key)

    {

        *head = temp->next;//changing head

        delete temp; //delete node

        return;

    }

    else

    {

//traversing to find key to delete

        while (temp != NULL && temp->data != key)

        {

            prev = temp;

            temp = temp->next;

        }

        if (temp == NULL)

            return;

        prev->next = temp->next;

        delete temp;//delete node

    }

}

// This function prints contents of

// linked list starting from the

// given node

void printList(Node* node)

{

    while (node != NULL)

    {

        cout << node->data << “ “;

        node = node->next;

    }

}

// Driver code

int main()

{

// Start with the empty list

    Node* head = NULL;

// Add elements in linked list

    push(&head, 7);

    push(&head, 1);

    push(&head, 3);

    push(&head, 2);

    puts(”Created Linked List: “);

    printList(head);

    deleteNode(&head, 1);

    puts(”\nLinked List after Deletion of 1: “);

    printList(head);

    return 0;

}


