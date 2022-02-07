/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_flags_utils1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:25:17 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 16:44:18 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_control_precision(const char **format, t_bonus *flags)
{
	char	*prec_str;

	++*format;
	prec_str = ft_get_precision(*format);
	flags->precision = ft_atoi(prec_str);
	free(prec_str);
	while (ft_isdigit(**format))
		(*format)++;
}

void	ft_control_width(const char **format, t_bonus *flags)
{
	char	*width_str;

	width_str = ft_get_width(*format);
	flags->width = ft_atoi(width_str);
	free(width_str);
	while (ft_isdigit(**format) && *format)
		(*format)++;
}
