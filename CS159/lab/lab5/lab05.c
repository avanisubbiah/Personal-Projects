/***************************************************************************
 *
 *  Programmers and Purdue Email Addresses:
 *  1. 
 *  2. subbiah@purdue.edu
 *  3. nbanjurt@purdue.edu
 *
 *  Lab 05:
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Feb 18th, 3:30, SC G073:
 *
 *  Program Description:
 *  The program takes the charge of 3 point charges and calculates the resultant
 *  force on the point charge at the origin.
 *
 ***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265 // Defining constant pi

// Defining functions for later
double eField(double ptCharge, double x, double y, double* eFieldX, double* eFieldY);
double mag(double vecX, double vecY);
double angle(double vecX, double vecY);

double convUnitCToB(double c);
double convUnitMuToB(double Mu);
double convEFieldToForce(double obsCharge, double eFieldX, double eFieldY, double* fX, double* fY);
double forceSum(double fX1, double fY1, double fX2, double fY2, double* fNetX, double* fNetY);

int main (void)
{
  double charge1; // Coulombic charge of charge 1 (micro C)
  double charge2; // Coulombic charge of charge 2 (micro C)
  double charge3; // Coulombic charge of charge 3 (micro C)

  double charge2X; // x value of charge 2 (cm)
  double charge2Y; // y value of charge 2 (cm)
  double charge3X; // x value of charge 3 (cm)
  double charge3Y; // y value of charge 3 (cm)

  double fNetX; // Net force vector x comp (N)
  double fNetY; // Net force vector y comp (N)
  double fNetMag; // Magnitude of the net force (N)
  double fNetAngle; // Angle of the net force degrees

  double eC2OnC1; // Electric field magnitude of charge 2 on 1 (N/C)
  double eC2OnC1X; // Electric field X of charge 2 on 1 (N/C)
  double eC2OnC1Y; // Electric field Y of charge 2 on 1 (N/C)
  double eC3OnC1; // Electric field magnitude of charge 3 on 1 (N/C)
  double eC3OnC1X; // Electric field X of charge 2 on 1 (N/C)
  double eC3OnC1Y; // Electric field Y of charge 2 on 1 (N/C)

  double fC2OnC1; // Force of charge 2 on 1 (N)
  double fC2OnC1X; // Force x comp of charge 2 on 1 (N)
  double fC2OnC1Y; // Force y comp of charge 2 on 1 (N)
  double fC3OnC1; // Force of charge 3 on 1 (N)
  double fC3OnC1X; // Force x comp of charge 3 on 1 (N)
  double fC3OnC1Y; // Force y comp of charge 3 on 1 (N)

  // Recieving input from user for charges 
  printf("Enter charge [micro-Coulomb] of point #1 -> ");
  scanf("%lf", &charge1);
  printf("Enter charge [micro-Coulomb] of point #2 -> ");
  scanf("%lf", &charge2);
  printf("Enter charge [micro-Coulomb] of point #3 -> ");
  scanf("%lf", &charge3);

  // Recieving input for y and x coordinates of charge 2 and 3
  printf("Enter X coordinate [cm] of point #2 -> ");
  scanf("%lf", &charge2X);
  printf("Enter Y coordinate [cm] of point #2 -> ");
  scanf("%lf", &charge2Y);
  printf("Enter X coordinate [cm] of point #3 -> ");
  scanf("%lf", &charge3X);
  printf("Enter Y coordinate [cm] of point #3 -> ");
  scanf("%lf", &charge3Y);
  printf("\n");

  // Converting micro coulombs to coulombs
  charge1 = convUnitMuToB(charge1);
  charge2 = convUnitMuToB(charge2);
  charge3 = convUnitMuToB(charge3);
  // Converting cm to m
  charge2X = convUnitCToB(charge2X);
  charge2Y = convUnitCToB(charge2Y);
  charge3X = convUnitCToB(charge3X);
  charge3Y = convUnitCToB(charge3Y);

  // Calculating electric fields and forces from charge 2 and 3
  eC2OnC1 = eField(charge2, charge2X, charge2Y, &eC2OnC1X, &eC2OnC1Y);
  eC3OnC1 = eField(charge3, charge3X, charge3Y, &eC3OnC1X, &eC3OnC1Y);
  fC2OnC1 = convEFieldToForce(charge1, eC2OnC1X, eC2OnC1Y, &fC2OnC1X, &fC2OnC1Y);
  fC3OnC1 = convEFieldToForce(charge1, eC3OnC1X, eC3OnC1Y, &fC3OnC1X, &fC3OnC1Y);
  
  // Finding net force vector and its magnitude and angle
  fNetMag = forceSum(fC2OnC1X, fC2OnC1Y, fC3OnC1X, fC3OnC1Y, &fNetX, &fNetY);
  fNetAngle = angle(fNetX, fNetY);
// Outputing net force magnitude and angle with the x-axis
  printf("Magnitude of the resultant force on the charge at the origin: %.1f N\n", fNetMag);
  printf("Force vector angle with the x-axis: %.1f degrees\n", fNetAngle);
  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*  eField (Electric Field by Point Charge Calculator)
*
*  Function Return Type:
*  double
*  
*  Parameters (list data type, name, and comment one per line):
*    1. double ptCharge (point charge coulombs)
*    2. double x (distance x from reference point)
*    3. double y (distance y from reference point)
*    4. double* eFieldX (address of electric field x comp)
*    5. double* eFieldY (address of electric field y comp)
*
*  Function Description:
*  This function takes a point charge value in coulombs and its distance from
*  its reference point and returns the magnitude of the electric field and
*  passes the x and y components of said electric field by address.
*
***************************************************************************/
double eField(double ptCharge, double x, double y, double* eFieldX, double* eFieldY)
{
  double r = mag(x, y); // Defining r as the magnitude of x and y
  double rHatX = x/r; // Defining rHatX component as x divided by r
  double rHatY = y/r; // Defining rHatY component as y divided by r
  double k = 8.99 * pow(10, 9); // Defining k as 8.99e9
  double eFieldMag; // Magnitude of electric field

  *eFieldX = k * ((ptCharge) / (pow(r, 2))) * rHatX;
  *eFieldY = k * ((ptCharge) / (pow(r, 2))) * rHatY;
  eFieldMag = mag(*eFieldX, *eFieldY);
  return eFieldMag;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*  mag (2D Vector Magnitude Calculator)
*
*  Function Return Type:
*  double  
*
*  Parameters (list data type, name, and comment one per line):
*    1. double vec[2] (vector of size 2 to have x and y coords)
*
*  Function Description:
*  This function calculates the magnitude of a vector with x and y coords.
*
***************************************************************************/
double mag(double vecX, double vecY)
{
  double mag; // Magnitude of vector
  mag = sqrt((pow(vecX, 2)) + (pow(vecY, 2)));
  return mag;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*  angle (Vector Angle Calculator)
*
*  Function Return Type:
*  double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double vecX (vector X Coordinate)
*    2. double vecY (vector Y Coordinate)
*
*  Function Description:
*  This function returns the angle between a vector with x and y coords.
*
***************************************************************************/
double angle(double vecX, double vecY)
{
  double angle; // Angle of vector by x-axis
  angle = (atan(vecY / vecX) * 180) / PI; // Finding the angle of vector by x-axis
  return angle;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*  convUnitCToB (Unit Convertion from Centi to Base)
*
*  Function Return Type:
*  double   
*
*  Parameters (list data type, name, and comment one per line):
*    1. double c (The value of the centi unit)
*
*  Function Description:
*  This function converts a given centi unit to base.
*
***************************************************************************/
double convUnitCToB(double c)
{
  double b; // Base unit
  b = c * pow(10, -2);
  return b;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*  convUnitMuToB (Unit Converstion from Micro to Base)
*
*  Function Return Type:
*  double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double Mu (Input unit in micro)
*
*  Function Description:
*  This function converts units from micro to base.
*
***************************************************************************/
double convUnitMuToB(double Mu)
{
  double b; // Base unit
  b = Mu * pow(10, -6);
  return b;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*  convEFieldToForce (Finding Force From Electric Field)
*
*  Function Return Type:
*  double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double obsCharge (Observation Charge in Coulombs)
*    2. double eFieldX (Electric Field x comp in Newtons Per Coulomb)
*    3. double eFieldY (Electric Field y comp in Newtons Per Coulomb)
*    4. double* fX (Address of force x comp)
*    5. double* fY (Address of force y comp)
*
*  Function Description:
*  This function takes the electric field and observation charge given and
*  calculates the force applied by said electric field. It returns the
*  x and y components of said force by address.
*
***************************************************************************/
double convEFieldToForce(double obsCharge, double eFieldX, double eFieldY, double* fX, double* fY)
{
  double fMag; // Value of the magnitude of the force from the electric field (N)
  *fX = eFieldX * obsCharge;
  *fY = eFieldY * obsCharge;
  fMag = mag(*fX, *fY);
  return fMag;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*  forceSum (summation of two force vectors)
*
*  Function Return Type:
*  double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double fX1 (Force x1 comp)
*    2. double fY1 (Force y1 comp)
*    3. double fX2 (Force x2 comp)
*    4. double fY2 (Force y2 comp)
*    5. double* fNetX (Address of force net x comp)
*    6. double* fNetY (Address of force net y comp)
*
*  Function Description:
*  This function takes two force vectors and returns the magnitude of the
*  resulting net force and passes the x and y components of the force vector
*  by address.
*
***************************************************************************/
double forceSum(double fX1, double fY1, double fX2, double fY2, double* fNetX, double* fNetY)
{
  double fNetMag; // Magnitude of the net force (N)
  *fNetX = fX1 + fX2;
  *fNetY = fY1 + fY2;
  fNetMag = mag(*fNetX, *fNetY);
  return fNetMag;
}
