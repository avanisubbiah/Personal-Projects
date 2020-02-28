#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRSIZE 10

// Defining type struct node with char val and next pointer (nodeStr)
typedef struct node
{
    char val[STRSIZE]; // Val[STRSIZE]ue of the node
    struct node* next; // Pointer to next node
} nodeStr;

// Declaring linked list methods
void push(nodeStr * head, char val[STRSIZE]);
const char * pop(nodeStr * head);
const char * peek(nodeStr* head);
void printLinkedList(nodeStr * head);

int main (void)
{
    // Allocating space for the head node
    nodeStr* head = (nodeStr *) malloc(sizeof(nodeStr));
    if (head == NULL) {
        return 1;
    }
    strcpy(head->val, "head");
    head->next = NULL;
    push(head, "hello");
    //push(head,"asdfsdf");
    // Iterating and adding 10 val[STRSIZE]ues to linked list
    /*
    for(int i=0; i<10; i++)
    {
        char val[STRSIZE] = 'a';
        push(head, val[STRSIZE]);
    }
    */
    
    printLinkedList(head);
    printf("peek: %s\n", peek(head));
    printLinkedList(head);
    printf("pop: %s\n", pop(head));
    printLinkedList(head);
}

void push(nodeStr * head, char val[STRSIZE])
{
    // Setting pointer type node to head
    nodeStr * currentNode = head;
    // iterating through the list
    while (currentNode->next != NULL) 
    {
        currentNode = currentNode->next;
    }

    //Creating node at end of list
    currentNode->next = (nodeStr *) malloc(sizeof(nodeStr));
    strcpy(currentNode->next->val, val);
    currentNode->next->next = NULL;
}

// Method to pop top of list
const char * pop(nodeStr * head)
{
    // Setting currentNode to head
    nodeStr * currentNode = head;
    // Iterating through nodes through to end
    int canReturnVal = 0;
    if(currentNode->next != NULL) {
        while (currentNode->next->next != NULL)
        {
            currentNode = currentNode->next;
        }
        canReturnVal = 1;
    } else {
        printf("Stack is empty\n");
    }
    // Checking if a value can be returned
    if (canReturnVal == 1)
    {
        // Creating a array pointer to string in currentNode->next->val
        char (*returnStrP)[STRSIZE] = &currentNode->next->val;
        // Setting currenNode->next to NULL to remove from list
        currentNode->next = NULL;
        // Returning string value at returnStrP array pointer
        return *returnStrP;
    } else {
        return "\0";
    }
}

const char * peek(nodeStr* head)
{
    // Setting currentNode to head
    nodeStr * currentNode = head;
    // Iterating to end of linked list
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    // Returning value at end of linked list
    return currentNode->val;
}

// Print whole linked list
void printLinkedList(nodeStr * head)
{
    nodeStr * currentNode = head;
    
    // Iterate through list and print each val[STRSIZE]ue
    int index = -1;
    while (currentNode != NULL)
    {
        printf("Index: %d = %s\n", index, currentNode->val);
        currentNode = currentNode->next;
        index++; 
    }
}