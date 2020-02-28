
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. login@purdue.edu
*
*  Homework #:4
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:
*
*  Program Description:
*
***************************************************************************/
//global declarations
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void in(double *angle1, double *angle2, double *angle3, double *dist1, double *dist2, double *dist3);
void angle(double *angle1, double *angle2, double *angle3, double dist1, double dist2, double dist3);
double lawOfSinsAngle(double angle1, double dist1, double dist2);
void leg(double *angle1, double *angle2, double *angle3, double *dist1, double *dist2, double *dist3);
double lawOfSinsLeg(double angle1, double angle2, double dist1);

int main()
{
  //local declarations
  double angle1;
  double angle2;
  double angle3;
  double dist1;
  double dist2;
  double dist3;

  //executable statements
    in(&angle1,&angle2,&angle3,&dist1,&dist2,&dist3);
    angle(&angle1,&angle2,&angle3,dist1,dist2,dist3);
    printf("%lf",angle1);
    printf("%lf",angle2);
    printf("%lf",angle3);
return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:in
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double *angle1
*    2.double *angle2
*    3.double *angle3
*    4.double *dist1
*    5.double *dist2
*    6.double *dist3
*
*  Function Description:
*
***************************************************************************/
void in(double *angle1, double *angle2, double *angle3, double *dist1, double *dist2, double *dist3)
{
  //executable statements
  printf("\nEnter angle measurements [degrees] -> ");
  scanf("%lf %lf %lf", angle1, angle2, angle3);
  *angle1 *= (M_PI / 180);
  *angle2 *= (M_PI / 180);
  *angle3 *= (M_PI / 180);
  printf("\nEnter side lengths [cm] -> ");
  scanf("%lf %lf %lf",dist1, dist2, dist3);
return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: angle
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1
*    2.double angle2
*    3.double angle3
*    4.double dist1
*    5.double dist2
*    6.double dist3
*
*  Function Description:
*
***************************************************************************/
void angle(double *angle1, double *angle2, double *angle3, double dist1, double dist2, double dist3)
{
  //local declarations
  //executable statements
  if ((*angle1 && *angle2) || (*angle1 && *angle3) || (*angle2 && *angle3))
  {
    if (!*angle1)
    {
      *angle1 = M_PI - *angle2 - *angle3;
    }
    else if(!*angle2)
    {
      *angle2 = M_PI - *angle1 - *angle3;
    }
    else if(!*angle3)
    {
      *angle3 = M_PI - *angle1 - *angle2;
    }
    else
    {
      if(*angle1)
      {
        if(dist2)
        {
          *angle2 = lawOfSinsAngle(double *angle1, double dist1, double dist2);
        }
        else if(dist3)
        {
          *angle3 = lawOfSinsAngle(double *angle1, double dist1, double dist3);
        }  
      }
      else if(angle2)
      {
        if(dist1)
        {
          *angle1 = lawOfSinsAngle(double *angle2, double dist2, double dist1);
        }
        else
          *angle3 = lawOfSinsAngle(double *angle2, double dist2, double dist3);
      }
      else
      {
        if(dist1)
        {
          *angle1 = lawOfSinsAngle(double *angle3, double dist3, double dist1);
        }
        else
        {
          *angle2 = lawOfSinsAngle(double *angle3, double dist3, double dist2);
        }
      }
    }
  }
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: angle
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1
*    2.double angle2
*    3.double angle3
*    4.double dist1
*    5.double dist2
*    6.double dist3
*
*  Function Description:
*
***************************************************************************/
void leg(double *angle1, double *angle2, double *angle3, double *dist1, double *dist2, double *dist3)
{
  //local declarations
  //executable statements
  if ((dist1 && dist2) || (dist1 && dist3) || (dist2 && dist3))
  {
    
    }
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: lawofSinsLeg
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double *angle1
*    2.double *angle2
*    3.double *dist1
*
*  Function Description:
*
***************************************************************************/
double lawOfSinsLeg(double angle1, double angle2, double dist1)
{
  //local declarations
  double dist2;
  //executable statements
  dist2 = (dist1 / sin(angle1)) * sin(angle2);
  return (dist2);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: lawofSinsAngle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1
*    2.double dist1
*    3.double dist2
*
*  Function Description:
*
***************************************************************************/
double lawOfSinsAngle(double angle1, double dist1, double dist2)
{
  //local declarations
  double angle2;
  //executable statements
  angle2 = (dist1 / sin(angle1)) / dist2;
  return (angle2);

}