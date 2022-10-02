/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision_uint.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:52:13 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/11 10:23:40 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

char	*ft_process_precision_uint(t_bonus *flags, char *unbr_str)
{
	char	*new_nbr_str;
	int		nbr;
	size_t	i;
	size_t	j;

	i = 0;
	nbr = (flags->precision) - ft_strlen(unbr_str);
	nbr += ft_strlen(unbr_str) + 1;
	new_nbr_str = (char *)malloc(sizeof(char) * nbr + 1);
	if (!new_nbr_str)
		return (NULL);
	while (nbr-- > ft_strlen(unbr_str) + 1)
		new_nbr_str[i++] = '0';
	j = 0;
	while (nbr--)
		new_nbr_str[i++] = unbr_str[j++];
	new_nbr_str[i] = '\0';
	free(unbr_str);
	return (new_nbr_str);
}
