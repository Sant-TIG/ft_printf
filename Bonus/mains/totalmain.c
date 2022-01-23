#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	ft_str_bonus_test(char *str)
{
	printf("\033[0;33m\n");
	printf("\n   ----- %s CASE -----    \n", str);
	printf("\033[0m");
	int orlen = printf("\nOR --> %%10s = %10s | %%3s = %3s |\n", str, str);
	int ftlen = ft_printf("FT --> %%10s = %10s | %%3s = %3s |\n", str, str);
	orlen += printf("OR --> %%-10s = %-10s | %%-3s = %-3s | %%-s = %-s |\n", str, str, str);
	ftlen += ft_printf("FT --> %%-10s = %-10s | %%-3s = %-3s | %%-s = %-s |\n", str, str, str);
	orlen = printf("\nOR --> %%10.3s = %10.3s | %%3.10s = %3.10s | %%.s = %.s|\n", str, str, str);
	//ftlen = ft_printf("FT --> %%10.3s = %10.3s | %%3.10s = %3.10s | %%0.s = %0.s|\n", str, str, str);	
	orlen += printf("OR --> %%-10.3s = %-10.3s | %%-3.10s = %-3.10s | %%-.0s = %-.0s |\n", str, str, str);
	//ftlen += ft_printf("FT --> %%-10.3s = %-10.3s | %%-3.10s = %-3.10s | %%-.0s = %-.0s |\n", str, str, str);
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

int	ft_char_bonus_test(int c)
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

int	ft_char_mandatory_test()
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
		printf ("\033[0;31m\n");
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
	result = ft_char_mandatory_test();
	ft_check_result(result);
	printf("\033[0;33m\n");
	ft_printf("\n--- CHARACTER BONUS TEST ---\n");
	printf("\033[0m");
	result = ft_char_bonus_test('a');
	ft_check_result(result);
	result = ft_char_bonus_test('1');
	ft_check_result(result);
	result = ft_char_bonus_test('\0');
	ft_check_result(result);
	result = ft_char_bonus_test('0' - 256);
	ft_check_result(result);
	result = ft_char_bonus_test('9' + 256);
	ft_check_result(result);
	result = ft_char_bonus_test(-1);
	ft_check_result(result);
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