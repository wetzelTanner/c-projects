/**********************************************
    EGR/CS 222: Systems Programming
    Author: Tanner Wetzel
    Header file for the integral project
    Tests ability to write and use functions
 ***********************************************/

// Lines used for conditional compilation
// ensures header isn't included multiple times
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Calculate integral of f(x) over interval min to max, using n trapezoids
double integrate(double min, double max, int n);

// f(x) as defined in the specification
double f(double x);

// Used to clear line if input formatting error occurs
void badInput(void);

#endif /* More conditional compilation--end of proj1_functions_h */