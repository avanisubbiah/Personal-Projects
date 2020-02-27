#include <stdio.h>
#include <stdlib.h>

// Defining type struct node with char val and next pointer (nodeChar)
typedef struct node
{
    char val; // Value of the node
    struct node* next; // Pointer to next node
} nodeChar;

// Declaring linked list methods
void push(nodeChar * head, char val);
char pop(nodeChar * head);
char peek(nodeChar* head);
void printLinkedList(nodeChar * head);

int main (void)
{
    // Allocating space for the head node
    nodeChar* head = (nodeChar *) malloc(sizeof(nodeChar));
    if (head == NULL) {
        return 1;
    }
    head->val = '\0';
    head->next = NULL;
    //push(head,'a');
    // Iterating and adding 10 values to linked list
    /*
    for(int i=0; i<10; i++)
    {
        char val = 'a';
        push(head, val);
    }
    */
    
    printLinkedList(head);
    printf("peek: %c\n", peek(head));
    printLinkedList(head);
}

void push(nodeChar * head, char val)
{
    // Setting pointer type node to head
    nodeChar * currentNode = head;
    // iterating through the list
    while (currentNode->next != NULL) 
    {
        currentNode = currentNode->next;
    }

    //Creating node at end of list
    currentNode->next = (nodeChar *) malloc(sizeof(nodeChar));
    currentNode->next->val = val;
    currentNode->next->next = NULL;
}

// Method to pop top of list
char pop(nodeChar * head)
{
    // Setting currentNode to head
    nodeChar * currentNode = head;
    char returnChar;
    // Iterating through nodes through to end
    if(currentNode->next != NULL) {
        while (currentNode->next->next != NULL)
        {
            currentNode = currentNode->next;
        }
        returnChar = currentNode->next->val;
        currentNode->next = NULL;
    } else {
        printf("Stack is empty\n");
    }
    // Returning value of node at end
    
    return returnChar;
}

char peek(nodeChar* head)
{
    nodeChar * currentNode = head;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    return currentNode->val;
}

// Print whole linked list
void printLinkedList(nodeChar * head)
{
    nodeChar * currentNode = head;
    
    // Iterate through list and print each value
    int index = -1;
    while (currentNode != NULL)
    {
        printf("Index: %d = %c\n", index, currentNode->val);
        currentNode = currentNode->next;
        index++; 
    }
}