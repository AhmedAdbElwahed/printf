#include <stdint.h>
#include "main.h"
/**
 *	convert - convert number from base to another and convert it to string.
 * @num: the number to be converted.
 * @base: the desired base.
 * Return: string that represent the number.
 */
char *convert(unsigned int num, int base)
{
	static const char Representation[] = "0123456789abcdef";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 *	convert_cap - convert number from base to another and convert it to string.
 * @num: the number to be converted.
 * @base: the desired base.
 * Return: string that represent the number.
 */
char *convert_cap(unsigned int num, int base)
{
	static const char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 *	hex_digit1 - convert an integer to hex number.
 * @v: the int number to be converted.
 * Return: the hex number as char
 */
char hex_digit1(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

/**
 * convert_ptr - convert a pointer to string.
 * @ptr: the pointer that represent an address in memory.
 * Return: a string representation of the address.
 */
char *convert_ptr(void *ptr)
{
	int i, j;
	uintptr_t p = (uintptr_t)ptr;
	static char buffer[50];
	char *ptr1;

	ptr1 = &buffer[49];


	j = 0;
	for (i = (sizeof(p) << 3) - 4; i >= 0; i -= 4)
	{
		ptr1[j] = hex_digit1((p >> i) & 0xf);
		j++;
	}
	ptr1[j] = '\0';
	return (ptr1);
}
