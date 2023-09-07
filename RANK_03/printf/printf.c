#include <unistd.h>
#include <stdarg.h>

int	put_str(char *str)
{
	int	len = 0;

	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

void put_digit(long long int number, int base, int *len) 
{
	char *hexa = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*len += write(1, "-", 1);
	}
	if (number >= base)
		put_digit(number / base, base, len);
	*len += write(1, &hexa[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int len = 0;

	va_list	ptr;
	va_start(ptr, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') 
					|| (*(format + 1) == 'd') 
					|| (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}
