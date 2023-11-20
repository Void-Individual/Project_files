#include "main.h"

/**
 * input - function to process the input from the line
 * Return: empty
*/

void input(void)
{
	char *ch = NULL, *token, **cmd;
	size_t count = 0, read;
	int num = 0;

	printf("(Notepad: )");

	read = getline(&ch, &count, stdin);
	if (read == 0 || read == -1)
	{
		printf("Please input a valid command\n");
		free(ch);
		return;
	}
	ch[count++] = '\0';

	if (strcmp(ch, "quit") == 0)
	{
		printf("CLosing...");
		free(ch);
		exit(0);
	}
	token = strtok(ch, " ");
	while (token != NULL)
	{
		cmd[num] = token;
		token = strtok(NULL, " ");
		num++;
	}

	cmd[num] = "NULL";
	exec(cmd);
}
