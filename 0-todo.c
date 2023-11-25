#include "main.h"

/**
 * main - a program to create a custom todo list application
 * Return: 0 at end of program
*/

int main(void)
{
	int loop = 1;

	printf("This is a notepad application.\nType 'list' to view all available files.\n"
	"Type 'view' filename to see the content of the file.\nType 'new' filename to create a new file.\n"
	"Type 'delete' filename to delete a file permanently.\nType 'quit' to exit.\n");

	for (;; loop++)
		input();

	return (0);
}
