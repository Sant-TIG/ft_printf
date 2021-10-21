#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


int	ft_putchar(char c);


int	ft_is_specifier(char c);

size_t	ft_spclen(const char *str)
{
	size_t	i;

	i = 0;
	while(!ft_is_specifier(str[i]))
		i++;
	return (i);
}

/*------------------------------------------*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(char *str);

int	ft_atoi(const char *str);

int	ft_isdigit(int c);

char	*ft_get_width(const char *str)
{
	size_t	i;
	char	*dst;
	int		nbr;
	
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	dst[i] = '\0';
	while (i--)
		dst[i] = str[i];
	return (dst);
}

int	ft_isdigit(int c);

int	ft_process_width(char *arg, const char *format, size_t len)
{
	int		i;
	int		nbr;
	char 	*str;

	i = 0;
	nbr = 0;
	if (ft_isdigit(format[i]))
	{
		str = ft_get_width(format);
		nbr = ft_atoi(str) - ft_strlen(arg);
		while (nbr-- )
			i += ft_putchar(' ');
		return (i);
	}
	return (0);
}

int	ft_putstr(char *str);

/*------------------------------------------*/

int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = (*str++ - 48) + (result * 10);
	return (result * sign);
}

/*------------------------------------------*/

int	ft_isdigit(int c);

int	ft_prclen(char *str)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

char *ft_get_precision(const char *format)
{
	char 	*str;
	size_t	i;

	i = -1;
	str = (char *)malloc(sizeof(char) * (ft_prclen((char *)format) + 1));
	while (ft_isdigit(format[++i]))
		str[i] = format[i];
	str[i] = '\0';
	return (str);
}

/*------------------------------------------*/

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

char *ft_process_precision(char *arg, const char *format, char id)
{
	size_t	i;
	char	*str;
	char	*prc;
	int 	nbr;

	i = 0;
	nbr = 0;
	while (format[i] != '.' && format[i] != id)
		i++;
	if (format[i] == '.')
	{
		i++;
		if (format[i] != '0')
		{
			if (ft_isdigit(format[i]))
			{
				str = ft_get_precision(&format[i]);
				nbr = ft_atoi(str);
				prc = (char *)malloc(sizeof(char) * nbr + 1);
				prc[nbr] = '\0';
				while (nbr--)
				{
					prc[nbr] = arg[nbr];
				}
				return (prc);
			}
			return (NULL);
		}
		return (NULL);
	}
	return (arg);
}

/*------------------------------------------*/

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_process_string(char *arg, const char *format, char id)
{
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	if (!arg)
		return (ft_putstr("(null)"));
	arg = ft_process_precision(arg, format, id);
	if (format[i] == '-')
	{
		i++;
		len = ft_putstr(arg) + ft_process_width(arg, &format[i], ft_strlen(arg));
		return (len);
	}
	if (ft_isdigit(format[i]))
	{
		len = ft_process_width(arg, &format[i], ft_strlen(arg)) + ft_putstr(arg);
		return (len);
	}
	else
		return (ft_putstr(arg));
	return (len);
}

int	ft_write_specifier(va_list ap,const char *format, char id)
{
	int	len;

	len = 0;
	if (id == 's')
	{
		len = ft_process_string(va_arg(ap, char *), format, id);
	}
	return (len);
}

int	ft_is_specifier(char c)
{
	return ((c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'));
}

char	ft_identify_specifier(const char *str, int i)
{
	while(!ft_is_specifier(str[i]))
		i++;
	return (str[i]);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	char	id;
	size_t	i;
	size_t	format_len;

	i = 0;
	format_len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			id = ft_identify_specifier(format, i);
			format_len = ft_write_specifier(ap, &format[i + 1], id) + i;
			i += ft_spclen(&format[i]) + 1;
		}
		else
		{
			i += ft_putchar(format[i]);
			format_len++;
		}
	}
	va_end(ap);
	return (format_len);
}

int main ()
{
	int len = printf("Esto es una cadena: %10.4s y esta es otra: %-7.5s|\n", "cadena", "cadena");
	int len1 = ft_printf("Esto es una cadena: %10.4s y esta es otra: %-7.5s|\n", "cadena", "cadena");
	printf ("Printf = %d ft_printf = %d", len , len1);
	return (0);
}


/*
int main()
{
	int len = printf("Prueba 1:%50c\n", 'a');
	int len1 = ft_printf("Prueba 1:%50c\n", 'a');
	printf("%d\t%d\n", len, len1);
	len = printf("Prueba 2:%-50c\n", 'a');
	len1 = ft_printf("Prueba 2:%-50c\n", 'a');
	printf("%d\t%d\n", len, len1);
	printf("%10s, %6s, %4s, %0s, %s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	printf("%-10s, %-6s, %-4s, %-0s, %-s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	printf("%.10s, %.6s, %.4s, %.0s, %.s|\n", "cadena", "cadena", "cadena", "cadena");	
	printf("%-.10s, %-.6s, %-.4s, %-.0s, %-.s|\n", "cadena", "cadena", "cadena", "cadena");
	printf("%10.10s, %6.6s, %4.4s, %0.0s, %10.s|\n", "cadena", "cadena", "cadena", "cadena");
	printf("%-10.10s, %-6.6s, %-4.4s, %-0.0s, %-10.s|\n", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%10s, %6s, %4s, %0s, %s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%-10s, %-6s, %-4s, %-0s, %-s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%.10s, %.6s, %.4s, %.0s, %.s|\n", "cadena", "cadena", "cadena", "cadena");	
	ft_printf("%-.10s, %-.6s, %-.4s, %-.0s, %-.s|\n", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%10.10s, %6.6s, %4.4s, %0.0s, %10.s|\n", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%-10.10s, %-6.6s, %-4.4s, %-0.0s, %-10.s|\n", "cadena", "cadena", "cadena", "cadena");

}*/
/*
int main()
{
	ft_printf("\n---CHARACTER CASE---\n");
	int len = printf("Printf: Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z',  '0' - 256, '0' + 256, ' ');
	int len1 = ft_printf("Ft_printf: Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z', '0' - 256, '0' + 256, ' ');
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
	ft_printf("\n---CHARACTER CASE BONUS---\n");
	ft_printf("\n --SIMPLE FLAGS TESTS-- \n");
	len += printf("Printf: %#c\n", 'a');
	len += printf("Printf: %0c\n", 'a');
	len += printf("Printf: %-c\n", 'a');
	len += printf("Printf: % c\n", 'a');
	len += printf("Printf: %+c\n", 'a');
	len += printf("Printf: %50c\n", 'a');
	len += printf("Printf: %.c\n", 'a');
	ft_printf("\n --MIXED FLAGS TESTS-- \n");
	len += printf("Printf1: %50.c\n", 'a');
	len += printf("Printf2: %50.4c\n", 'a');
	len += printf("Printf3: %.50c\n", 'a');
	len += printf("Printf4: %5.50c\n", 'a');
	len += printf("Printf5: % 50c\n", 'a');
	len += printf("Printf6: %+50c\n", 'a');
	len += printf("Printf7: %050c\n", 'a');
	len += printf("Printf8: %#50c\n", 'a');
	len += printf("Printf9: %-50c\n", 'a');
	len += printf("Printf10: %50c\n", 'a');
	len += printf("Printf11: %#050c\n", 'a');
	len += printf("Printf12: %#-50c\n", 'a');
	len += printf("Printf13: %# 50c\n", 'a');
	len += printf("Printf14: %#+50c\n", 'a');
	len += printf("Printf15: %#.50c\n", 'a');
	len += printf("Printf16: %+ -0#50c\n", 'a');

	len += ft_printf("Printf1: %50.c\n", 'a');
	len += ft_printf("Printf2: %50.4c\n", 'a');
	len += ft_printf("Printf3: %.50c\n", 'a');
	len += ft_printf("Printf4: %5.50c\n", 'a');
	len += ft_printf("Printf5: % 50c\n", 'a');
	len += ft_printf("Printf6: %+50c\n", 'a');
	len += ft_printf("Printf7: %050c\n", 'a');
	len += ft_printf("Printf8: %#50c\n", 'a');
	len += ft_printf("Printf9: %-50c\n", 'a');
	len += ft_printf("Printf10: %50c\n", 'a');
	len += ft_printf("Printf11: %#050c\n", 'a');
	len += ft_printf("Printf12: %#-50c\n", 'a');
	len += ft_printf("Printf13: %# 50c\n", 'a');
	len += ft_printf("Printf14: %#+50c\n", 'a');
	len += ft_printf("Printf15: %#.50c\n", 'a');
	len += ft_printf("Printf16: %+ -0#50c\n", 'a');
	
	len += printf("Printf: %.#0- +.50c.\n", 'a');
	len += printf("Printf: %#0 +50.c\n", 'a');
	//len1 += ft_printf("%#c\n", 'a');
	//len1 += ft_printf("%0c\n", 'a');
	//len1 += ft_printf("%-c\n", 'a');
	//len1 += ft_printf("% c\n", 'a');
	//len1 += ft_printf("%+c\n", 'a');
	//len1 += ft_printf("%.c\n", 'a');
	len1 += ft_printf("Ft_printf: %-50c\n", 'a');
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
}*/