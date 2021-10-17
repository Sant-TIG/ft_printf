#include "../incs/ft_printf_bonus.h"
#include <stdlib.h>
#include <unistd.h>

/*
	Esta funcion comprueba primero si antes del especificador hay un caracter '-'
  antes del especificador c. En caso de ser asi, el '-' representaria la flag '-'
  por lo que el caracter c deberia imprimirse antes de los espacios.

	Una vez analizado si contiene la flag o no, hay que comprobar si se especifica
  un ancho de campo minimo. Para ello haremos un bucle que identifique que numero
  de ancho de ha pasado, para convertirlo despues a un numero y utilizarlo en otro
  bucle para imprimir la cantidad de espacios asignada.
*/

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = ft_strlen(src);
	if (dstsize)
	{
		while (src[++i] && --dstsize)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (j);
}

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_atoi(const char *str)
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

static int	ft_count_width(char *format)
{
	int len;

	len = 0;
	while(ft_isdigit(*format))
		len++;
	return (len);
}

int	ft_putlchar_bonus(int c, char *format, int len)
{
	int nbr;
	int	width_len;
	char *str;

	nbr = 0;
	str = (char *)malloc(sizeof(char) * (ft_count_width(&(*format)) + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, &(*format), width_len);
	nbr = ft_atoi(str);
	while (nbr--)
		len += write(1, " ", 1); 
	return (len);
}