/*
Author: Tanner Wetzel
Date: 2/15/2023
Description: A simple two-player hangman game
*/
#include <stdio.h>
#include <ctype.h>

void badInput(void) {
    char junk;
    do{scanf("%c", &junk);
    }while(junk != '\n');
}

int main(void){
    //letters gained from user1 input
    char ltr1 = '_', ltr2 = '_', ltr3 = '_';
    //store the status of the guessed letters
    int match1 = 0, match2 = 0, match3 = 0;
    //status of the game (1 = game won, 0 = game still going)
    int won = 0;
    //store user2 guesses
    char guess;


    //loop of input for user validation
    do{
        printf("User1, enter a three-letter word: ");
        scanf("%c%c%c", &ltr1, &ltr2, &ltr3);
        
        if(!isalpha(ltr1) || !isalpha(ltr2) || !isalpha(ltr3)){
            printf("Error: used non-alphabetic character(s)!\n");
        }
        badInput();
    } while(!isalpha(ltr1) || !isalpha(ltr2) || !isalpha(ltr3));

    //loop for user2 to guess letters
    do{
        printf("User2, guess a letter: ");
        scanf("%c", &guess);
        if(guess == ltr1){
            match1 = 1;
            char v1 = '_', v2 = '_', v3 = '_'; //temporary variables to store current guessed chars
            if(match1 == 1){
                v1 = ltr1;
            }
            if(match2 == 1){
                v2 = ltr2;
            }
            if(match3 == 1){
                v3 = ltr3;
            }
            //print result of assigning current matched variables
            printf("User2, so far your word is: %c%c%c\n", v1, v2, v3);
        }
        if(guess == ltr2){
            match2 = 1;
            char v1 = '_', v2 = '_', v3 = '_'; //temporary variables to store current guessed chars
            if(match1 == 1){
                v1 = ltr1;
            }
            if(match2 == 1){
                v2 = ltr2;
            }
            if(match3 == 1){
                v3 = ltr3;
            }
            //print result of assigning current matched variables
            printf("User2, so far your word is: %c%c%c\n", v1, v2, v3);
        }
        if(guess == ltr3){
            match3 = 1;
            char v1 = '_', v2 = '_', v3 = '_'; //temporary variables to store current guessed chars
            if(match1 == 1){
                v1 = ltr1;
            }
            if(match2 == 1){
                v2 = ltr2;
            }
            if(match3 == 1){
                v3 = ltr3;
            }
            //print result of assigning current matched variables
            printf("User2, so far your word is: %c%c%c\n", v1, v2, v3);
        }
        if(guess!=ltr1 && guess!=ltr2 && guess!=ltr3){
            char v1 = '_', v2 = '_', v3 = '_'; //temporary variables to store current guessed chars
            if(match1 == 1){
                v1 = ltr1;
            }
            if(match2 == 1){
                v2 = ltr2;
            }
            if(match3 == 1){
                v3 = ltr3;
            }
            //print result of assigning current matched variables
            printf("User2, so far your word is: %c%c%c\n", v1, v2, v3);
        }
        //if all letters matched, win condition = 1
        if(match1 && match2 && match3){
            won = 1;
        }
        badInput();
    }while(!won);
    
    printf("User2 won! The word is %c%c%c\n", ltr1, ltr2, ltr3);

    return 0;
}