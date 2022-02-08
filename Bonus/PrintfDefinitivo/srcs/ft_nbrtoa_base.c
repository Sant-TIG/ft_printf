#include "../incs/ft_printf_bonus.h"

static size_t	ft_nbrlen(size_t nbr, t_bonus *flags)
{
	size_t	nbr_len;

	nbr_len = 0;
	while (nbr > 0)
	{
		nbr /= flags->base_len;
		nbr_len++;
	}
	return (nbr_len);
}

static char	*ft_charconv(char *str, size_t nbr, t_bonus *flags, char *base)
{
	if (nbr == 0)
	{
		*str = base[nbr % flags->base_len];
		return (str);
	}
	while (nbr > 0)
	{
		*(str + flags->nbr_len--) = base[nbr % flags->base_len];
		nbr /= flags->base_len;
	}
	return (str);
}

char	*ft_nbrtoa_base(size_t nbr, t_bonus *flags, char *base)
{
	char	*nbr_str;

	//printf("base = %s\n", base);
	flags->base_len = ft_strlen(base);
	//printf("base_len = %zu\n", flags->base_len);
	flags->nbr_len = ft_nbrlen(nbr, flags);
	//printf("nbr_len = %zu\n", flags->nbr_len);
	nbr_str = (char *)malloc(sizeof(char) * (flags->nbr_len) + 1);
	if (!nbr_str)
		return (NULL);	
	*(nbr_str + flags->nbr_len--) = '\0';
	//printf("nbr_len = %zu\n", flags->nbr_len);
	nbr_str = ft_charconv(nbr_str, nbr, flags, base);
	return(nbr_str);
}