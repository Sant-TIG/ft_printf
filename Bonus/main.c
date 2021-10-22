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
	printf ("\n---SPCLEN---\n");
	while(!ft_is_specifier(str[i]))
		i++;
	return (i);
}

/*------------------------------------------*/

int	ft_putchar(char c)
{
	printf ("\n---PUTCHAR---\n");
	return (write(1, &c, 1));
}

size_t	ft_strlen(char *str);

int	ft_atoi(const char *str);

int	ft_isdigit(int c);

char	*ft_get_width(const char *str)
{
	printf ("\n---GET WIDTH---\n");
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
	printf ("\n---PROCESS WIDTH---\n");
	int		i;
	int		nbr;
	char 	*str;

	i = 0;
	nbr = 0;
	if (ft_isdigit(format[i]))
	{
		str = ft_get_width(format);
		printf ("\nstr = %s\n", str);
		nbr = ft_atoi(str) - ft_strlen(arg);
		printf ("\nnbr = %d\n", nbr);
		while (nbr-- )
			i += ft_putchar(' ');
		printf ("\ni = %d\n", i);
		return (i);
	}
	return (0);
}

int	ft_putstr(char *str);

/*------------------------------------------*/

int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	printf ("\n---ATOI---\n");
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
	printf ("\n---PRCLEN---\n");
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

char *ft_get_precision(const char *format)
{
	printf ("\n---GET PRECISION---\n");
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
	printf ("\n---ISDIGIT---\n");
	return (c >= 48 && c <= 57);
}

char *ft_process_precision(char *arg, const char *format, char id)
{
	printf ("\n---PROCESS PRECISION---\n");
	size_t	i;
	char	*str;
	char	*prc;
	int 	nbr;

	i = 0;
	nbr = 0;
	printf("\narg = %s\tformat = %s\tid = %c", arg, format, id);
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
				printf ("\nstr = %s\n", str);
				nbr = ft_atoi(str);
				printf ("\nnbr = %d\n", nbr);
				prc = (char *)malloc(sizeof(char) * nbr + 1);
				prc[nbr] = '\0';
				while (nbr--)
				{
					printf("\nnbr = %d, char = %c\n", nbr, arg[nbr]);
					prc[nbr] = arg[nbr];
					printf("\nchar1 = %c\n", prc[nbr]);
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
	printf ("\n---FT_STRLEN---\n");
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	printf ("\n---PUTSTR---\n");
	return (write(1, str, ft_strlen(str)));
}

int	ft_process_string(char *arg, const char *format, char id)
{
	printf ("\n---PROCESS STRING---\n");
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	printf("\narg = %s\tformat = %s\tid = %c", arg, format, id);
	if (!arg)
		return (ft_putstr("(null)"));
	arg = ft_process_precision(arg, format, id);
	printf ("\n new arg = %s format = %s\n", arg, format);
	if (format[i] == '-')
	{
		i++;
		len = ft_putstr(arg) + ft_process_width(arg, &format[i], ft_strlen(arg));
		return (len);
	}
	if (ft_isdigit(format[i]))
	{
		printf("\n---DIGITO---\n");
		printf("\narg = %s\tformat = %s\n", arg, &format[i]);
		len = ft_process_width(arg, &format[i], ft_strlen(arg)) + ft_putstr(arg);
	}
	else
		return (ft_putstr(arg));
	return (len);
}

int	ft_write_specifier(va_list ap,const char *format, char id)
{
	printf ("\n---WRITE SPECIFIER---\n");
	int	len;

	len = 0;
	printf ("\n format = %s y id = %c", format, id);
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
	printf ("\n---IDENTYFY SPECIFIER---\n");
	while(!ft_is_specifier(str[i]))
		i++;
	return (str[i]);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	char	id;
	size_t	i;
	int	format_len;

	i = 0;
	format_len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			printf ("\n---ESTOY EN %%---\n");
			id = ft_identify_specifier(format, i);
			printf ("\n id = %c\n", id);
			format_len += ft_write_specifier(ap, &format[i + 1], id);
			printf("\n%ld y %s y  formatlen = %d\n", i, &format[i], format_len);
			i += ft_spclen(&format[i]) + 1;
			printf("\n%ld y %s\n", i, &format[i]);
		}
		else
		{
			printf ("\n---NO ESTOY EN %%\n");
			i += ft_putchar(format[i]);
			format_len++;
			printf ("\nformatlen = %d\n", format_len);
		}
	}
	va_end(ap);
	return (format_len);
}

int main ()
{
	int len = printf("Esto es una cadena: %10.4s y esta es otra: %-7.5s y esta es otra: %s|\n", "cadena", "string", "");
	int len1 = ft_printf("Esto es una cadena: %10.4s y esta es otra: %-7.5s y esta es otra: %s|\n", "cadena", "string", "");
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