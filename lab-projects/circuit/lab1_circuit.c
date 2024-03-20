/*
Author: Tanner Wetzel
Date: 2/3/2023
Description: A program that will take a user input for a voltage
             value and three resistance values and output three 
             different calculations
*/
#include <stdio.h>

int main(void){
    //declare variables and collect user input
    double vSource, R1, R2, R3;
    printf("Enter voltage source value(V): ");
    scanf("%lf", &vSource);
    
    printf("Enter three resistance values(ohms): ");
    scanf("%lf %lf %lf", &R1, &R2, &R3);

    //do calculations for series circuit and print results
    double sCurr, sRes, V1, V2, V3;
    sRes = R1 + R2 + R3;
    sCurr = vSource/sRes;
    V1 = sCurr * R1;
    V2 = sCurr * R2;
    V3 = sCurr * R3;

    printf("\nSERIES CIRCUIT\n");
    printf("Current through circuit: %lf A\n", sCurr);
    printf("Voltage across R1: %lf V\n", V1);
    printf("Voltage across R2: %lf V\n", V2);
    printf("Voltage across R3: %lf V\n", V3);

    //do calculations for parallel circuit and print results
    double C1, C2, C3;
    C1 = vSource/R1;
    C2 = vSource/R2;
    C3 = vSource/R3;

    printf("\nPARALLEL CIRCUIT\n");
    printf("Voltage across each resistor: %lf V\n", vSource);
    printf("Current through R1: %lf A\n", C1);
    printf("Current through R2: %lf A\n", C2);
    printf("Current through R3: %lf A\n", C3);

    //do calculations for R2 & R3 in parallel circuit and print results
    double I, veff, v1, cur1, v2, cur2, v3, cur3;
    I = vSource/(R1+((R2*R3)/(R2+R3)));
    veff = I * ((R2*R3)/(R2+R3));
    v1 = I * R1;
    v2 = v3 = veff;
    cur1 = I;
    cur2 = veff/R2;
    cur3 = veff/R3;

    printf("\nR2 & R3 IN PARALLEL\n");
    printf("Voltage across R1: %lf V\n", v1);
    printf("Current through R1: %lf A\n", cur1);
    printf("Voltage across R2: %lf V\n", v2);
    printf("Current through R2: %lf A\n", cur2);
    printf("Voltage across R3: %lf V\n", v3);
    printf("Current through R3: %lf A\n", cur3);
}