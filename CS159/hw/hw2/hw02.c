/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. subbiah@purdue.edu
*
*  Homework 2:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Feb 9th, 3:08PM, HILL 330w:
*
*  Program Description:
*  This program will take user input for whether the observer is stationary
*  or travelling and print out the observed frequency of a moving ambulance
*  based on the speed of the vehicles.
*
***************************************************************************/

#include <stdio.h>
#include<stdlib.h>

int main (void) 
{
  // Defining Variables
  double mph; // Mph of the vehicles
  double emergencyMs; // M/s of the emergency vehicle
  double secondMs; // M/s of the second vehicle
  double sirenFreq; // Integer of siren frequency in Hz
  char input; // Character for input
  double apprFreq; // Double of the approach frequency in Hz
  double awayFreq; // Double of the away frequency in Hz
  double mphToMs = 0.447; // Double of ratio of mph to m/s
  int vSoundAirMs = 345; // Integer of the speed of sound in air
  float inputS; // Float for input stationary
  float inputT; // Float for input Travelling

  // Recieving Input From User
  printf("Enter whether observer is (S)tationary or (T)raveling -> ");
  scanf("%c", &input);
  printf("Enter speed [miles/hr] of vehicle(s) -> ");
  scanf("%lf", &mph);
  printf("Enter frequency [Hz] of siren -> ");
  scanf("%lf", &sirenFreq);
  printf("\n");
  
  // Calculations
  inputS = abs((float)input - 84); // User input for mass
  inputT = abs((float)input - 83); // User input for velocity
  emergencyMs = mphToMs * mph; // Calculating emergency m/s
  secondMs = inputT * (mphToMs * mph); // Setting vehicle m/s to value or 0 if stationary
  apprFreq = sirenFreq * ((vSoundAirMs + secondMs) / (vSoundAirMs - emergencyMs));
  awayFreq = sirenFreq * ((vSoundAirMs - secondMs) / (vSoundAirMs + emergencyMs));

  // Output
  printf("Observed frequency during approach: %.1lf Hz\n", apprFreq);
  printf("Observed frequency moving away: %.1lf Hz\n", awayFreq);
  
  return 0;
}