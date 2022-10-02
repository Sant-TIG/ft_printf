/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:05:03 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/11 10:24:48 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

size_t	ft_nbrlen(size_t nbr, t_bonus *flags)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= flags->base_len;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_charconv(char *str, size_t nbr, t_bonus *flags, char *base)
{
	if (nbr == 0)
	{
		*str = base[nbr % flags->base_len];
		return (str);
	}
	while (nbr > 0)
	{
		*(str + flags->nbr_len--) = base[nbr % flags->base_len];
		nbr /= flags->base_len;
	}
	return (str);
}

char	*ft_nbrtoa_base(size_t nbr, t_bonus *flags, char *base)
{
	char	*nbr_str;

	flags->base_len = ft_strlen(base);
	flags->nbr_len = ft_nbrlen(nbr, flags);
	nbr_str = (char *)malloc(sizeof(char) * (flags->nbr_len) + 1);
	if (!nbr_str)
		return (NULL);
	*(nbr_str + flags->nbr_len--) = '\0';
	nbr_str = ft_charconv(nbr_str, nbr, flags, base);
	return (nbr_str);
}
