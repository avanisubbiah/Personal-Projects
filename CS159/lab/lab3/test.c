#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int selection = 1;
    double mass = 2*(abs(selection - 2));
    double velocity = 3*(abs(selection - 1));
    printf("%f", mass+velocity);
    return 0;
}