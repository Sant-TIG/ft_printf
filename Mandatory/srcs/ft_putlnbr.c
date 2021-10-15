/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:34:43 by sperez-p          #+#    #+#             */
/*   Updated: 2021/10/14 17:06:41 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/ft_printf.h"

int	ft_putlnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (ft_putlstr("-2147483648"));
	if (nbr < 0)
	{
		nbr *= -1;
		len = ft_putlchar('-');
	}
	if (nbr > 9)
		len += ft_putlnbr(nbr / 10);
	len += ft_putlchar((nbr % 10) + 48);
	return (len);
}
