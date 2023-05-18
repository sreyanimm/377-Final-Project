#include <tsh.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

using namespace std;

void simple_shell::parse_command(char* cmd, char** cmdTokens) {
    // TODO: tokenize the command string into arguments
    //looked at strtok on cplusplus.com
    *cmdTokens = strtok(cmd, " \n");
    char* result[25]; //temporary variable to hold cmdTokens
    int i = 0; //counter for while loop
    while(cmdTokens[i] != NULL) { 
        //printf ("%s\n", cmdTokens[i]); -- print statement used for testing
        if(strcmp(cmdTokens[i], "|") == 0) { //check if current token is "|"
            // for(int j = 0; j < i; j++) { //loop to add tokens before "|" to temporary variable result
            //     printf ("%s\n", cmdTokens[j]);
            //     // result[j] = cmdTokens[j];
            //     cmdTokens[j] = NULL;
            //     cmdTokens[j] = strtok(NULL, " \n");
            // }
            cmdTokens[i] = NULL;
            break; //exit while loop
        }
        ++i; //incrementer loop counter
        cmdTokens[i] = strtok(NULL, " \n"); //to get to next token
    }
    // int a = 0;
    // while(strcmp(result[a], "|") == 0) {
    //     cmdTokens[a] == NULL;
    //     a++;
    // }

    //**cmdTokens = **result;
}

void simple_shell::exec_command(char** argv) {
    // fork a child process to execute the command.
    // parent process should wait for the child process to complete and reap it
    // referred to code example from lecture 4
    int pid = fork(); //fork the process
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE); //exit with failure
    }
    else if(pid == 0) { //this is a child process
        if(isQuit(argv[0])) { //use isQuit() that is defined below
            exit(EXIT_SUCCESS); //exit successfully
        }
        execvp(argv[0], argv);
        perror("execvp");
    }
    else {
        wait(NULL); //parent process waiting for child process
    }
}

bool simple_shell::isQuit(char* cmd) {
    // TODO: check for the command "quit" that terminates the shell
    return strcmp(cmd, "quit") == 0; //use compare method to check if cmd is "quit"
}

bool simple_shell::isPipe(char* cmd, char** cmdTokens) {
    // check for the token "|" to pipe
    int i = 0;
    while(cmdTokens[i] != NULL) {  //loop through the tokens
        //printf ("%s\n", cmdTokens[i]); -- print statement used for testing
        if (strcmp(cmd, "|") == 0) {
            return true; //return true if token is "|"
        }
        ++i; //increment loop counter
    }
    return false; //if "|" not found return false
}