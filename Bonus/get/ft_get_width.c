/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:16:47 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 17:20:14 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_width(const char *str)
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
	if (!dst)
		return (NULL);
	dst[j] = '\0';
	while (j--)
		dst[j] = str[i + j];
	return (dst);
}
