#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	ft_str_bonus_test(char *str)
{  	
	printf("\n----- %s CASE -----\n", str);
	int orlen = printf("\nOR --> %%10s = %10s | %%3s = %3s |\n", str, str);
	int ftlen = ft_printf("FT --> %%10s = %10s | %%3s = %3s |\n", str, str);
	orlen += printf("OR --> %%-10s = %-10s | %%-3s = %-3s | %%-s = %-s |\n", str, str, str);
	ftlen += ft_printf("FT --> %%-10s = %-10s | %%-3s = %-3s | %%-s = %-s |\n", str, str, str);
	printf("Printf: %d Ft_printf: %d\n", --orlen, ftlen);
	if (orlen == ftlen)
		return (1);
	return (0);
}

int	ft_str_mandatory_test()
{
	int	orlen = printf("\nOR --> %s , %s , %s|\n", "", "c", "4");
	int ftlen = ft_printf("FT --> %s , %s , %s|\n", "", "c", "4");
	orlen += printf("OR --> %s , %s|\n", "string ", "string1 y string2");
	ftlen += ft_printf("FT --> %s , %s|\n", "string ", "string1 y string2");
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
	ft_printf("--- STRINGS MANDATORY TEST ---\n");
	printf("\033[0m");
	result = ft_str_mandatory_test();
	ft_check_result(result);
	printf("\033[0;33m\n");
	ft_printf("\n--- STRING BONUS TEST ---\n");
	printf("\033[0m");
	result = ft_str_bonus_test("");
	ft_check_result(result);
	result = ft_str_bonus_test("c");
	ft_check_result(result);
	result = ft_str_bonus_test("4");
	ft_check_result(result);
	result = ft_str_bonus_test("string ");
	ft_check_result(result);
	result = ft_str_bonus_test("string1 y string2");
	ft_check_result(result);
	result = ft_str_bonus_test(NULL);
	ft_check_result(result);
	return (0);
}
