#include <stdio.h>
#include <stdlib.h>

// Defining type struct node with double val and next pointer (nodeDouble)
typedef struct node
{
    double val; // Value of the node
    struct node* next; // Pointer to next node
} nodeDouble;

// Declaring linked list methods
void createNodeAtEnd(nodeDouble * head, double val);
double retrieveAtIndex(nodeDouble * head, int index);
void setAtIndex(nodeDouble * head, int index, double val);
void printLinkedList(nodeDouble * head);
void removeNode(nodeDouble * head, int index);
void addNodeAfter(nodeDouble * head, int index, double val);

int main (void)
{
    // Allocating space for the head node
    nodeDouble* head = (nodeDouble *) malloc(sizeof(nodeDouble));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = NULL;
    // Iterating and adding 10 values to linked list
    for(int i=0; i<10; i++)
    {
        double val = 1.1*((double)i);
        createNodeAtEnd(head, val);
    }
    setAtIndex(head, 2, 2.5343);
    removeNode(head, 4);
    addNodeAfter(head, 5, 50.1243);
    printLinkedList(head);
    printf("Value: %lf Found at: %d\n", retrieveAtIndex(head, 3), 3);
}

void createNodeAtEnd(nodeDouble * head, double val)
{
    // setting pointer type node to head
    nodeDouble * currentNode = head;
    // iterating through the list
    while (currentNode->next != NULL) 
    {
        currentNode = currentNode->next;
    }

    //Creating node at end of list
    currentNode->next = (nodeDouble *) malloc(sizeof(nodeDouble));
    currentNode->next->val = val;
    currentNode->next->next = NULL;
}

// Method to retrieve double value at index in linked list
double retrieveAtIndex(nodeDouble * head, int index)
{
    nodeDouble * currentNode = head;
    // Iterating through list according to specified index
    for (int i = 0; i < index; i++)
    {   
        // Checking if index is valid
        if (currentNode->next == NULL) 
        {
            printf("Index out of bounds\n");
        } else 
        {
            currentNode = currentNode->next;
        }
    }

    // Returning value of node at index
    return currentNode->val;
}

// Set value of node at index equal to value
void setAtIndex(nodeDouble * head, int index, double val)
{
    nodeDouble * currentNode = head;
    // Iterating through list according to specified index
    for (int i = 0; i < index; i++)
    {
        // Checking if index is valid
        if (currentNode->next == NULL)
        {
            printf("Index out of bounds\n");
        } else
        {
            currentNode = currentNode->next;
        }
    }

    // Setting value of node at index equal to input value
    currentNode->val = val;
}

// Print whole linked list
void printLinkedList(nodeDouble * head)
{
    nodeDouble * currentNode = head;
    
    // Iterate through list and print each value
    int index = 0;
    while (currentNode != NULL)
    {
        printf("Index: %d = %lf\n", index, currentNode->val);
        currentNode = currentNode->next;
        index++; 
    }
}

// Remove node at index
void removeNode(nodeDouble * head, int index)
{
    nodeDouble * currentNode = head;

    // Iterating through linked list to node before node at index
    for (int i = 0; i < index-1; i++)
    {
        if (currentNode == NULL)
        {
            printf("Index out of bounds\n");
        } else
        {
            currentNode = currentNode->next;
        }
    }

    // Setting the next pointer of node before index to node after index
    currentNode->next = currentNode->next->next;
}

void addNodeAfter(nodeDouble * head, int index, double val)
{
    nodeDouble * currentNode = head;
    nodeDouble* newNode = (nodeDouble *) malloc(sizeof(nodeDouble));
    newNode->val = val;
    
    for (int i = 0; i < index; i++)
    {
        if (currentNode == NULL)
        {
            printf("Index out of bounds\n");
        } else
        {
            currentNode = currentNode->next;
        }
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
}