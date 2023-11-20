#include "main.h"

/**
 * main - a program to create a custom todo list application
 * Return: 0 at end of program
*/

int main(void)
{
	int loop = 1;

	printf("This is a notepad application.\nType 'list' to view all available files.\n"
	"'View' filename to see the content of the file.\n'quit' to exit.");

	for (;; loop++)
	{
		input();
	}

	return (0);
}
