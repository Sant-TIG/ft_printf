/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:23:28 by sperez-p          #+#    #+#             */
/*   Updated: 2021/10/14 15:45:49 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/ft_printf.h"
#include <unistd.h>

int	ft_putlstr(char *str)
{
	if (!str)
		return(write(1, "(null)", 6));
	return(write(1, str, ft_strlen(str)));
}
