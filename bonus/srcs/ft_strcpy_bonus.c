/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:07:19 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/11 09:33:59 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

char	*ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
