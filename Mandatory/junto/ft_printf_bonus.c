#include "../incs/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_strlen(const char *str)
{
	//printf("STRLEN\n");
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	//printf("PUTSTR\n");
	return (write(1, str, ft_strlen(str)));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_is_specifier(int c)
{
	//printf("IS SPECIFIER\n");
	return ((c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'));
}

int	ft_strstr(char *str, char *str1)
{
	while (*str && *str1 && *str == *str1)
	{
		str++;
		str1++;
	}
	if (*str != *str1)
		return (0);
	return(1);
}

void	ft_init_struct(t_bonus *flags)
{
	//printf("INIT_STRUCT\n");
	flags->len = 0;
	flags->id = 0;
}

void	ft_init_flags(t_bonus *flags)
{
	//printf("INIT FLAGS\n");
	flags->plus = 0;
	flags->minus = 0;
	flags->width = -1;
	flags->space = 0;
	flags->precision = -1;
	flags->zero = 0;
	flags->hastack = 0;
	flags->sign = 0;
}

char	*ft_spclen(const char *str)
{
	size_t	i;

	i = 0;
	while(!ft_is_specifier(str[i]))
		i++;
	return ((char *)&str[i]);
}

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
	//printf("reslt = %d",result);
	return (result * sign);
}

char	*ft_get_width(const char *str)
{
	size_t	i;
	size_t	j;
	char	*dst;
	
	//printf("str = %s\n", str);
	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	dst = (char *)malloc(sizeof(char) * (j + 1));
	if (!dst)
		return (NULL);
	dst[j] = '\0';
	while (j--)
		dst[j] = str[i + j];
	return (dst);
}

char *ft_get_precision(const char *str)
{
	//printf("\nGET PRECISION\n");
	//printf("\nstr = %s\n", str);
	size_t	i;
	size_t	j;
	char	*dst;
	
	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	dst = (char *)malloc(sizeof(char) * (j + 1));
	dst[j] = '\0';
	while (j-- > 0)
		dst[j] = str[i + j];
	//printf("\nstr = %s\n", dst);
	return (dst);
}

size_t	ft_uintlen(unsigned int unbr)
{
	size_t	unbr_len;

	unbr_len = 0;
	while (unbr > 0)
	{
		unbr /= 10;
		unbr_len++;
	}
	return (unbr_len);
}

char	*ft_charconv(char *dest, unsigned int unbr, size_t unbr_len)
{
	if (unbr == 0)
		*dest = 48;
	while (unbr > 0)
	{
		*(dest + unbr_len--) = 48 + (unbr % 10);
		unbr /= 10;
	}
	return (dest);
}

char	*ft_uitoa(unsigned int unbr)
{
	//printf("\nUITOA\n");
	char	*dest;
	size_t		unbr_len;

	if (unbr == 0)
	{
		dest = malloc(2);
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	unbr_len = ft_uintlen(unbr);
	dest = (char *)malloc(sizeof(char) * unbr_len + 1);
	if (!dest)
		return (NULL);
	*(dest + unbr_len--) = '\0';
	dest = ft_charconv(dest, unbr, unbr_len);
	//printf("\ndest = %s\n", dest);
	return (dest);
}

char	*ft_process_precision_uint(t_bonus *flags, char *unbr_str)
{
	//printf("precisionn =%d",ft_strlen(unbr_str) + (flags->precision - ft_strlen(unbr_str)));
	//printf("\nPROCESS PRECISION UINT\n");
	char	*new_nbr_str;
	int		nbr;
	size_t	i;
	size_t	j;

	i = 0;

	nbr = (flags->precision) - ft_strlen(unbr_str);
	nbr += ft_strlen(unbr_str) + 1;
	new_nbr_str = (char *)malloc(sizeof(char) * nbr + 1);
	if (!new_nbr_str)
		return (NULL);
	//printf("%d\n", nbr);
	while (nbr-- > ft_strlen(unbr_str) + 1)
		new_nbr_str[i++] = '0';
	j = 0;
	while (nbr--)
		new_nbr_str[i++] = unbr_str[j++];
	new_nbr_str[i] = '\0';
	free(unbr_str);
	//printf("\nnew_str_nbr = %s\n", new_nbr_str);
	return (new_nbr_str);
}

int	ft_process_width(char*str, t_bonus *flags)
{
	int	nbr;
	int	i;

	i = 0;
	/*if (ft_strstr(str, "0") && flags->width > ft_strlen(str))
	{
		nbr = flags->width;
		while (nbr--)
			i += ft_putchar(' ');
		return (i);
	}*/
	if (flags->id == 'c')
		nbr = (flags->width) - 1;
	else if (flags->sign != 0)
		nbr = (flags->width) - ft_strlen(str) - 1;
	else
		nbr = (flags->width) - ft_strlen(str);
	/*if (flags->zero == 1 && flags->plus == 0 && flags->precision <= -1)
	{
		//printf("hgfjhgsdfohlgsv");
		while (nbr-- > 0)
			i += ft_putchar('0');
		return (i);
	}*/

	if (flags->precision != -1 && flags->width >= 0 && ft_strstr(str, "0"))
	{
		if (flags->precision == ft_strlen(str))
			nbr = 0;
		else
			nbr = flags->width;
		while (nbr--)
			i+= ft_putchar(' ');
		return (i);
	}	
	else if (flags->plus == 1)
	{
		if (flags->zero == 1)
		{
			i += ft_putchar('+');
			while (nbr-- > 1)
				i += ft_putchar('0');
			return (i);
		}
		while (nbr-- > 1)
			i += ft_putchar(' ');
		i += ft_putchar('+');
		return (i);			
	}
	else if (flags->space == 1)
	{
		if (flags->zero == 1)
		{
			while (nbr-- > 0)
				i += ft_putchar('0');
			return (i);
		}
	}
	else if (flags->zero == 1)
	{
		if (flags->precision > 0)
		{
			while (nbr-- > 0)
				i += ft_putchar(' ');
		}
		while (nbr-- > 0)
			i += ft_putchar('0');
		return (i);
	}
	while (nbr-- > 0)
		i += ft_putchar(' ');
	return (i);
}



char	*ft_process_precision(char *str, t_bonus *flags)
{
	//printf("%d", flags->precision);
	//printf ("\nPROCESS PRECISION\n");
	char	*prc;
	int 	nbr;

	if (ft_strstr(str, "(null)"))
	{
		free(str);
		return ("");
	}
	nbr = flags->precision;
	prc = (char *)malloc(sizeof(char) * nbr + 1);
	prc[nbr] = '\0';
	while (nbr-- > 0)
		prc[nbr] = str[nbr];
	free(str);
	return (prc);
}

void	ft_process_negative_int(char *unbr_str, t_bonus *flags)
{
	if (flags->precision == 0 && ft_strstr(unbr_str, "0"))
	{
		if (flags->width > 0 || flags->zero == 1)
			flags->len += ft_process_width(unbr_str, flags) + ft_putstr("");
		else
			flags->len += ft_putstr("");
	}
	else 
	{
		if (flags->precision > ft_strlen(unbr_str))
			unbr_str = ft_process_precision_uint(flags, unbr_str);
		if (flags->width > 0)
		{
			if (flags->minus > 0)
				flags->len += ft_putchar('-')  + ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
			else if (flags->zero > 0)
			{
				if (flags->precision > 0)
					flags->len += ft_process_width(unbr_str, flags) + ft_putchar('-')  + ft_putstr(unbr_str);
				else
					flags->len += ft_putchar('-')  + ft_process_width(unbr_str, flags) + ft_putstr(unbr_str);
			}
			else
				flags->len += ft_process_width(unbr_str, flags) + ft_putchar('-')  + ft_putstr(unbr_str);
		}
		else if (flags->minus > 0)
			flags->len += ft_putchar('-')  + ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
		else if (flags->space > 0)
		{
			if (flags->sign != 0)
				flags->len += ft_putchar('-')  + ft_putstr(unbr_str);
			else
				flags->len += ft_putchar(' ') + ft_putchar('-')  + ft_putstr(unbr_str);
		}
		else
			flags->len += ft_putchar('-') + ft_putstr(unbr_str);
	}
	free(unbr_str);
}

char	*ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}

char	*ft_strndup(const char *str, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, str, len + 1);
	return (dst);
}

size_t	ft_hexlen(unsigned int hex)
{
	size_t	hex_len;

	hex_len = 0;
	while (hex > 0)
	{
		hex /= 16;
		hex_len++;
	}
	return (hex_len);
}

char	*ft_charconv_hex(char *str, unsigned int unbr, size_t unbr_len, t_bonus *flags)
{
	if (flags->id == 'x' || flags->id == 'p')
	{
		if (unbr == 0)
			*str = LOWERXBASE[unbr % 16];
		while (unbr > 0)
		{
			*(str + unbr_len--) = LOWERXBASE[unbr % 16];
			unbr /= 16;
		}
		return (str);
	}
	if (unbr == 0)
		*str = UPPERXBASE[unbr % 16];
	while (unbr > 0)
	{
		*(str + unbr_len--) = UPPERXBASE[unbr % 16];
		unbr /= 16;
	}
	return (str);
}

char	*ft_hextoa(size_t hex, t_bonus *flags)
{
	char	*hex_str;
	size_t	hex_len;

	/*if (hex == 0)
		return ("0");*/
	hex_len = ft_hexlen(hex);
	hex_str = (char *)malloc(sizeof(char) * hex_len + 1);
	if (!hex_str)
		return (NULL);
	*(hex_str + hex_len--) = '\0';
	hex_str = (ft_charconv_hex(hex_str, hex, hex_len, flags));
	return (hex_str);
}


void	ft_process_int(int nbr, t_bonus *flags)
{
	unsigned int unbr;
	char	*unbr_str;

	if (nbr < 0 || nbr == INT_MIN)
	{
		flags->sign = '-';
		flags->plus = 0;
		unbr = nbr * -1;
	}
	else
		unbr = nbr;
	unbr_str = ft_uitoa(unbr);
	if (flags->sign != 0)
		ft_process_negative_int(unbr_str, flags);
/*	else if (unbr == 0)
		ft_process_zero(unbr_str, flags);*/
	else
	{
		if ((flags->precision == 0 && unbr == 0))
		{
			if (flags->width > 0 || flags->zero == 1)
				flags->len += ft_process_width(unbr_str, flags) + ft_putstr("");
			else
				flags->len += ft_putstr("");
		}
		else 
		{
			if (flags->precision > ft_strlen(unbr_str))
				unbr_str = ft_process_precision_uint(flags, unbr_str);
			if (flags->width > 0)
			{
				if (flags->minus > 0)
					flags->len += ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
				else
					flags->len += ft_process_width(unbr_str, flags) + ft_putstr(unbr_str);
			}
			else if (flags->plus > 0)
				flags->len += ft_putchar('+') + ft_putstr(unbr_str);
			else if (flags->minus > 0)
				flags->len += ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
			else if (flags->space > 0)
				flags->len += ft_putchar(' ') + ft_putstr(unbr_str);
			//printf("unbr_str = %s\n", unbr_str);
			/*if (flags->width > 0)
			{
				if (flags->minus == 1)
					flags->len += ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
				else
				//printf("width = %d str = %d", ft_process_width(unbr_str, flags), ft_putstr(unbr_str));
					flags->len += ft_process_width(unbr_str, flags) + ft_putstr(unbr_str);
			}
			else if (flags->sign == '-')
				flags->len += ft_putchar('-') + ft_putstr(unbr_str);
			else if (flags->space == 1)
				flags->len += ft_putchar(' ') + ft_putstr(unbr_str);
			else
				flags->len += ft_putstr(unbr_str);
			//printf("%u\n", unbr);*/
			else
				flags->len += ft_putstr(unbr_str);
		}
		free(unbr_str);
	}
}

void 	ft_process_hex(unsigned int hex, t_bonus *flags)
{
	char	*hex_str;

	hex_str = ft_hextoa(hex, flags);
	if ((flags->precision == 0 && hex == 0) && flags->hastack == 0)
	{
		if ((flags->width > 0 || flags->zero == 1))
			flags->len += ft_process_width(hex_str, flags) + ft_putstr("");
		else
			flags->len += ft_putstr("");
		free(hex_str);
	}
	else
	{
		if (flags->precision > ft_strlen(hex_str))
			hex_str = ft_process_precision_uint(flags, hex_str);
		//printf("\nunbr_str = %s\n", unbr_str);
		if (flags->minus == 1 && flags->width == -1)
			flags->len += ft_putstr(hex_str);
		else if (flags->hastack == 1 && hex != 0)
		{
			if (flags->id == 'X' && hex != 0)
				flags->len += ft_putstr("0X") + ft_putstr(hex_str) + ft_process_width(hex_str, flags);
			else if ((flags->id == 'x') && hex != 0 )
				flags->len += ft_putstr("0x") + ft_putstr(hex_str) + ft_process_width(hex_str, flags);
		}
		else if (flags->hastack == 1 && hex == 0)
		{
			if (flags->id == 'X')
				flags->len += ft_putstr("0") + ft_process_width(hex_str, flags);
			else if (flags->id == 'x')
				flags->len += ft_putstr("0") + ft_process_width(hex_str, flags);
			
		}
		else if (flags->width > 0)
		{
			if (flags->minus == 1)
				flags->len += ft_putstr(hex_str) + ft_process_width(hex_str, flags);
			else
			//printf("\nZEROOOO2\n");
				flags->len += ft_process_width(hex_str, flags) + ft_putstr(hex_str);
		}
		else
			flags->len += ft_putstr(hex_str);
		free(hex_str);
	}
}
void	ft_process_uint(unsigned int unbr, t_bonus *flags)
{
	char	*unbr_str;

	unbr_str = ft_uitoa(unbr);
	if ((flags->precision == 0 && unbr == 0))
	{
		if (flags->width > 0 || flags->zero == 1)
			flags->len += ft_process_width(unbr_str, flags) + ft_putstr("");
		else
			flags->len += ft_putstr("");
		free(unbr_str);
	}
	else
	{
		if (flags->precision > ft_strlen(unbr_str))
			unbr_str = ft_process_precision_uint(flags, unbr_str);
		//printf("\nunbr_str = %s\n", unbr_str);
		if (flags->minus == 1)
			flags->len += ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
		else if (flags->width > 0 || flags->zero == 1)
		{
			//printf("\nZEROOOO2\n");
			flags->len += ft_process_width(unbr_str, flags) + ft_putstr(unbr_str);
		}
		else
			flags->len += ft_putstr(unbr_str);
		free(unbr_str);
	}		
}

void	ft_process_str(char *str, t_bonus *flags)
{
	char	*temp;

	if (!str && flags->precision != -1 && flags->precision < 6)
	{
		flags->len += ft_putstr("");
	}
	else
	{
		if (!str)
		{
			temp = ft_strndup("(null)", 6);
			//printf("temp = %s\n", temp);
		}
		else
			temp = ft_strndup(str, ft_strlen(str));
		if (flags->precision == 0)
		{
			free(temp);
			temp = ft_strndup("", 0);
		}
		else if (flags->precision < ft_strlen(temp) && flags->precision != -1)
			temp = ft_process_precision(temp, flags);
		//printf("temp = %s|\n", temp);
		if (flags->minus == 1 && flags->width == -1)
			flags->len += ft_putstr(temp) + ft_process_width (temp, flags);
		else if (flags->width > 0)
		{
			if (flags->minus == 1)
				flags->len += ft_putstr(temp) + ft_process_width (temp, flags);
			else
				flags->len += ft_process_width (temp, flags) + ft_putstr(temp);
		}
		else
			flags->len += ft_putstr(temp);
		free(temp);
	}
}

void	ft_process_pointer(void *ptr_addr, t_bonus *flags)
{
	char			*str;
	unsigned long	addr;

	addr = (unsigned long)ptr_addr;
	str = ft_hextoa(addr, flags);
	flags->len += ft_putstr("0x") + ft_putstr(str);
	free(str);
	
}

void	ft_process_char(int c, t_bonus *flags)
{
	if (flags->width > 0)
	{
		if (flags->minus == 1)
			flags->len += ft_putchar(c) + ft_process_width ("", flags);
		else
			flags->len += ft_process_width("", flags) + ft_putchar(c);
	}
	else if (flags->minus == 1)
		flags->len += ft_putchar(c) + ft_process_width ("", flags);
	else
		flags->len += ft_putchar(c);
}

void	ft_write_specifier(va_list ap, t_bonus *flags)
{
	if (flags->id == 'c')
		ft_process_char(va_arg(ap, int), flags);
	else if (flags->id == 's')
		ft_process_str(va_arg(ap, char *), flags);
	else if (flags->id == 'u')
		ft_process_uint(va_arg(ap, unsigned int), flags);
	else if (flags->id == 'x' || flags->id == 'X')
		ft_process_hex(va_arg(ap, unsigned int), flags);
	else if (flags->id == 'i' || flags->id == 'd')
		ft_process_int(va_arg(ap, int), flags);
	else if (flags->id == 'p')
		ft_process_pointer(va_arg(ap, void *), flags);
}




void	ft_control_zero(const char **format, t_bonus *flags)
{
	if (flags->zero == 0)
		flags->zero = 1;
	++*format;
}

void	ft_control_precision(const char **format, t_bonus *flags)
{
	char	*prec_str;

	++*format;
	prec_str = ft_get_precision(*format);
	flags->precision = ft_atoi(prec_str);
	free(prec_str);
	while (ft_isdigit(**format))
		++*format;
}

void	ft_control_width(const char **format, t_bonus *flags)
{
	char	*width_str;

	width_str = ft_get_width(*format);
	flags->width = ft_atoi(width_str);
	free(width_str);
	while (ft_isdigit(**format) && *format)
		++*format;
}

void	ft_control_space(const char **format, t_bonus *flags)
{
	if (flags->plus == 1)
		flags->space = 0;
	else
		flags->space = 1;
	++*format;
}

void	ft_control_minus(const char **format, t_bonus *flags)
{
	if (flags->minus == 0)
		flags->minus = 1;
	++*format;
}

void	ft_control_plus(const char **format, t_bonus *flags)
{
	if (flags->plus == 0)
		flags->plus = 1;
	++*format;
}

void	ft_control_hastack(const char **format, t_bonus *flags)
{
	if (flags->hastack == 0)
		flags->hastack = 1;
	++*format;
}

void	ft_control_flags(const char *format, t_bonus *flags)
{
	ft_init_flags(flags);
	while (!ft_is_specifier(*format) && *format != '%')
	{
		if (*format == '#')
			ft_control_hastack(&format, flags);
		if (*format == '+')
			ft_control_plus(&format, flags);
		if (*format == '-')
			ft_control_minus(&format, flags);
		if (*format == ' ')
			ft_control_space(&format, flags);
		if (*format == '0')
			ft_control_zero(&format, flags);
		if (ft_isdigit(*format))
			ft_control_width(&format, flags);
		if (*format == '.')
			ft_control_precision(&format, flags);
	}
	if (ft_is_specifier(*format))
		flags->id = *format;
}




int ft_printf(const char *format, ...)
{
	//printf("PRINTF\n");
	va_list	ap;
	t_bonus	flags;

	va_start(ap, format);
	ft_init_struct(&flags);
	while (*format)
	{
		if (*format == '%' && *++format != '%')
		{
			//printf("format = %s\n", format);
			ft_control_flags(format, &flags);
			ft_write_specifier(ap, &flags);
			format = ft_spclen(format);
			//printf("format = %s\n", format);
		}
		else
			flags.len += ft_putchar(*format);
		//printf("*format = %c\n", *format);
		format++;
		//printf("format = %s\n", format);
	}
	return (flags.len);
}
/*
int main()
{

}*/
