#include "main.h"

/**
 * list - function to list all files in the folder
 * @cmd: has to be freed
 * @arg: has to be freed
 * Return: empty
*/

void list(char *cmd, char **arg)
{
	char *run[] = {"/bin/ls", "-1", NULL};

	if (execve(run[0], run, NULL) == -1)
	{
		free(cmd);
		free(arg);
		kill(getpid(), SIGTERM);
	}

}

/**
 * create - function to create a new file
 * @cmd: has to be freed
 * @rg: has to be freed
 * Return: empty
*/

void create(char *cmd, char **arg)
{
	arg[0] = "/bin/touch";

	if (execve(arg[0], arg, NULL) == -1)
	{
		printf("To create a new file, input 'new' followed by a single filename with no spaces.\n");
		free(cmd);
		free(arg);
		kill(getpid(), SIGTERM);
	}
}



/**
 * del - function to delete a file
 * @cmd: has to be freed
 * @rg: has to be freed
 * Return: empty
*/

void del(char *cmd, char **arg)
{
	arg[0] = "/bin/rm";

	if (execve(arg[0], arg, NULL) == -1)
	{
		printf("To delete a file, input 'delete' followed by a single filename with no spaces.\n");
		free(cmd);
		free(arg);
		kill(getpid(), SIGTERM);
	}

}

/**
 * view - function to read the content of a file
 * @cmd: has to be freed
 * @rg: has to be freed
 * Return: empty
*/

void view(char *cmd, char **arg)
{
	arg[0] = "/bin/cat";

	if (execve(arg[0], arg, NULL) == -1)
	{
		printf("To check the content of a file, input 'view' followed by a single filename with no spaces.\n");
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
		return;
	if (child > 0)
		wait(&status);

	if (child == 0)
	{
		if (strcmp(arg[0], "list") == 0)
			list(cmd, arg);
		if (strcmp(arg[0], "new") == 0)
			create(cmd, arg);
		if (strcmp(arg[0], "delete") == 0)
			del(cmd, arg);
		if (strcmp(arg[0], "view") == 0)
			view(cmd, arg);

		printf("Please input a valid command :)\n");
		kill(getpid(), SIGTERM);
	}
}
