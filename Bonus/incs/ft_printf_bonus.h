/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:59:57 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 16:06:10 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define LOWERXBASE "0123456789abcdef"
# define UPPERXBASE "0123456789ABCDEF"

# include <stdlib.h>
# include <stdio.h>

typedef struct s_bonus
{
	char	sign;
	int		width;
	char	id;
	int		len;
	int		precision;
	int		zero;
    int     plus;
    int     space;
    int     hastack;
    int     minus;

} t_bonus;

/* FLAFS FUNCTIONS */

void	ft_control_hastack(const char **format, t_bonus *flags);
void	ft_control_hastack(const char **format, t_bonus *flags);
void	ft_control_minus(const char **format, t_bonus *flags);
void	ft_control_plus(const char **format, t_bonus *flags);
void	ft_control_precision(const char **format, t_bonus *flags);
void	ft_control_space(const char **format, t_bonus *flags);
void	ft_control_width(const char **format, t_bonus *flags);
void	ft_control_zero(const char *format, t_bonus *flags);

/* GET FUNCTIONS */

char	*ft_get_precision(const char *str);
char	*ft_get_width(const char *str);

/* INIT FUNCTIONS */

void	ft_init_struct(t_bonus *flags);
void	ft_init_flags(t_bonus *flags);

/* PRINTF FUNCTIONS */

int		ft_printf(const char *format, ...);

/* PROCESS FUNCTIONS */

void	ft_process_char(int c, t_bonus *flags);
void	ft_process_negative_int(char *unbr_str, t_bonus *flags);
char	*ft_process_precision(char *str, t_bonus *flags);
char	*ft_process_precision_uint(t_bonus *flags, char *unbr_str);
void	ft_process_str(char *str, t_bonus *flags);
int		ft_process_width(char*str, t_bonus *flags);

/* UTILS */

int		ft_isdigit(int c);
int		ft_is_specifier(int c);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_strlen(const char *str);
int		ft_strstr(char *str, char *str1);
char	*ft_uitoa(unsigned int unbr);

#endif
