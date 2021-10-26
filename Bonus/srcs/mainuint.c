#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	printf("\n-----UNSIGNED INTEGER CASES-----\n");
	printf("42\n");
	printf("Or --> %%u == %u|\n", 42); 
	ft_printf("FT --> %%u == %u|\n", 42);
	//printf("Or --> %%+u == %+u|\n", 42); //el mas no afecta a unsigned int
	printf("Or --> %%0u == %0u|\n", 42);
	ft_printf("FT --> %%0u == %0u|\n", 42);
	printf("Or --> %%010u == %010u|\n", 42);
	ft_printf("FT --> %%010u == %010u|\n", 42);
	printf("Or --> %%+010u == %+010u|\n", 42);
	ft_printf("FT --> %%+010u == %+010u|\n", 42);
	printf("Or --> %%-010u == %-010u|\n", 42);
	ft_printf("FT --> %%-010u == %-010u|\n", 42);
	printf("Or --> %%0-10u == %0-10u|\n", 42);
	ft_printf("FT --> %%0-10u == %0-10u|\n", 42);
	printf("Or --> %%-+0-10u == %-+0-10u|\n", 42); // si aparece - tanto 0 como + se omiten
	ft_printf("FT --> %%-+0-10u == %-+0-10u|\n", 42);
	printf("Or --> %%10u == %10u|\n", 42);
	ft_printf("FT --> %%10u == %10u|\n", 42);
	printf("Or --> %%+10u == %+10u|\n", 42);
	ft_printf("FT --> %%+10u == %+10u|\n", 42);
	printf("Or --> %%-10u == %-10u|\n", 42);
	ft_printf("FT --> %%-10u == %-10u|\n", 42);
	printf("Or --> %%+--+10u == %+--+10u|\n", 42);
	ft_printf("FT --> %%+--+10u == %+--+10u|\n", 42);
	printf("-42\n");
	printf("Or --> %%u == %u|\n", -42);
	ft_printf("FT --> %%u == %u|\n", -42);
	printf("Or --> %%0u == %0u|\n", -42);
	ft_printf("FT --> %%0u == %0u|\n", -42);
	printf("Or --> %%010u == %010u|\n", -42);
	ft_printf("FT --> %%010u == %010u|\n", -42);
	printf("Or --> %%+010u == %+010u|\n", -42);
	ft_printf("FT --> %%+010u == %+010u|\n", -42);
	printf("Or --> %%-010u == %-010u|\n", -42);
	ft_printf("FT --> %%-010u == %-010u|\n", -42);
	printf("Or --> %%0-10u == %0-10u|\n", -42);
	ft_printf("FT --> %%0-10u == %0-10u|\n", -42);
	printf("Or --> %%-+0-10u == %-+0-10u|\n", -42); // si aparece - tanto 0 como + se omiten
	ft_printf("FT --> %%-+0-10u == %-+0-10u|\n", -42);
	printf("-42\n");

	printf("Or --> Kashim a %u histoires à raconter\n", 1001);
	ft_printf("FT --> Kashim a %u histoires à raconter\n", 1001);
	printf("Or --> Il fait au moins %u\n", -8000);
	ft_printf("FT --> Il fait au moins %u\n", -8000);
	printf("Or --> %u\n", -0);
	ft_printf("FT --> %u\n", -0);
	printf("Or --> %u\n", 0);
	ft_printf("FT --> %u\n", 0);
	printf("Or --> %u\n", INT_MAX);
	ft_printf("FT --> %u\n", INT_MAX);
	printf("Or --> %u\n", INT_MIN);
	ft_printf("FT --> %u\n", INT_MIN);
	printf("Or --> %u\n", INT_MIN - 1);
	ft_printf("FT --> %u\n", INT_MIN - 1);
	printf("Or --> %u\n", INT_MAX + 1);
	ft_printf("FT --> %u\n", INT_MAX + 1);
	printf("Or --> %%u 0000042 == |%u|\n", 0000042);
	ft_printf("FT --> %%u 0000042 == |%u|\n", 0000042);
	printf("Or --> %%u \t == |%u|\n", '\t');
	ft_printf("FT --> %%u \t == |%u|\n", '\t');
	printf("Or --> %%u Lydie == |%u|\n", 'L'+ 'y' + 'd' + 'i' + 'e');
	ft_printf("FT --> %%u Lydie == |%u|\n", 'L'+ 'y' + 'd' + 'i' + 'e');
}