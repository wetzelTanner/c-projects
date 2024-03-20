/*
 *  EGR/CS 222: Systems Programming
 *  Main.c
 *  Author: Tanner Wetzel
 *  Purpose: The main file for Project 3
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Rectangle.h"      // Includes "Point.h" as well
#define HELP_MSG "Available commands: add, print, dimension, overlap, quit.\n"
char *readCmd();            // readCmd() helper function prototype

int main(int argc, char * argv[]) {
    Rectangle rlist[10];    // Array containing up to 10 rectangles
    int nRect = 0;          // Number of rectangles
    char* cmd;              // String command
    int ind, ind2;          // Loop index
    int flag;               // Flag to simplify conditionals
    char junk;              // Used to clear input
    
    // command line parsing
    if(argc == 2){
        if(strcmp(argv[1], "-h")==0){
            printf(HELP_MSG);
            exit(0);
        }
        else{
            printf("Incorrect command line argument!\n");
            exit(0);
        }
    }
    else if(argc > 2){
        printf("Too many command line arguments!\n");
        exit(0);
    }


    // Loop to check and execute the user's command
    //   Only breaks out when receives "exit"
    do {
        // Prompt user to enter a string command
        printf("\nEnter command: ");
        // Read string from standard input with readCmd() function
        cmd = readCmd();

        // Add points to create rectangle
        if (strcmp(cmd, "add") == 0) {
            printf("Enter coordinates as x y, starting with lower left corner: \n");
            readPoint(&(rlist[nRect].vert[0]));
            readPoint(&(rlist[nRect].vert[1]));
            readPoint(&(rlist[nRect].vert[2]));
            readPoint(&(rlist[nRect].vert[3]));
            // increment number of rectangles
            nRect++;
            do{scanf("%c", &junk);}while(junk != '\n');
        }

        // Print rectangle list
        else if (strcmp(cmd, "print") == 0) {
            if(nRect == 0){
                printf("No rectangles in list\n");
            }
            else{
                printList(rlist, nRect);
            }
        }

        // print dimensions of selected rectangle
        else if (strcmp(cmd, "dimension") == 0) {
            printf("Enter index into array: ");
            scanf(" %d", &flag); 
            printf("Area of rectangle %d: %.2lf\n", flag, area(&rlist[flag]));
            printf("Perimeter of rectangle %d: %.2lf\n", flag, perimeter(&rlist[flag]));
            do{scanf("%c", &junk);}while(junk != '\n');
        }

        // print if the rectangles overlap or not
        else if (strcmp(cmd, "overlap") == 0) {
            printf("Enter indices to test: ");
            scanf(" %d %d", &ind, &ind2);
            if(overlap(&rlist[ind], &rlist[ind2]) == 1){
                printf("Rectangles %d and %d overlap\n", ind, ind2);
            }
            else{
                printf("Rectangles %d and %d do not overlap\n", ind, ind2);
            }
            do{scanf("%c", &junk);}while(junk != '\n');
        }

        // Invalid command
        else if (strcmp(cmd, "quit") != 0) {
            printf("Invalid command %s\n", cmd);
        }
    } while (strcmp(cmd, "quit") != 0);
    free(cmd);
    return 0;
}

// Reads string from standard input and dynamically allocates space
// Assumes user input string terminates with '\n'
char *readCmd() {
    int  i = 0;         // Loop index
    char *inStr;        // Input string
    char *tempStr;      // Temp string
    char inCh;          // Input character

    // Start with 1-character string
    inStr = (char *)malloc(sizeof(char));
    	
    // Allocation failure safeguard
    if (inStr == NULL) {
        fprintf(stderr, "Could not allocate\n");
        return NULL;
    }

    // Repeatedly read input characters and reallocate space to store string
    while ((inCh = fgetc(stdin)) != '\n') {
        tempStr = (char *)realloc(inStr, (i + 2) * sizeof(char));

        // Reallocation failure safeguard
        if (tempStr == NULL) {
            fprintf(stderr, "Could not reallocate\n");
            return inStr;
        }
        // Reallocation successful
        else {
            inStr = tempStr;
            inStr[i++] = inCh;
        }
    } 

    // Properly NULL-terminate the string
    inStr[i] = '\0';

    return inStr;
}