#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define LOWERXBASE "0123456789abcdef"
# define UPPERXBASE "0123456789ABCDEF"

typedef struct s_bonus
{
	char	id;
	int		len;
	int		plus;
	int		minus;
	int		width;
	int		space;
	int		precision;
	int		zero;
	int		hastack;
	
} t_bonus;

#endif
