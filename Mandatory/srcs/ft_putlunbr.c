/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:33:54 by sperez-p          #+#    #+#             */
/*   Updated: 2021/10/14 15:38:31 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* **************************************************************************/
#include "../incs/ft_printf.h"

int	ft_putlunbr(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr > 9)
		len += ft_putlunbr(unbr / 10);
	len += ft_putlchar((unbr % 10) + 48);
	return (len);
}
