#include "main.h"

/**
 * _puts - a function that prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str: the string to be printed.
 * Return: the length of the printed string.
 */
int _puts(char *str)
{
	int i = 0;

	if (str[0] != '\0')
	{
		for (i = 0; str[i] != '\0'; ++i)
		{
			_putchar(str[i]);
		}
	}
	return (i);
}
