#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define STRSIZE 10
#define SIZEMAX 100000

int isOperand(char sym);
int operatorPrecedence(char operator);

// ______________Stack Definition and Methods______________

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

// Defining type struct node with char val and next pointer (nodeChar)
typedef struct nodeChar
{
    char val; // Value of the node
    struct nodeChar* next; // Pointer to next node
} nodeChar;

int isEmptyChar(nodeChar * head);
void pushChar(nodeChar * head, char val);
char popChar(nodeChar * head);
char peekChar(nodeChar * head);
void printLinkedListChar(nodeChar * head);

int isEmptyChar(nodeChar * head)
{
    nodeChar* currentNode = head;
    if (currentNode->next == NULL)
    {
        return 1;
    } else {
        return 0;
    }
}

void pushChar(nodeChar * head, char val)
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
char popChar(nodeChar * head)
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

char peekChar(nodeChar* head)
{
    nodeChar * currentNode = head;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    return currentNode->val;
}

// Print whole linked list
void printLinkedListChar(nodeChar * head)
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

// ______________StackInt Definition and Methods______________

long stackLong[SIZEMAX];
int topLong = -1;

// Method to check if the stackLong is empty
int isEmptyInt()
{
    if(topLong == -1)
    {
        return 1;
    } 
    
    else 
    {
        return 0;
    }
}

// Method to check if the stackLong is full
int isFullInt()
{
    if(topLong == SIZEMAX)
    {
        return 1;
    } 
    
    else 
    {
        return 0;
    }
}

// Method to push a character to stackLong
void pushLong(long data)
{
    if(!isFullInt())
    {
        topLong++;
        stackLong[topLong] = data;
    } 
    
    else 
    {
        printf("StackInt is full\n");
    }
}

// Method to pop a character from stackLong
long popLong()
{
    long data;
    
    if(!isEmptyInt())
    {
        data = stackLong[topLong];
        topLong = topLong - 1;
        return data;
    } 
    
    else 
    {
        printf("StackInt is empty\n");
    }
}

int peekInt()
{
    return stackLong[topLong];
}


char * strrev(char * str)
{
    if (! str || ! *str)
    {
        return str;
    }
    int i = strlen(str) - 1;
    int j = 0;

    char temp;
    while (i > j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i--;
        j++;
    }
}

//______________Seperate Int from Char_____________

void infixStringToStack(char infixExp[SIZEMAX], nodeStr* headInfix, nodeChar* headOperand)
{
    
    //printLinkedListChar(headOperand);
    printf("MethodRun\n");
    //printLinkedListChar(headOperand);
    // Iterating through the infix expression
    //printf("%ld", strlen(infixExp));
    
    for (int i = 0; i < strlen(infixExp); i++)
    {
        printf("----------------------------\n");
        printf("%c\n", infixExp[i]);
        if (!isOperand(infixExp[i]))
        {   
            char tempArr[SIZEMAX];
            memset(tempArr, 0, sizeof tempArr);
            char operator[2];
            memset(operator, 0, sizeof operator);
            operator[0] = infixExp[i];
            operator[1] = '\0';
            int i = 0;
            while(!isEmptyChar(headOperand))
            {
                printf("Iteration\n");
                tempArr[i] = popChar(headOperand);
                i++;
                printf("Iteration Complete\n");
            }

            strrev(tempArr);
            
            printf("tempArrFull:|%s|\n", tempArr);
            if (tempArr[0] != '\0') {
                push(headInfix, tempArr);
            }
            push(headInfix, operator);
            printLinkedList(headInfix);
        } else 
        {
            printf("Operator\n");
            pushChar(headOperand, infixExp[i]);
            printLinkedListChar(headOperand);
        }
    }
    
    printf("--------------------\n");
    printLinkedList(headInfix);
    printLinkedListChar(headOperand);
    char lastArr[SIZEMAX];
    memset(lastArr, 0, sizeof lastArr);
    int i = 0;
    while(!isEmptyChar(headOperand))
    {
        printf("Iteration\n");
        lastArr[i] = popChar(headOperand);
        i++;
        printf("Iteration Complete\n");
    }
    //printf("%d\n", popChar(headOperand));
    
    strrev(lastArr);
    
    push(headInfix, lastArr);
    
    printLinkedList(headInfix);
    
}
//______________Infix/Postfix Methods______________

// Method to determine if the next symbol in the infixExpression is an operand
int isOperand(char sym)
{
    // Determining if passed symbol is one of the following non-operands '(', ')', '+', '*', '/', '^'
    if(sym == '(' || sym == ')' || sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '^')
    {
        return 0;
    } 
    else 
    {
        return 1;
    }
}

// Method to determine the precedence of the operator
int operatorPrecedence(char operator)
{
    // Determining precedence of each operator assigned to values 3, 2, 1, and 0
    if (operator == '+' || operator == '-') 
    {
        return 1;
    } 
    else if (operator == '*' || operator == '/')
    {
        return 2;
    } 
    else if (operator == '^')
    {
        return 3;
    } 
    else 
    {
        return 0;
    }
}

/*
// Method to convert infix to postfix expression
void infixToPostfix(char infixExpression[SIZEMAX], char postfix[SIZEMAX], nodeStr* head) {
    int i = 0;
    int j = 0;
    //Iterating infix to postfix rules across infix expression
    while (infixExpression[i] != '\0')
    {
        char infixSym = infixExpression[i];
        if(isOperand(infixSym)) // Rule 2
        {
            // Passing operand to postfixExpression
            char operand = infixSym;
            postfix[j] = operand;
            j++;
        } 
        else if (infixSym == '+' || infixSym == '-' || infixSym == '*' || infixSym == '/' || infixSym == '^') // Rule 2
        {
            // Part I: Determining precedence and popping equal or higher precedence operators from the stack   
            int precedenceInfix = operatorPrecedence(infixSym);
            if (peek(head) != '(') // Checking for left parenthesis
            {
                while(precedenceInfix <= operatorPrecedence(peek(head))) 
                {
                    char operator = pop(head);
                    postfix[j] = operator;
                    j++;
                }
            }
            // Part II: Pushing new operator to stack
            char operator = infixSym;
            push(head, operator);
        } 
        else if (infixSym == '(') // Rule 4
        {
            // Pushing left parenthesis to stack
            char leftParenthesis = infixSym;
            push(head, leftParenthesis);
        } 
        else if (infixSym == ')') // Rule 5
        {
            // Popping all symbols from stack until left parenthesis
            while(peek(head) != '(') {
                postfix[j] = pop(head);
                j++;
            }
            char discard = pop(head);
            discard = '\0';
        }
        i++;
    }

    // Flushing stack to end of postfix expression
    while(!isEmpty(head)) 
    {
        char operatorsLeft = pop(head);
        postfix[j] = operatorsLeft;
        j++;
    }
    
}
*/
//______________Postfix Evaluator______________
long postfixEval(char postfixExpression[SIZEMAX])
{
    long finalResult;
    int i = 0;
    // Looping postfix evaluation
    while(postfixExpression[i] != '\0')
    {
        char postfixSym = postfixExpression[i];
        if (isOperand(postfixSym)) // Pushing operands to stack
        {
            char operand = postfixSym;
            pushLong(operand);
        } 
        else // Operator encountered
        {
            // Defining result, operand1, and operand2
            long result;
            long operand2 = popLong();
            long operand1 = popLong();
            operand1 = operand1 - '0';
            operand2 = operand2 - '0';

            // Evaluating operand1, operator, operand2 combination
            if (postfixSym == '^') 
            {
                result = pow(operand1, operand2);
            } 
            else if (postfixSym == '*')
            {
                result = operand1 * operand2;                
            } 
            else if (postfixSym == '/')
            {
                result = operand1 / operand2;
            } 
            else if (postfixSym == '+')
            {
                result = operand1 + operand2;
            } 
            else if (postfixSym == '-')
            {
                result = operand1 - operand2; 
            }
            // Pushing result to stack
            pushLong(result);
        }
        i++;
    }
    // Popping final result from stack
    finalResult = popLong();
    return finalResult;
}

//______________Main Method______________
int main (void)
{
    // Defining infix and postfix char arrays
    char infixExpression[SIZEMAX];
    char postfixExpression[SIZEMAX];
    long resultPostfix;
    
    nodeStr* headInfix = (nodeStr *) malloc(sizeof(nodeStr));
    if (headInfix == NULL) {
        return 1;
    }

    nodeStr* head = (nodeStr *) malloc(sizeof(nodeStr));
    if (head == NULL) {
        return 1;
    }

    nodeChar* headOperand = (nodeChar *) malloc(sizeof(nodeChar));
    if (headOperand == NULL) {
        return 1;
    }
    strcpy(head->val, "head");
    head->next = NULL;

    
    // Printing and scanning for infix input
    printf("Enter infix expression:\n");
    scanf("%s", infixExpression);
    infixStringToStack(infixExpression, headInfix, headOperand);
    //infixToPostfix(infixExpression, postfixExpression, head);
    printf("Postfix expression: %s\n", postfixExpression);
    //resultPostfix = postfixEval(postfixExpression);
    printf("Result = %ld\n", resultPostfix);
    
    return 0;
}