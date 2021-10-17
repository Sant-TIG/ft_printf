#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

#include <unistd.h> 

typedef struct printf_flags
{
	int	sharp;	//#
	int	zero;	//0
	int minus;	//-
	int spc;	//space
	int	plus;	//+
	int width;	//width
	int	prc;	//precision
}	p_list;

int ft_printf(const char *format, ...);
int	ft_putlchar_bonus(int c, char *format, int len);

#endif
