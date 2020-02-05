/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. subbiah@purdue.edu
*
*  Homework 1:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Jan 23rd, 10:58 AM, ARMS B098:
*
*  Program Description:
*  The program recieves input for the speed of an emergency vehicle and a
*  second vehicle in miles per hour and calculates and outputs the approach
*  and moving away frequencies generated.
*
***************************************************************************/

#include <stdio.h>

int main (void) 
{
    // Defining Variables
    double emergencyMph; // Double of emergency vehicle miles per hour
    double secondMph; // Double of second vehicle miles per hour
    double emergencyMs; // Double of emergency vehicle meters per second
    double secondMs; // Double of second vehicle meters per second
    int sirenFreq = 400; // Integer of siren frequency in Hz
    double apprFreq; // Double of the approach frequency in Hz
    double awayFreq; // Double of the away frequency in Hz
    double mphToMs = 0.447; // Double of ratio of mph to m/s
    int vSoundAirMs = 345; // Integer of the speed of sound in air

    // Recieving Input From User
    printf("Enter speed [miles/hr] of emergency vehicle -> ");
    scanf("%lf", &emergencyMph);
    printf("Enter speed [miles/hr] of second vehicle -> ");
    scanf("%lf", &secondMph);
    printf("\n");

    // Calculations
    emergencyMs = mphToMs * emergencyMph;
    secondMs = mphToMs * secondMph;
    apprFreq = sirenFreq * ((vSoundAirMs + secondMs) / (vSoundAirMs - emergencyMs));
    awayFreq = sirenFreq * ((vSoundAirMs - secondMs) / (vSoundAirMs + emergencyMs));

    // Output
    printf("Observed frequency during approach: %.1lf Hz\n", apprFreq);
    printf("Observed frequency moving away: %.1lf Hz\n", awayFreq);
    return 0;
}