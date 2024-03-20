/*
Author: Tanner Wetzel
Date: 2/28/2024
Description: A simple shell program that will allow the user
             only to use basic shell commands in a linux 
             environment
*/
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <dirent.h> 

int status, total = 0;
char line[256];
char *prompt = ">";

void getln(char* buf, int size) {
    int n = 0;
    char ch;
    while((ch = getchar()) != '\n'){
        if(n<size-1) buf[n++] = ch;
    }
    buf[n] = 0;
}

void ctrlc(int signum){
    printf("\nCtrl-C type. Unable to kill");
    printf("\n%s ", prompt);
    fflush(stdout);
}

int main(int n, char* arg[]) {
    pid_t cpid;
    int pcount;
    char* args[10];
    char* ptr;
    bool background_flag = false;
    char entries[1024] = "";

    signal(2, ctrlc);

    while (strcmp(line, "exit") != 0) {
        printf("%s ", prompt);
        getln(line, 256);
        if(line[0] == '\0') continue;
        printf("Command: %s\n", line);
        ptr = line;
        while(*ptr != 0) ptr++;
        ptr--;
        if(*ptr == '&'){
            background_flag = true;
            *ptr = 0;
        } else {
            background_flag = false;
        }
        ptr = strtok(line, " ");
        int i = 0;
        while(ptr != NULL){
            args[i++] = ptr;
            ptr = strtok(NULL, " ");
        }
        args[i] = NULL;
        
        if (strcmp(args[0], "cp") == 0 && args[1] != NULL && args[2] != NULL) {
            cpid = fork();
            if(cpid==0){
                execvp(args[0], args);
                printf("ERROR, command not found\n");
                exit(1);
            }
            if(background_flag) continue;
            waitpid(cpid, &status, 0);
            if(status != 0) printf("Child had an Error #%d\n", status);
        } else if (strcmp(args[0], "dir") == 0) {
            DIR *dir;
            struct dirent *entry;

            dir = opendir(".");
            if (dir == NULL) {
                perror("opendir");
                exit(1);
            }
            
            while ((entry = readdir(dir)) != NULL) {
                strcat(entries, entry->d_name);
                strcat(entries, " ");
            }
            printf("%s\n", entries);
            for(int i=0; i<1024; i++) { 
                entries[i] = 0; 
            } 

            closedir(dir);
        } else {
            cpid = fork();
            if(cpid==0){
                execvp(args[0], args);
                printf("ERROR, command not found\n");
                exit(1);
            }
            if(background_flag) continue;
            waitpid(cpid, &status, 0);
            if(status != 0) printf("Child had an Error #%d\n", status);
        }
    }
    printf("Shell Terminating\n");
}