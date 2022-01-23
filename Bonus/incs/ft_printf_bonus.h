#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>

typedef struct s_print
{
	char	sign;
	int		width;
	char	id;
	int		len;
	int		precision;
} t_print;

/* CHAR FUNCTIONS */

int		ft_putchar(int c);
void	ft_process_char(int c, t_print *flags);

/* STRINGS FUNCTIONS */

void	ft_process_string(char *str, t_print *flags);
int		ft_putstr(char *str);

/*CONVERSION FUNCTIONS*/

void	ft_control_conversion(t_print *flags, const char *str);
int		ft_is_specifier(int c);

/* PRINTF FUNCTIONS */

int	ft_printf(const char *format, ...);

/* UTILS FUNCTIONS */

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *str, size_t len);

/* WIDTH FUNCTIONS */

char	*ft_get_width(const char *str);
int		ft_process_width(t_print *flags, char*str);

/* PRECISION FUNCTIONS */

char	*ft_get_precision(const char *str);
int		ft_process_precision(t_print *flags, char*str);

#endif