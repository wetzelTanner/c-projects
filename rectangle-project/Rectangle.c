/*
 *  EGR/CS 222: Systems Programming
 *  Rectangle.c
 *  Author: Tanner Wetzel
 *  Purpose: The function definitions for
 *           Rectangle related functions
 */

#include "Rectangle.h"        // Implicitly includes Point.h
#include <stdio.h>
#include <math.h>

// Print contents of rectangle
// Prints vertices in appropriate relative positions:
//   vert[1]   vert[2]
//   vert[0]   vert[3]
void printRectangle(Rectangle *r) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    printPoint(&(r->vert[1])); printf("\t"); printPoint(&(r->vert[2]));
    printf("\n");
    printPoint(&(r->vert[0])); printf("\t"); printPoint(&(r->vert[3]));
    printf("\n");
}

// Print list of n Rectangles
void printList(Rectangle list[], int n) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    int i;
    for(i=0; i<n; i++){
        printRectangle(&list[i]);
        printf("\n");
    }
}

// Returns area of rectangle
double area(Rectangle *r) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    double width = dist(&(r->vert[0]), &(r->vert[3]));
    double height = dist(&(r->vert[0]), &(r->vert[1]));
    return width * height;
}

// Returns perimeter of rectangle
double perimeter(Rectangle *r) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    double width = dist(&(r->vert[0]), &(r->vert[3]));
    double height = dist(&(r->vert[0]), &(r->vert[1]));
    return 2 * (width + height);
}

// Returns 1 if two rectangles overlap; 0 otherwise
int overlap(Rectangle *r1, Rectangle *r2) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    double x_left = fmax(r1->vert[0].x, r2->vert[0].x);
    double y_bottom = fmax(r1->vert[0].y, r2->vert[0].y);
    double x_right = fmin(r1->vert[2].x, r2->vert[2].x);
    double y_top = fmin(r1->vert[2].y, r2->vert[2].y);

    // If the two rectangles don't overlap, return 0
    if (x_left >= x_right || y_bottom >= y_top) {
        return 0;
    }
    return 1;
}