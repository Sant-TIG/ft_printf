/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:20:24 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 17:34:33 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_get_precision(const char *str)
{
	size_t	i;
	size_t	j;
	char	*dst;
	
	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	dst = (char *)malloc(sizeof(char) * (j + 1));
	dst[j] = '\0';
	while (j-- > 0)
		dst[j] = str[i + j];
	return (dst);
}
