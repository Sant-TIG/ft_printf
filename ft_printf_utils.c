#include "ft_printf.h"

int	ft_putlstr_fd(char *str, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putlstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd(45, fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

int	ft_len_nbase(int nbr, int nbase, int len);

/**/

int	ft_putlnbr_fd(int nbr, int fd, int len)
{
	ft_putnbr_fd(nbr, 1);
	if (nbr == -2147483648)
		return(11);
	if (nbr == 0)
		return(1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	ft_len_nbase(nbr, 10, len);
}

/*
  La funcion ft_len_nbase() se encarga de devolver la cantidad de numeros que forman
  el numero pasado como parametro, en relacion al numero de elementos de una base
  determinada(decimal => nbase = 10 || hexadecimal => nbase = 16).
*/

int	ft_len_nbase(int nbr, int nbase, int len)
{
	while(nbr > 0 && ++len)
		nbr /= nbase;
	return(len);
}


/*
  La funcion ft_putlptr_fd() se encarga de escribir en pantalla la memoria almacenada
  en una variable de tipo puntero. Ademas, devuelve el numero de caracteres impresos.
  Al igual que en las funciones ft_putlstr_fd() y ft_putchar_fd(), esta no necesita 
  devolver nada porque esta implicito en la funcion ft_len_nbase().
*/

int	ft_putlptr_fd(size_t adr, char* base)
{
	int len;

	len = 0;
	if (adr == 0)
		len++;
	if (adr >= 16)
		ft_putlptr_fd(adr / 16, base);
	ft_putchar_fd(base[adr % 16], 1);
	ft_len_nbase(adr, 16, len);
}

/*
  La funcion ft_strlen() se encarga de devolver el numero de caracteres que forman
  la cadena pasada como parametro.
*/

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

/*
  Con la funcion ft_putlstr_fd() escribimos la cadena pasada como parametro y
  devolvemos la cantidad de caracteres que la forman. Al igual que la funcion
  ft_putchar_fd, esta no necesita devolver nada porque esta implicito en la
  funcion write().
*/

int	ft_putlstr_fd(char *str, int fd)
{
	if (!str)
		return(write(fd, "(null)", 6));
	write (fd, str, ft_strlen(str));
}

/*
  La funcion ft_putchar_fd() se encarga de escribir el caracter pasado con el file descriptor
  indicado. Como la funcion write devuelve el numero de caracteres impresos, no tenemos
  que devolver nada en esta funcion.
*/

int	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*
  Con la funcion ft_write_specifier() identicamos que tipo de especificador se esta
  pasando como argumento (cspdiuxX). En funcion de cual sea, llamara a la funcion 
  encargada de escribirla en pantalla y devolver la cantidad de caracteres impresos.
*/

int	ft_write_specifier(va_list ap, char c, int len)
{
	if (c == 'c')
		len += ft_putchar_fd(va_arg(ap, int), 1);
	if (c == 's')
		len += ft_putlstr_fd(va_arg(ap, char *), 1);
	if (c == 'p')
		len += write(1, "0x", 2) + ft_putlptr_fd(va_arg(ap, size_t), "0123456789abcdef");
	if (c == 'd' || c == 'i')
		len += ft_putlnbr_fd(va_arg(ap, int), 1, len);
	/*
	if (c == 'u')
	{

	}
	if (c == 'x')
	{

	}
	if (c == 'X')
	{

	}
	if (c == '%')
	{

	}*/
	return (len);
}
