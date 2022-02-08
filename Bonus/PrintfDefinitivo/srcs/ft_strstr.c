/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:01:39 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 17:01:51 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strstr(char *str, char *str1)
{
	while (*str && *str1 && *str == *str1)
	{
		str++;
		str1++;
	}
	if (*str != *str1)
		return (0);
	return(1);
}
