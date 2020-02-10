/***************************************************************************
 *
 *  Programmers and Purdue Email Addresses:
 *  1. deanp@purdue.edu
 *  2. subbiah@purdue.edu
 *  3. hall529@purdue.edu
 *
 *  Lab 02:
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Tuesday, 3:30, SC G073:
 *
 *  Program Description:
 *  It allows users to input data regarding a suspended block and string.
 *  It then calculates different values based on the input data. 
 *
 ***************************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define GRAV 9.8

int main (void) 
{

  //Local Declarations
  float input; //user selection for mass of string or velocity of wave
  float inputM; //variable for user input in mass
  float inputV; //variable for user input in velocity
  float m; //mass of the string
  float string; //length of string
  float m2; //mass of maintaining tension
  float f; //force of mass and gravity
  float mass_per_length; //mass of string per unit length
  float v; //velocity of wave generated
  float time; //time to travel string length
  float mOrV; //mOrV unkown variable
  float valCalc; //calculated value based on input
  
  //Executable Declarations

  //These printf and scanf statements allow the user to input their values
  printf("Enter length of string (m) -> ");
  scanf("%f", &string);
  printf("Enter mass of the block maintaining tension (kg) -> ");
  scanf("%f", &m2);
  printf("\n1. Enter string mass\n2. Enter velocity of wave\n\n");
  
  printf("Make your selection -> ");
  scanf("%f", &input);
  printf("Enter value for selection -> ");
  scanf("%f", &mOrV);
  printf("\n");

  f = GRAV * m2; //force of gravity
  inputM = abs(input - 2); // User input for mass
  inputV = abs(input - 1); // User input for velocity
  
  valCalc = (inputM * (pow((f / (mOrV / string)), 0.5))) + (inputV * ((f * string) / pow(mOrV,2))); // Calculating other variable (m or v) based on input
  m = (inputM * mOrV) + (inputV * valCalc); // Setting mass
  v = (inputV * mOrV) + (inputM * valCalc); // Setting velocity
  mass_per_length = m / string; // Calculating mass_per_length
  time = (string - 1) / v; //calculates the time to travel string length

  //These printf commands print out the calculated values
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Mass of string: %10.1f (kg)\n", m);
  printf("Length of string: %9.1f (m)\n", string);
  printf("Mass of block: %11.1f (kg)\n", m2);
  
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Force of tension: %8.1f (kg)\n", f);
  printf("Mass per unit of length: %14.3f (m)\n", mass_per_length);
  printf("Velocity of wave generated: %9.1f (m\\s)\n", v);
  printf("Time to travel string length: %9.3f (s)\n", time);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;

}