#include "main.h"

/**
 * list - function to list all files in the folder
 * @cmd: has to be freed
 * @arg: has to be freed
 * Return: empty
*/

void list(char *cmd, char **arg)
{
	char *run[] = {"/bin/ls", "-l", NULL};

	if (execve(run[0], run, NULL) == -1)
	{
		perror("execve error");
		free(cmd);
		free(arg);
		kill(getpid(), SIGTERM);
	}

}

/**
 * exec - function to process passed commands
 * @cmd: passed command
 * @arg: command to be passed
 * Return: empty
*/

void exec( char *cmd, char **arg)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("Fork error");
		return;
	}
	if (child > 0)
		wait(&status);

	if (child == 0)
	{
		if (strcmp(arg[0], "list") == 0)
			list(cmd, arg);
	}
}
