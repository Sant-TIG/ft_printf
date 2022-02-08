/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:53:15 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 14:55:12 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

void	ft_init_flags(t_bonus *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->width = -1;
	flags->space = 0;
	flags->precision = -1;
	flags->zero = 0;
	flags->hastack = 0;
	flags->sign = 0;
}

void	ft_init_struct(t_bonus *flags)
{
	flags->len = 0;
	flags->id = 0;
}
