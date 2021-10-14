/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:37:52 by sperez-p          #+#    #+#             */
/*   Updated: 2021/10/14 15:38:20 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	str_len;

	str_len = 0;
	while (*str++)
		str_len++;
	return(str_len);
}
