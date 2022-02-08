/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:44:40 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 17:45:08 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	ft_uintlen(unsigned int unbr)
{
	size_t	unbr_len;

	unbr_len = 0;
	while (unbr > 0)
	{
		unbr /= 10;
		unbr_len++;
	}
	return (unbr_len);
}

static char	*ft_charconv(char *dest, unsigned int unbr, size_t unbr_len)
{
	if (unbr == 0)
		*dest = 48;
	while (unbr > 0)
	{
		*(dest + unbr_len--) = 48 + (unbr % 10);
		unbr /= 10;
	}
	return (dest);
}

char	*ft_uitoa(unsigned int unbr)
{
	char	*dest;
	size_t		unbr_len;

	if (unbr == 0)
	{
		dest = malloc(2);
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	unbr_len = ft_uintlen(unbr);
	dest = (char *)malloc(sizeof(char) * unbr_len + 1);
	if (!dest)
		return (NULL);
	*(dest + unbr_len--) = '\0';
	dest = ft_charconv(dest, unbr, unbr_len);
	return (dest);
}

