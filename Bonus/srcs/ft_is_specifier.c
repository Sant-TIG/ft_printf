int	ft_is_specifier(char c)
{
	return ((c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'));
}