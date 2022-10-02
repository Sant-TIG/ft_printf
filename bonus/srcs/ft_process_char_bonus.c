/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:45:16 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/11 10:24:10 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

void	ft_process_char(int c, t_bonus *flags)
{
	if (flags->width > 0)
	{
		if (flags->minus == 1)
			flags->len += ft_putchar(c) + ft_process_width ("", flags);
		else
			flags->len += ft_process_width("", flags) + ft_putchar(c);
	}
	else if (flags->minus == 1)
		flags->len += ft_putchar(c) + ft_process_width ("", flags);
	else
		flags->len += ft_putchar(c);
}
