#include "variadic_functions.h"

/**
*print_all - prints anything
*@format: a list of types of arguments passed to the function
*
*/

void print_all(const char * const format, ...)
{
	va_list li;
	unsigned int i = 0, j;
	char *str;

	while (format != NULL)
		{
		va_start(li, format);
		while (format[i] != 0)
		{
			j = 1;
			switch (format[i])
			{
				case 'c':
				printf("%c", va_arg(li, int));
				break;
				case 'i':
				printf("%d", va_arg(li, int));
				break;
				case 'f':
				printf("%f", va_arg(li, double));
				break;
				case 's':
				str = va_arg(li, char *);
				if (str == 0)
				str = "(nil)";
				printf("%s", str);
				break;
				default:
				j = 0;
				break;
			}
			if (format[i + 1] && j)
				printf(", ");
			i++;
		}
		va_end(li);
		break;
	}
	printf("\n");
}
