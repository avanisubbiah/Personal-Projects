/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. Avanish Subbiah, subbiah@purdue.edu
*  2. Patrick Dean, deanp@purdue.edu
*  3. Micheal Hall, hall529@purdue.edu
*
*  Lab 1:
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Jan 21st, 3:30PM , SC G073:
*
*  Program Description:
*  This program takes two x and y coordinates and outputs the perpendicular
*  bisector of the two sets of x, y coordinates.
*
***************************************************************************/

#include <stdio.h>

int main (void)
{
    // Declaring Local Variables
    float x1; // First x Coordinate
    float x2; // Second x Coordinate
    float y1; // First y Coordinate
    float y2; // Second y Coordinate
    float midX; // Midpoint of X
    float midY; // Midpoint of Y
    float slopeCoor; // Slope of the X/Y Coordinates
    float slopeBis; // Slope of the Bisector
    float b; // Y-intercept of the Bisector

    // Getting input for Coordinates
    printf("Enter the first x coordinate -> ");
    scanf("%f", &x1);
    printf("Enter the first y coordinate -> ");
    scanf("%f", &y1);
    printf("Enter the second x coordinate -> ");
    scanf("%f", &x2);
    printf("Enter the second y coordinate -> ");
    scanf("%f", &y2);
    printf("\n");

    // Calculating the midpoint of x and y coordinates
    midX = (x1 + x2) / 2;
    midY = (y1 + y2) / 2;

    // Calculating the slope of the two points and the bisector
    slopeCoor = (y2 - y1) / (x2 - x1);
    slopeBis = -1 / slopeCoor;

    // Calculating Y-intercept
    b = midY - (slopeBis * midX);

    // Printing the Equation of the Bisector
    printf("Original endpoints: [%0.1f, %0.1f] and [%0.1f, %0.1f]\n", x1, y1, x2, y2);
    printf("Equation of the perpendicular bisector: y = %0.2fx + %0.2f\n", slopeBis, b);
    
    return 0;
}