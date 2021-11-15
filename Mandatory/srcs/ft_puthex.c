/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:46:24 by sperez-p          #+#    #+#             */
/*   Updated: 2021/11/12 17:02:58 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/ft_printf.h"

int	ft_puthex(size_t adr, char c)
{
	int	len;

	len = 0;
	if (c == 'x' || c == 'p')
	{
		if (adr >= 16)
			len += ft_puthex(adr / 16, c);
		len += ft_putchar(LOWXBASE[adr % 16]);
		return (len);
	}
	if (c == 'X')
	{
		if (adr >= 16)
			len += ft_puthex(adr / 16, c);
		len += ft_putchar(UPPERXBASE[adr % 16]);
		return (len);
	}
	return (0);
}
