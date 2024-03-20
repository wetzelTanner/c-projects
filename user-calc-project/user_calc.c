/*
Author: Tanner Wetzel
Date: 2/12/2023
Description: A program that will take a user calculation and 
             output the result
*/
#include <stdio.h>

int main(void){
    //declare variables
    int prec;
    double v1,v2, result;
    char op;

    //retrieve user input for precision
    printf("Enter precision: ");
    scanf("%d", &prec);

    //print an error and exit if precision variable is negative 
    if(prec < 0){
        printf("Error: negative precision\n");
        return 0;
    }

    //retrieve user inputs for variables
    printf("Enter expression: ");
    int nVals = scanf("%lf %c %lf", &v1, &op, &v2);

    //print an error if user tries to divide by 0
    if(op == '/' && v2 == 0){
        printf("Error: cannot divide by zero\n");
        return 0;
    }

    //print an error and exit if input was formatted incorrectly
    if(nVals < 3){
        printf("Error: incorrectly formatted input\n");
        return 0;
    } 

    //calculate the result based on which operand was used
    switch(op){
        case '+':
            result = v1 + v2;
            break;
        case '-':
            result = v1 - v2;
            break;
        case '*':
            result = v1 * v2;
            break;
        case '/':
            result = v1 / v2;
            break;
        //print an error and exit if op is not one of the stated cases
        default:
            printf("Error: invalid operator %c\n", op);
            return 0;
    }

    //print the result of the calculation with the specified precision
    printf("%.*lf %c %.*lf = %.*lf\n", prec, v1, op, prec, v2, prec, result);

    return 0;
}