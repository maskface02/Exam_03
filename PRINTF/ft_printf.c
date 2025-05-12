
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *txt)
{
	int	i;

	if (!txt)
		return (print_str("(null)"));
	i = -1;
	while (txt[++i])
		write(1, &txt[i], 1);
	return (i);
}
int	degit_count(int n)
{
	int	count;

	count = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count = 1;
	}
	while (n)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

int	print_num(int n)
{
	long	nb;
	int		degit;

	degit = degit_count(n);
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		print_char('-');
	}
	if (nb >= 0 && nb <= 9)
		print_char((nb + 48));
	else
	{
		print_num(nb / 10);
		print_num(nb % 10);
	}
	return (degit);
}
int	count_hex(size_t n)
{
	int	count;

	count = 0;
	if (!n)
		count = 1;
	while (n)
	{
		n = n / 16;
		++count;
	}
	return (count);
}
int	print_hexa(size_t n)
{
	if (!n)
		return (print_num(0));
	if (n <= 16)
	{
		if (n < 10)
			print_char(n + 48);
		else
			print_char('a' + n - 10);
	}
	else
	{
		print_hexa(n / 16);
		print_hexa(n % 16);
	}
	return (count_hex(n));
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		size;

	size = 0;
	if (!f)
		return (-1);
	va_start(ap, f);
	while (*f)
	{
		if (*f == '%')
		{
			if (*(f + 1) == 's')
				size += print_str(va_arg(ap, char *));
			if (*(f + 1) == 'd')
				size += print_num(va_arg(ap, int));
			if (*(f + 1) == 'x')
				size += print_hexa(va_arg(ap, size_t));
			f++;
		}
		else
			size += print_char(*f);
		f++;
	}
	return (size);
}

int	main(void)
{
	int	size;

	size = ft_printf("%s\n", NULL);
	ft_printf("%d\n", size);
	size = printf("%s\n", NULL);
	printf("%d", size);
}
