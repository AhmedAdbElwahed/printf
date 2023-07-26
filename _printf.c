#include<stdarg.h>
#include <stdint.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: the formatted string.
 * @...: the list of args.
 * Return: the length of the printed string.
 */
int _printf(const char *format, ...)
{

	int i;
	void *pointer;
	int done = 0;
	char *s;
	va_list arg;

	va_start(arg, format);
	for (; *format != '\0'; format++)
	{
		while (*format != '%')
		{
			if (*format == '\0')
			{
				return (done);
			}
			_putchar(*format);
			done++;
			format++;
		}

		format++;


		switch (*format)
		{
			case 'c':
				i = va_arg(arg, int);
				_putchar(i);
				done++;
				break;

			case 'i':
			case 'd':
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = -i;
					_putchar('-');
					done++;
				}
				done += _puts(convert(i, 10));
				break;

			case 'o':
				i = va_arg(arg, unsigned int);
				done += _puts(convert(i, 8));
				break;

			case 's':
				s = va_arg(arg, char *);
				done += _puts(s);
				break;

			case 'X':
				i = va_arg(arg, unsigned int);
				done += _puts(convert_cap(i, 16));
				break;

			case 'x':
				i = va_arg(arg, unsigned int);
				done += _puts(convert(i, 16));
				break;

			case '%':
				_putchar(*format);
				done++;
				break;

			case 'p':
				pointer = va_arg(arg, void *);
				_putchar('0');
				_putchar('x');
				done += (_puts(convert_ptr(pointer)) + 2);
				break;

			default:
				_putchar('%');
				_putchar(*format);
				done += 2;
				break;
		}
	}


	va_end(arg);
	return (done);
}
