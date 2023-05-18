# 377-Final-Project

In this project, I extended Project 2: Simple Shell by adding functionality to allow for the piping of commands.

The parse_command function takes in a command (cmd) and cmdTokens. It parses cmd into separate command tokens using strtok. The function then loops through these command tokens and uses strcmp to check if any of the commands are "|". If this token exists, then the remaining command tokens are set to NULL.

The exec_command takes in the arguments as a parameter and executes the command. This function forks a child process to execute the command. if there is an error, the function returns a failure message. If the ID indicates this is a child process, the function checks if the command is "quit" to exit and else, it executes the command. Otherwise, the parent process will wait for the child process to finish executing.

The isQuit function checks if the command is "quit". This function uses the strcmp function to check if the command is "quit".

The isPipe function checks if there is a command "|" to indicate this command is being piped. This function takes in two parameters, which are cmd and cmdTokens. The function then loops through the command tokens (cmdTokens) to check if any of them are "|". This is done using the strcmp function. If this command is found, the function returns true. Else, the function returns false.

The main function uses all of these functions to run the program. The main function will first parse the commands into separate tokens. It will then check if the command is "quit" and exit if it is. Otherwise, the function will next check if we have a pipe command using the isPipe function. If so, it will execute the commands. Else, the function will execute the given command and exit.


Presentation video link: https://drive.google.com/file/d/15PTYC_elsKUMFCgAF4ClB8cbEsx_8GvI/view?usp=share_link
