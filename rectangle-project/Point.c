/*
 *  EGR/CS 222: Systems Programming
 *  Point.c
 *  Author: Tanner Wetzel
 *  Purpose: The function definitions for
 *           Point related functions
 */
#include "Point.h"
#include <stdio.h>
#include <math.h>

// Print coordinates as (x.xx, y.yy)
void printPoint(Point *p) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    printf("(%.2lf, %.2lf)", p->x, p->y); 
}

// Read input coordinates
void readPoint(Point *p) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    scanf(" %lf %lf", &(p->x), &(p->y));
}

// Return distance between two points
double dist(Point *p1, Point *p2) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}
