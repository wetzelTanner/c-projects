/*****************************************************
    EGR/CS 222 Systems Programming
    
    Source file for demo: Dynamic memory allocation
    and data structures

    Contains function definitions for functions
    prototyped in LLnode.h
******************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "LLnode.h"

// Add integer to list and return list's starting address
LLnode *addNode(LLnode *list, int v) {
    LLnode* newNode;

    // Allocate space for a new node; exit if error
    newNode = (LLnode*)malloc(sizeof(LLnode));
    if(newNode == NULL){
        printf("Error: could not allocate new node\n");
        free(list);
        exit(0);
    }

    // Copy value to new node
    newNode -> value = v;
    
    // Next points to old beginning of list
    newNode -> next = list;

    return newNode;
}

// Find node in list and return pointer
//   (or NULL if not found)
LLnode *findNode(LLnode *list, int v) {
    // Create pointer to start of list
    LLnode* n = list;

    // Loop to visit all nodes in list
    while (n != NULL) {
        // For current node:
        //   a. Check if data you want is in that node --> return address if so
        if(n->value == v)
            return n;
    
        //   b. Otherwise, move to the next node
        else
            n = n->next;
    }

    // If data isn't found, return NULL
    return NULL;
}

// Delete node from list (if present)
// Return starting address of list when done
LLnode *delNode(LLnode *list, int v) {
    // Variable declaration
    LLnode* cur = list;
    LLnode* prev = NULL;
    // Loop to find the proper place matching v
    while((cur!=NULL) && (cur->value!=v)){
        prev = cur;
        cur = cur->next;
    }

    // 1. Went through entire list but no match -- return the original
    if (cur == NULL) {
        return list;
    }
    
    // 2. Match found (v == cur->value), so delete cur node
    else {
        // a. Match found in first node
        if(prev == NULL)
            list = cur->next;

        // b. Match found outside of first node
        else
            prev->next = cur->next;

        // Free the space for either case a or b. 
        free(cur);
        return list;
    }
}

// Print contents of entire list
void printList(LLnode *list) {
    // Create pointer to start of list
    LLnode* n = list;

    // List is empty
    if(n == NULL){
        printf("List is empty\n");
    }
    
    // List not empty, then print
    else{
        while(n != NULL){
            printf("%d ", n->value);
            n = n->next;
        }
        printf("\n");
    }
}

// Frees entire list before end of program to avoid memory leaks
void freeList(LLnode *list) {
    LLnode* cur = list;
    LLnode* prev = NULL;

    while(cur != NULL){
        prev = cur;
        cur = cur->next;
        free(prev);
    }
}
