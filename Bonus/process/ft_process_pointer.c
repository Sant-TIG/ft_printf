/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:14:50 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 18:14:57 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_process_pointer(size_t hex, t_bonus *flags)
{
    char	*hex_str;

	hex_str = ft_hextoa(hex, flags);
    if (flags->width > 0)
    {
        if (flags->minus == 1)
            flags->len += ft_putstr("0x") + ft_putstr(hex_str) + ft_process_width(hex_str, flags);
        else
            flags->len += ft_process_width(hex_str, flags) + ft_putstr("0x") + ft_putstr(hex_str);
    }
    else
	    flags->len += ft_putstr("0x") + ft_putstr(hex_str);
    free(hex_str);
}
