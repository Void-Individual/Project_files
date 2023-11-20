#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void input(void);
void exec(char *cmd, char **arg);



#endif
