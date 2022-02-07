/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:12:48 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 18:12:59 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_process_int(int nbr, t_bonus *flags)
{
	unsigned int unbr;
	char	*unbr_str;

	if (nbr < 0 || nbr == INT_MIN)
	{
		flags->sign = '-';
		flags->plus = 0;
		unbr = nbr * -1;
	}
	else
		unbr = nbr;
	unbr_str = ft_uitoa(unbr);
	if (flags->sign != 0)
		ft_process_negative_int(unbr_str, flags);
	else
	{
		if ((flags->precision == 0 && unbr == 0))
		{
			if (flags->width > 0 || flags->zero == 1)
				flags->len += ft_process_width(unbr_str, flags) + ft_putstr("");
			else
				flags->len += ft_putstr("");
		}
		else 
		{
			if (flags->precision > ft_strlen(unbr_str))
				unbr_str = ft_process_precision_uint(flags, unbr_str);
			if (flags->width > 0)
			{
				if (flags->minus > 0)
					flags->len += ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
				else
					flags->len += ft_process_width(unbr_str, flags) + ft_putstr(unbr_str);
			}
			else if (flags->plus > 0)
				flags->len += ft_putchar('+') + ft_putstr(unbr_str);
			else if (flags->minus > 0)
				flags->len += ft_putstr(unbr_str) + ft_process_width(unbr_str, flags);
			else if (flags->space > 0)
				flags->len += ft_putchar(' ') + ft_putstr(unbr_str);
			else
				flags->len += ft_putstr(unbr_str);
		}
		free(unbr_str);
	}
}
