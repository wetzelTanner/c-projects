/*****************************************************
    EGR/CS 222 Systems Programming
    
    Main program for demo: Dynamic memory allocation
    and data structures

    Works with singly linked list, which is defined
    in separate file
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LLnode.h"  // Contains LLNode definition, function prototypes

/*** U T I L I T Y   F U N C T I O N ***/
char *readLine();    // Reads string from input and dynamically allocates space

int main(void) {
    LLnode * first = NULL;     // Pointer to start of list
    LLnode * temp;
    char   * cmd   = NULL;     // Input command
    int      inVal;            // Input value
    char     junk;             // Used to hold newline

    do {
        printf("\nEnter command:  ");
        cmd = readLine();      // Read string from standard input

        // Add integer to list
        if (strcmp(cmd, "add")==0) {
            printf("Enter number to be added: ");
            scanf("%d%c", &inVal, &junk);

            // Add a node to the start of the list
            first = addNode(first, inVal);
        }

        // Delete integer from list
        else if (strcmp(cmd, "delete")==0) {
            printf("Enter number to be deleted: ");
            scanf("%d%c", &inVal, &junk);

            // Delete a node matching the given number
            first = delNode(first, inVal);
        }

        // Find integer in list
        else if (strcmp(cmd, "find")==0) {
            printf("Enter number to be found: ");
            scanf("%d%c", &inVal, &junk);

            // Find a node containing the given number
            // and display the found number
            printf("Number found: %d\n", findNode(first, inVal)->value);
        }

        // Print contents of entire list
        else if (strcmp(cmd, "print")==0) {
            printList(first);
        }
        
        // Invalid command
        else if(strcmp(cmd, "exit")!=0){
            printf("Invalid command %s\n", cmd);
        }

    } while(strcmp(cmd, "exit")!=0);
    freeList(first);
    
    return 0;
}

// Reads string from standard input and dynamically allocates space
// Assumes string terminates with '\n'
char *readLine() {
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