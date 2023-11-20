#include "main.h"

/**
 * input - function to process the input from the line
 * Return: empty
*/

void input(void)
{
	char *cmd = NULL, *token, **args;
	size_t count = 0, read;
	int num = 0;

	printf("(Notepad: )");

	read = getline(&cmd, &count, stdin);
	if (read == 0 || read == -1)
	{
		printf("Please input a valid command\n");
		free(cmd);
		return;
	}
	cmd[read - 1] = '\0';
	if (strcmp(cmd, "quit") == 0)
	{
		printf("CLosing...");
		free(cmd);
		exit(0);
	}
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		args[num] = token;
		token = strtok(NULL, " ");
		num++;
	}

	args[num] = "NULL";
	exec(cmd, args);
	free(args);
	free(cmd);
}
