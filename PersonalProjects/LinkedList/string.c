#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRSIZE 10

int main (void)
{
    int strInt;
    char str[STRSIZE] = "1234";
    char strRev[STRSIZE];
    for (int i; i < strlen(str); i++)
    {
        printf("%c\n", str[i]);
    }
    return 0;
}