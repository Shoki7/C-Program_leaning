/*The program you provided demonstrates a custom implementation of the printf function called my_printf. It allows you to format and print various types of data using format specifiers.*/

#include<stdio.h>
#include<stdarg.h>

void my_printf(char *format, ...);

int main()
{
    int num = 123;
    char ch = 'A';
    float floatValue = 3.14f;
    double doubleValue = 1.23456789;
    long double longDoubleValue = 9.876543210000000000L;
    unsigned int octValue = 0777;
    unsigned int unsignedValue = 4294967295;
    long int longIntValue = 987654321;
    unsigned int hexValue = 0xABCD;
    void *ptr = &num;

    my_printf("Decimal integer: %d\n", num);
    my_printf("Character: %c\n", ch);
    my_printf("Float value: %f\n", floatValue);
    my_printf("Exponential notation: %e\n", doubleValue);
    my_printf("String: %s\n", "Hello, World!");
    my_printf("Double: %f\n", doubleValue);
    my_printf("Long Double: %Lf\n", longDoubleValue);
    my_printf("Octal value: %o\n", octValue);
    my_printf("Unsigned value: %u\n", unsignedValue);
    my_printf("Long decimal integer: %ld\n", longIntValue);
    my_printf("Hexadecimal value: %x\n", hexValue);
    my_printf("Memory address: %p\n", ptr);

    return 0;
}


void my_printf(char *format, ...)
{
    va_list ap;
    va_start(ap, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd':
                case 'i': {
                    int x = va_arg(ap, int);
                    fprintf(stdout, "%d", x);
                    break;
                }
                case 'c': {
                    int c = va_arg(ap, int);
                    putchar(c);
                    break;
                }
                case 'f': {
                    double f = va_arg(ap, double);
                    fprintf(stdout, "%f", f);
                    break;
                }
                case 'e': {
                    double e = va_arg(ap, double);
                    fprintf(stdout, "%e", e);
                    break;
                }
                case 's': {
                    char *s = va_arg(ap, char *);
                    fprintf(stdout, "%s", s);
                    break;
                }
                case 'l': {
                    format++;
                    switch (*format) {
                        case 'f': {
                            double lf = va_arg(ap, double);
                            fprintf(stdout, "%lf", lf);
                            break;
                        }
                        case 'd': {
                            long int ld = va_arg(ap, long int);
                            fprintf(stdout, "%ld", ld);
                            break;
                        }
                        default:
                            putchar(*format);
                            break;
                    }
                    break;
                }
                case 'u': {
                    unsigned int u = va_arg(ap, unsigned int);
                    fprintf(stdout, "%u", u);
                    break;
                }
                case 'x': {
                    unsigned int x = va_arg(ap, unsigned int);
                    fprintf(stdout, "%x", x);
                    break;
                }
                case 'p': {
                    void *p = va_arg(ap, void *);
                    fprintf(stdout, "%p", p);
                    break;
                }
                case 'o': {
                    unsigned int o = va_arg(ap, unsigned int);
                    fprintf(stdout, "%o", o);
                    break;
                }
                case 'L': {
                    long double Lf = va_arg(ap, long double);
                    double lf = (double)Lf;
                    fprintf(stdout, "%f", lf);
                    break;
                }
                default:
                    putchar(*format);
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }

    va_end(ap);
}

