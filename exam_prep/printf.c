# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

void	ft_putstr(char *s, int *counter)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return ;
	}
	while (s[++i] != '\0')
	{
		ft_putchar(s[i], counter);
	}
}

static void	ft_base(
	unsigned long arg, unsigned int base, char *digits, int *counter)
{
	if (arg >= base)
		ft_base(arg / base, base, digits, counter);
	ft_putchar(digits[arg % base], counter);
}

static void	ft_sbase(long arg, unsigned int base, char *digits, int *counter)
{
	if (arg < 0)
	{
		ft_putchar('-', counter);
		arg *= -1;
		ft_base(arg, base, digits, counter);
	}
	else
		ft_base(arg, base, digits, counter);
}

void	ft_check_type(va_list arg, char c, int *counter)
{
	if (c == 's')
		ft_putstr(va_arg(arg, char *), counter);
	if (c == 'd')
		ft_sbase(va_arg(arg, int), 10, "0123456789", counter);
	if (c == 'x')
		ft_base(
			va_arg(arg, unsigned int), 16, "0123456789abcdef", counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		counter;
	int		i;	

	i = 0;
	counter = 0;
	va_start (arg, input);
	while (input[i])
	{
		if (input[i] != '%')
			ft_putchar(input[i], &counter);
		else if (input[i] == '%' && input[i + 1] == '%' && ++i)
			ft_putchar(input[i], &counter);
		else if (input[i] == '%')
			ft_check_type(arg, input[++i], &counter);
		i++;
	}
	va_end (arg);
	return (counter);
}
