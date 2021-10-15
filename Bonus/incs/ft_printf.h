/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:13:10 by sperez-p          #+#    #+#             */
/*   Updated: 2021/10/14 17:16:03 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define XBASE "0123456789abcdef"
# define BASEX "0123456789ABCDEF"

# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putlchar(char c);
int		ft_putlstr(char *str);
int		ft_putlnbr(int nbr);
int		ft_putlunbr(unsigned int unbr);
int		ft_putlhex(size_t adr, char c);
size_t	ft_strlen(char *str);

#endif
