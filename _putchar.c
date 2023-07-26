#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes character c to stdout
 * @c: the character c to be printed
 * Return: on success 1.
 *	on error -1 is returned.
 */
long _putchar(char c)
{
	return (write(1, &c, 1));
}
