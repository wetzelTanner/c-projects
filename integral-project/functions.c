/**********************************************
File: functions.c
Author: Tanner Wetzel
Date: 3/25/2023
Description: A file to define the integration functions used in integral.c
***********************************************/

#include <stdio.h>
#include <math.h>
#include "functions.h"

// Calculate integral of f(x) over interval min to max, using n trapezoids
double integrate(double min, double max, int n) {
    int i;
    double area = 0;
    double deltaX = fabs((max - min))/n;
    double y1 = min, y2 = min + deltaX;

    for(i = 0; i < n; i++){
        area += (0.5) * (deltaX) * (f(y1) + f(y2));
        y1 += deltaX;
        y2 += deltaX; 
    }

    return area;
}

// f(x) as defined in the specification
double f(double x) {
    return (cos(pow(x,2)) + ((pow(x,3) - (2 * pow(x,2))) / 10));
}

// Used to clear line if input formatting error occurs
void badInput(void) {
    char junk;
    do{scanf("%c", &junk);
    }while(junk != '\n');
}