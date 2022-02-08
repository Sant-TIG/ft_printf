#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	ft_uint_bonus_test(unsigned int unbr)
{  	
	printf("\n----- %u CASE -----\n", unbr);
	int orlen = printf("\nOR --> %%10u = %10u | %%5u = %5u | %%1u = %1u |\n", unbr, unbr, unbr);
	int ftlen = ft_printf("FT --> %%10u = %10u | %%5u = %5u | %%1u = %1u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%-10u = %-10u | %%-5u = %-5u | %%-u = %-u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%-10u = %-10u | %%-5u = %-5u | %%-u = %-u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%-10.5u = %-10.5u | %%-5.10u = %-5.10u | %%-.u = %-.u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%-10.5u = %-10.5u | %%-5.10u = %-5.10u | %%-.u = %-.u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%10.5u = %10.5u | %%5.10u = %5.10u | %%.u = %.u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%10.5u = %10.5u | %%5.10u = %5.10u | %%.u = %.u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%10.0u = %10.0u | %%.10u = %.10u | %%.0u = %.0u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%10.0u = %10.0u | %%.10u = %.10u | %%.0u = %.0u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%010u = %010u | %%07u = %07u | %%0u = %0u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%010u = %010u | %%07u = %07u | %%0u = %0u |\n", unbr, unbr, unbr);
	printf("Printf: %d Ft_printf: %d\n", --orlen, ftlen);
	if (orlen == ftlen)
		return (1);
	return (0);
}

int	ft_uint_mandatory_test()
{
	int	orlen = printf("\nOR --> %u , %u , %u, %u |\n", -1, 0, 1, 42);
	int ftlen = ft_printf("FT --> %u , %u , %u, %u |\n", -1, 0, 1, 42);
	orlen += printf("OR --> %u , %u, %u |\n", INT_MAX, INT_MIN, UINT_MAX);
	ftlen += ft_printf("FT --> %u , %u, %u |\n", INT_MAX, INT_MIN, UINT_MAX);
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

int	main()
{
	int result;
	printf("\033[0;33m\n");
	ft_printf("--- UNSIGNED INT MANDATORY TEST ---\n");
	printf("\033[0m");
	result = ft_uint_mandatory_test();
	ft_check_result(result);
	printf("\033[0;33m\n");
	ft_printf("\n--- UNSIGNED INT BONUS TEST ---\n");
	printf("\033[0m");
	result = ft_uint_bonus_test(0);
	ft_check_result(result);
	result = ft_uint_bonus_test(42);
	ft_check_result(result);
	result = ft_uint_bonus_test(INT_MIN);
	ft_check_result(result);
	result = ft_uint_bonus_test(UINT_MAX);
	ft_check_result(result);
	return (0);

}/*
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
}*/
/*
int	main()
{
	printf("%u |\n", 3000);
	printf("%.u |\n", 3000);
	printf("%.02u |\n", 3000);
	printf("%.2u |\n", 3000);
	printf("%.4u |\n", 3000);
	printf("%.10u |\n", 3000);
	printf("%u |\n", 3000);
	printf("%2u |\n", 3000);
	printf("%0u |\n", 3000);
	printf("%4u |\n", 3000);
	printf("%10u |\n", 3000);
	printf("%-u |\n", 3000);
	printf("%-2u |\n", 3000);
	printf("%-0u |\n", 3000);
	printf("%-4u |\n", 3000);
	printf("%-10u |\n", 3000);
	printf("%-u |\n", 3000);
	printf("%-2u |\n", 3000);
	printf("%-0.0u |\n", 3000);
	printf("%-4.5u |\n", 3000);
	printf("%-5.4u |\n", 3000);
	printf("%-10.10u |\n", 3000);
	printf("%-u |\n", 3000);
}*/
/*
int	main()
{
	printf("%d |\n", 3000);
	printf("%.d |\n", 3000);
	printf("%.02d |\n", 3000);
	printf("%.2d |\n", 3000);
	printf("%.4d |\n", 3000);
	printf("%.10d |\n", 3000);
	printf("%d |\n", 3000);
	printf("%2d |\n", 3000);
	printf("%0d |\n", 3000);
	printf("%4d |\n", 3000);
	printf("%10d |\n", 3000);
	printf("%d |\n", 3000);
	printf("%02d |\n", 3000);
	printf("%0d |\n", 3000);
	printf("%06d |\n", 3000);
	printf("%010d |\n", 3000);
	printf("--% d |\n", 3000);
	printf("% 2d |\n", 3000);
	printf("%   0d |\n", 3000);
	printf("% 06d |\n", 3000);
	printf("%   10d |\n", 3000);
	printf("%-d |\n", 3000);
	printf("%-2d |\n", 3000);
	printf("%-0d |\n", 3000);
	printf("%-4d |\n", 3000);
	printf("%-10d |\n", 3000);
	printf("%-d |\n", 3000);
	printf("%-2d |\n", 3000);
	printf("%-0.0d |\n", 3000);
	printf("%-4.5d |\n", 3000);
	printf("%-5.4d |\n", 3000);
	printf("%-10.10d |\n", 3000);
	printf("%-d |\n", 3000);
	printf("%0.0d |\n", 3000);
	printf("%4.5d |\n", 3000);
	printf("%5.4d |\n", 3000);
	printf("%10.10d |\n", 3000);
	printf("%d |\n", 3000);

}*/
#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	ft_uint_bonus_test(unsigned int unbr)
{  	
	printf("\n----- %u CASE -----\n", unbr);
	int orlen = printf("\nOR --> %%10u = %10u | %%5u = %5u | %%1u = %1u |\n", unbr, unbr, unbr);
	int ftlen = ft_printf("FT --> %%10u = %10u | %%5u = %5u | %%1u = %1u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%-10u = %-10u | %%-5u = %-5u | %%-u = %-u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%-10u = %-10u | %%-5u = %-5u | %%-u = %-u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%-10.5u = %-10.5u | %%-5.10u = %-5.10u | %%-.u = %-.u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%-10.5u = %-10.5u | %%-5.10u = %-5.10u | %%-.u = %-.u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%10.5u = %10.5u | %%5.10u = %5.10u | %%.u = %.u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%10.5u = %10.5u | %%5.10u = %5.10u | %%.u = %.u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%10.0u = %10.0u | %%.10u = %.10u | %%.0u = %.0u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%10.0u = %10.0u | %%.10u = %.10u | %%.0u = %.0u |\n", unbr, unbr, unbr);
	orlen += printf("OR --> %%010u = %010u | %%07u = %07u | %%0u = %0u |\n", unbr, unbr, unbr);
	ftlen += ft_printf("FT --> %%010u = %010u | %%07u = %07u | %%0u = %0u |\n", unbr, unbr, unbr);
	printf("Printf: %d Ft_printf: %d\n", --orlen, ftlen);
	if (orlen == ftlen)
		return (1);
	return (0);
}

int	ft_uint_mandatory_test()
{
	int	orlen = printf("\nOR --> %u , %u , %u, %u |\n", -1, 0, 1, 42);
	int ftlen = ft_printf("FT --> %u , %u , %u, %u |\n", -1, 0, 1, 42);
	orlen += printf("OR --> %u , %u, %u |\n", INT_MAX, INT_MIN, UINT_MAX);
	ftlen += ft_printf("FT --> %u , %u, %u |\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("Printf: %d Ft_printf: %d\n", --orlen, ftlen);
	if (orlen == ftlen)
		return (1);
	return (0);
}

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
	ftlen = ft_printf("FT --> %%10.3s = %10.3s | %%3.10s = %3.10s | %%.s = %.s|\n", str, str, str);	
	orlen += printf("OR --> %%-10.3s = %-10.3s | %%-3.10s = %-3.10s | %%-.0s = %-.0s |\n", str, str, str);
	ftlen += ft_printf("FT --> %%-10.3s = %-10.3s | %%-3.10s = %-3.10s | %%-.0s = %-.0s |\n", str, str, str);
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
	printf("\033[0;33m\n");
	ft_printf("--- UNSIGNED INT MANDATORY TEST ---\n");
	printf("\033[0m");
	result = ft_uint_mandatory_test();
	ft_check_result(result);
	printf("\033[0;33m\n");
	ft_printf("\n--- UNSIGNED INT BONUS TEST ---\n");
	printf("\033[0m");
	result = ft_uint_bonus_test(0);
	ft_check_result(result);
	result = ft_uint_bonus_test(42);
	ft_check_result(result);
	result = ft_uint_bonus_test(INT_MIN);
	ft_check_result(result);
	result = ft_uint_bonus_test(UINT_MAX);
	ft_check_result(result);
	return (0);
}
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