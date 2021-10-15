/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:46:24 by sperez-p          #+#    #+#             */
/*   Updated: 2021/10/14 18:04:20 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/ft_printf.h"

int	ft_putlhex(size_t adr, char c)
{
	int	len;

	len = 0;
	if (c == 'x' || c == 'p')
	{
		if (adr >= 16)
			len += ft_putlhex(adr / 16, c);
		len += ft_putlchar(XBASE[adr % 16]);
		return (len);
	}
	if (c == 'X')
	{
		if (adr >= 16)
			len += ft_putlhex(adr / 16, c);
		len += ft_putlchar(BASEX[adr % 16]);
		return (len);
	}
	return (0);
}
