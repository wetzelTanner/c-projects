/**********************************************
File: integral.c
Author: Tanner Wetzel
Date: 3/25/2023
Description: A file to define handle input validation and output of user calculation
***********************************************/

#include <stdio.h>
#include <ctype.h>
#include "functions.h"

int main() {
    double low, high;	  // Input command
    int numT;             // number of trapezoids
    int nVals;            // # values read
    char cmd;             // user input, either y or n

    do {
        // loop to handle endpoint validation 
        do{
            printf("Enter endpoints of interval to be integrated (low hi): ");
            nVals = scanf("%lf %lf", &low, &high);
            if(nVals != 2){
                printf("Error: incorrectly formatted input\n\n");
            }
            else if(low > high){
                printf("Error: low must be < hi\n\n");
            }
            badInput();
        } while(nVals != 2 || low > high);

        // loop to handle number of trapzoid validation
        do{
            printf("Enter number of trapezoids to be used: ");
            nVals = scanf("%d", &numT);
            if(nVals != 1){
                printf("Error: Improperly formatted input\n\n");
            }
            else if(numT < 1){
                printf("Error: num must be >= 1\n\n");
            }
            badInput();
        } while(nVals != 1 || numT < 1);

        // print out the integral approximation calulated from the user input
        printf("Using %d trapezoids, integral between %lf and %lf is %lf\n\n", numT, low, high, integrate(low, high, numT));

        // loop to handle the Yes or No validation
        do{
            printf("Evaluate another interval (Y/N)? ");
            nVals = scanf("%c", &cmd);
            cmd = tolower(cmd);
            if(nVals != 1){
                printf("Error: must enter Y or N\n\n");
            }
            else if(cmd != 'y' && cmd != 'n'){
                printf("Error: must enter Y or N\n\n");
            }
            badInput();
        } while(nVals != 1 || (cmd != 'y' && cmd != 'n'));

    } while(cmd != 'n');
    
    return 0;
}