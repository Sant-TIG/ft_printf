/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:09:45 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 18:10:12 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	ft_hexlen(size_t hex)
{
	size_t	hex_len;

	hex_len = 0;
	while (hex > 0)
	{
		hex /= 16;
		hex_len++;
	}
	return (hex_len);
}

static char	*ft_charconv_hex(char *str, size_t unbr, size_t unbr_len, t_bonus *flags)
{
	if (flags->id == 'x' || flags->id == 'p')
	{
		if (unbr == 0)
			*str = LOWERXBASE[unbr % 16];
		while (unbr > 0)
		{
			*(str + unbr_len--) = LOWERXBASE[unbr % 16];
			unbr /= 16;
		}
		return (str);
	}
	if (unbr == 0)
		*str = UPPERXBASE[unbr % 16];
	while (unbr > 0)
	{
		*(str + unbr_len--) = UPPERXBASE[unbr % 16];
		unbr /= 16;
	}
	return (str);
}

char	*ft_hextoa(size_t hex, t_bonus *flags)
{
	char	*hex_str;
	size_t	hex_len;

	hex_len = ft_hexlen(hex);
	hex_str = (char *)malloc(sizeof(char) * hex_len + 1);
	if (!hex_str)
		return (NULL);
	*(hex_str + hex_len--) = '\0';
	hex_str = (ft_charconv_hex(hex_str, hex, hex_len, flags));
	return (hex_str);
}
