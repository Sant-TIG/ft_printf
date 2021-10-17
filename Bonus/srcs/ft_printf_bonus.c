#include <stdarg.h>
#include "../incs/ft_printf_bonus.h"
/*
static p_list  *ft_initialise_flags(p_list *flg)
{
  flg->sharp = 0;
  flg->zero = 0;
  flg->minus = 0;
  flg->spc = 0;
  flg->plus = 0;
  flg->width = 0;
  flg->prc = 0;
}*/

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

static char  ft_identify_specifier(const char *str)
{
  while (!ft_strchr("cspdiuxX", *str))
    str++;
  return (*str);
}

static int  ft_write_specifier(va_list ap, char *format, char c, int len)
{
  if (c == 'c')
  {
    if (*format == '-')
      		len = write(1, &c, 1) + ft_putlchar_bonus(va_arg(ap, int), format, len);
    else
      len = ft_putlchar_bonus(va_arg(ap, int), format, len) + write(1, &c, 1);
  }
  return (len);
}

int ft_printf(const char *format, ...)
{
  va_list ap;
  int len;
  char id;

  len = 0;
  va_start(ap, format);
  while(*format)
  {
    if (*format == '%')
    {
      id = ft_identify_specifier(&(*format));
      len = ft_write_specifier(ap, (char *)++format, id, len);
    }
    else
			len += write(1, &format, 1);
		format++;
  }
  va_end(ap);
	return (len);
}

/*
int	ft_printf(const char *format, ...)
{
	va_list ap;
  p_list  *flags;
  int     len;
  

  len = 0;
  va_start(ap, format);
  flags = (p_list *)malloc(sizeof(p_list));
  if (!flags)
    return (-1);
  while (*format)
  {
    if (*format == '%' && *(format + 1) != '%')
    {
      ft_initialise_flags(flags);
    }
    else
      len += write(1, &format, 1);
    format++;
  }
  va_end(ap);
  return (len);
}
*/



/*


  La flag '#' convierte el valor a una "forma alternativa". Para las conversiones x y X,
  se les añade la cadena  "0x" o "OX" al principio si el resultado es distinto de cero.

  La flag '0' coloca ceros en el valor. Para las conversiones d, i, u, x y X el valor
  convertido se rellena a la izquiera con ceros en lugar de espacios en blanco. En el caso
  de que las flags '0' y '-' aparezcan juntas, la flag '0' se ignorará. Si se da una
  precision con la conversion numerica (d, i, u, x, X), la flag '0' es ignorada. Para 
  otras conversiones, su comportamiento es indefinido.

  La flag '-' ajusta el valor convertido a la izquierda del limite de campo. por defecto, 
  estan ajustados a la derecha. El valor convertido se rellena a la derecha con espacios en
  blanco, en lugar de a la izquierda con espacios o ceros. Esta flag sobreescribe al '0' si
  se dan ambos.

  La flag ' ' coloca un espacio antes de un numero positivo o de una cadena vacia producido
  por una conversion con signo.

  La flag '+' coloca un signo (+ o -) antes del numero producido por una conversion con signo.
  Por defecto, el signo se utiliza solo para los numero negativos. Esta flag sobreescribe a la
  del ' ' si aparecen ambas.

  El tamaño minimo se representa como una cadena de difitos decimales (con un primer digito
  distinto de cero) que especifica un ancho de campo minimo. Si el valor convertido tiene menos
  caracteres que el ancho del campo, se rellenara con espacios a la izquierda( o derecha si la 
  flag de ajustar a la izquierda aparece.)

  
*/
