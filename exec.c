#include "main.h"

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

	if (strcmp(arg[0], "create") == 0)
		arg[0] = "/bin/touch";
	if (strcmp(arg[0], "list") == 0)
		arg[0] = "/bin/ls, -1";
	if (strcmp(arg[0], "delete") == 0)
		arg[0] = "/bin/rm";
	if (strcmp(arg[0], "read") == 0)
		arg[0] = "/bin/cat";
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
		if (execve(arg[0], arg, NULL) == -1)
		{
			printf("Invalid command: %s, execve error\n", *arg);
			perror("execve error");
			free(cmd);
			free(arg);
			kill(getpid(), SIGTERM);
		}
	}
}
