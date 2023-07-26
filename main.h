#ifndef MYPRINTF_MAIN_H
#define MYPRINTF_MAIN_H

long _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
char *convert(unsigned int num, int base);
char *convert_cap(unsigned int num, int base);
char *convert_ptr(void *ptr);


#endif
