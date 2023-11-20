#include "main.h"

/**
 * exec - function to process passed commands
 * @cmd: command to be passed
 * Return: empty
*/

void exec( char **cmd)
{
	pid_t child;
	int status;

	if (strcmp(cmd[0], "create") == 0)
		cmd[0] = "/bin/touch";
	if (strcmp(cmd[0], "list") == 0)
		cmd[0] = "/bin/ls -1";
	if (strcmp(cmd[0], "delete") == 0)
		cmd[0] = "/bin/rm";
	if (strcmp(cmd[0], "read") == 0)
		cmd[0] = "/bin/cat";
	child = fork();
	if (child == -1)
	{
		perror("Fork error");
		return;
	}
	if (child > 0)
	{
		printf("Loading...\n");
		sleep(1);
		wait(&status);
	}
	if (child == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("execve error");
			free(cmd);
			kill(getpid(), SIGTERM);
		}
	}
}
