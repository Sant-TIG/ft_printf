/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_flags_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:10:58 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 16:31:43 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

void	ft_control_minus(const char **format, t_bonus *flags)
{
	if (flags->minus == 0)
		flags->minus = 1;
	(*format)++;
}

void	ft_control_plus(const char **format, t_bonus *flags)
{
	if (flags->plus == 0)
		flags->plus = 1;
	(*format)++;
}

void	ft_control_hastack(const char **format, t_bonus *flags)
{
	if (flags->hastack == 0)
		flags->hastack = 1;
	(*format)++;
}

void	ft_control_space(const char **format, t_bonus *flags)
{
	if (flags->plus == 1)
		flags->space = 0;
	else
		flags->space = 1;
	(*format)++;
}
