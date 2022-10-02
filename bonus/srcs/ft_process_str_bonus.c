/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:48:47 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/11 10:23:21 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

void	ft_process_str(char *str, t_bonus *flags)
{
	char	*temp;

	if (!str)
		temp = ft_strndup("(null)", 6);
	else
		temp = ft_strndup(str, ft_strlen(str));
	if (flags->precision == 0)
	{
		free(temp);
		temp = ft_strndup("", 0);
	}
	else if (flags->precision < ft_strlen(temp) && flags->precision != -1)
		temp = ft_process_precision(temp, flags);
	if (flags->minus == 1 && flags->width == -1)
		flags->len += ft_putstr(temp) + ft_process_width (temp, flags);
	else if (flags->width > 0)
	{
		if (flags->minus == 1)
			flags->len += ft_putstr(temp) + ft_process_width (temp, flags);
		else
			flags->len += ft_process_width (temp, flags) + ft_putstr(temp);
	}
	else
		flags->len += ft_putstr(temp);
	free(temp);
}
