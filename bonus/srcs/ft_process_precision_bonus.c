/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:54:45 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/11 10:23:52 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

char	*ft_process_precision(char *str, t_bonus *flags)
{
	char	*prc;
	int		nbr;

	nbr = flags->precision;
	prc = (char *)malloc(sizeof(char) * nbr + 1);
	prc[nbr] = '\0';
	while (nbr-- > 0)
		prc[nbr] = str[nbr];
	free(str);
	return (prc);
}
