#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265 // Defining constant pi

double mag(double vecX, double vecY)
{
  double mag; // Magnitude of vector
  mag = sqrt((pow(vecX, 2)) + (pow(vecY, 2)));
  return mag;
}

double eField(double ptCharge, double x, double y, double* eFieldX, double* eFieldY)
{
  double r = mag(x, y);
  double rHatX = x/r;
  double rHatY = y/r;
  double k = 8.99 * pow(10, 9); // Defining k as 8.99e9
  double eFieldMag; // Magnitude of electric field
  *eFieldX = k * ((ptCharge) / (pow(r, 2))) * rHatX;
  *eFieldY = k * ((ptCharge) / (pow(r, 2))) * rHatY;
  eFieldMag = mag(*eFieldX, *eFieldY);
  return eFieldMag;
}

int main (void)
{
  double eFieldX;
  double eFieldY;
  double eFieldMag;
  double ptCharge = 0.6;
  double x = 20;
  double y = 50;
  eFieldMag = eField(ptCharge, x, y, &eFieldX, &eFieldY);
  printf("eFieldMag: %lf, eFieldX: %lf, eFieldY %lf\n", eFieldMag, eFieldX, eFieldY);
}
