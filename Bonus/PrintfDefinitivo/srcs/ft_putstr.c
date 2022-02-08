/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:55:16 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/08 18:33:33 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"
#include <unistd.h>

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}
