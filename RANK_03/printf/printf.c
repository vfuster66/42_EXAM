#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
		*count += write(1, str++, 1);
}

void	put_digit(long long int number, int base, int *count)
{
	char	*hexa = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*count += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, count);
	*count += write(1, &hexa[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		count = 0;
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format== '%')
		{
			format++;
			if (*format == 's')
				put_str(va_arg(args, char *), &count);
			else if (*format == 'd')
				put_digit((long long int)va_arg(args, int), 10, &count);
			else if (*format == 'x')
				put_digit((long long int)va_arg(args, unsigned int), 16, &count);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	return (va_end(args), count);
}

/*#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	int	size;

	size = 0;

	size = ft_printf("%s\n", "toto");
	printf("%d\n", size);
	size = printf("%s\n", "toto");
	printf("%d\n", size);
	size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	printf("%d\n", size);
	ft_printf("Hello world %\n");
	return (0);
}*/
