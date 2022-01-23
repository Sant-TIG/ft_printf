#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	ft_bonus_test(int c)
{
	printf("\033[0;33m\n");
	printf("     ----- %c CASE -----    \n", c);
	printf("\033[0m");
	int orlen = printf("\nOR --> %%10c = %10c | %%3c = %3c |\n", c, c);
	int ftlen = ft_printf("FT --> %%10c = %10c | %%3c = %3c |\n", c, c);
	orlen += printf("OR --> %%-10c = %-10c | %%-3c = %-3c | %%-c = %-c |\n", c, c, c);
	ftlen += ft_printf("FT --> %%-10c = %-10c | %%-3c = %-3c | %%-c = %-c |\n", c, c, c);
	printf("Printf: %d Ft_printf: %d\n", --orlen, ftlen);
	if (orlen == ftlen)
		return (1);
	return (0);
}

int	ft_mandatory_test()
{
	int	orlen = printf("\nOR --> %c , %c , %c|\n", 'a', '1', '\0');
	int ftlen = ft_printf("FT --> %c , %c , %c|\n", 'a', '1', '\0');
	orlen += printf("OR --> %c , %c , %c, %c|\n", 'Z', '0' - 256, '9' + 256, ' ');
	ftlen += ft_printf("FT --> %c , %c , %c, %c|\n", 'Z', '0' - 256, '9' + 256, ' ');
	printf("Printf: %d Ft_printf: %d\n", --orlen, ftlen);
	if (orlen == ftlen)
		return (1);
	return (0);
}

void ft_check_result(int n)
{
	if (n == 1)
	{
		printf ("\033[0;32m");
		printf("OK\n");
	}
	else
	{
		printf ("\033[0;31m");
		ft_printf("KO\n");
	}
	printf("\033[0m");
}

int main()
{
	int	result;
	printf("\033[0;33m\n");
	ft_printf("--- CHARACTER MANDATORY TEST ---\n");
	printf("\033[0m");
	result = ft_mandatory_test();
	ft_check_result(result);
	printf("\033[0;33m\n");
	ft_printf("\n--- CHARACTER BONUS TEST ---\n");
	printf("\033[0m");
	result = ft_bonus_test('a');
	ft_check_result(result);
	result = ft_bonus_test('1');
	ft_check_result(result);
	result = ft_bonus_test('\0');
	ft_check_result(result);
	result = ft_bonus_test('0' - 256);
	ft_check_result(result);
	result = ft_bonus_test('9' + 256);
	ft_check_result(result);
	result = ft_bonus_test(-1);
	ft_check_result(result);
	printf("%c", 'c');
	//printf(" %2413124.335 d");
	return (0);
}