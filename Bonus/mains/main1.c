#include "../incs/ft_printf_bonus.h"
#include <stdio.h>

int main()
{
    ft_printf("\n-----CHARACTER CASE-----\n");
    ft_printf("\nPrintf\n");
    int len = printf("%c ... %c\n", 'a', 'Z');
    ft_printf("\nFt_printf\n");
    int len1 = ft_printf("%c ... %c\n", 'a', 'Z');
    ft_printf("\nPrintf\n");
    len += printf("\t%c ... %c\n", '0', '9');
    ft_printf("\nFt_printf\n");
    len1 += ft_printf("\t%c ... %c\n", '0', '9');
    ft_printf("\nPrintf\n");
    len += printf("    %c ... %c\n", '0' + 256, '0' - 256);
    ft_printf("\nFt_printf\n");
    len1 += ft_printf("    %c ... %c\n", '0' + 256, '0' - 256);
    printf("Printf = %d Ft_printf = %d\n", len , len1);
    ft_printf("\n-----CHARACTER BONUS CASE-----\n");
    ft_printf("\nPrintf\n");
    len = printf("%10c ... %10c\n", 'a', 'Z');
    ft_printf("\nFt_printf\n");
    len1 = ft_printf("%10c ... %10c\n", 'a', 'Z');
    ft_printf("\nPrintf\n");
    len += printf("\t%-10c ... %-10c\n", '0', '9');
    ft_printf("\nFt_printf\n");
    len1 += ft_printf("\t%-10c ... %-10c\n", '0', '9');
    ft_printf("\nPrintf\n");
    len += printf("    10%c ... 10%c\n", '0' + 256, '0' - 256);
    ft_printf("\nFt_printf\n");
    len1 += ft_printf("    10%c ... 10%c\n", '0' + 256, '0' - 256);
	printf("Printf = %d Ft_printf = %d\n", len , len1);
	ft_printf("\n-----STRING CASE-----\n");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	printf("\nPrintf = %d Ft_printf = %d\n", len , len1);
	ft_printf("\nPrintf\n");
	len += printf(" %s\n", "c");
	ft_printf("\nFt_printf\n");
	len1 += ft_printf(" %s", "c");
	printf("\nPrintf = %d Ft_printf = %d\n", len , len1);
	ft_printf("\nPrintf\n");
	len += printf(" %s \n", "4");
	ft_printf("\nFt_printf\n");
	len1 += ft_printf(" %s ", "4");
	printf("\nPrintf = %d Ft_printf = %d\n", len , len1);
	ft_printf("\nPrintf\n");
	len += printf("\t%s \n", "cadena");
	ft_printf("\nFt_printf\n");
	len1 += ft_printf("\t%s ", "cadena");
	printf("\nPrintf = %d Ft_printf = %d\n", len , len1);
	ft_printf("\nPrintf\n");
	len += printf("\n10%s10\n", NULL);
	ft_printf("\nFt_printf\n");
	len1 += ft_printf("\n10%s10\n", NULL);
	printf("\nPrintf = %d Ft_printf = %d\n", len , len1);
	/*ft_printf("\n-----STRING BONUS CASE-----\n");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	ft_printf("\nPrintf\n");
	len = printf("%s", "");
	ft_printf("\nFt_printf\n");
	len1 = ft_printf("%s", "");
	printf("Printf = %d Ft_printf = %d\n", len , len1);
	len = printf("Esto es una cadena: %10.4s y esta es otra: %-7.5s y esta es otra: %s|\n", "cadena", "string", NULL);
	len1 = ft_printf("Esto es una cadena: %10.4s y esta es otra: %-7.5s y esta es otra: %s|\n", "cadena", "string", NULL);
	printf ("Printf = %d ft_printf = %d\n", len , len1);
	len = printf("Esto es una cadena: %.4s y esta es otra: %-.5s y esta es otra: %10s|\n", "cadena", "string", NULL);
	len1 = ft_printf("Esto es una cadena: %.4s y esta es otra: %-.5s y esta es otra: %10s|\n", "cadena", "string", NULL);
	printf ("Printf = %d ft_printf = %d", len , len1);*/
	return (0);

}

/*
int main()
{
	int len = printf("Prueba 1:%50c\n", 'a');
	int len1 = ft_printf("Prueba 1:%50c\n", 'a');
	printf("%d\t%d\n", len, len1);
	len = printf("Prueba 2:%-50c\n", 'a');
	len1 = ft_printf("Prueba 2:%-50c\n", 'a');
	printf("%d\t%d\n", len, len1);
	printf("%10s, %6s, %4s, %0s, %s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	printf("%-10s, %-6s, %-4s, %-0s, %-s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	printf("%.10s, %.6s, %.4s, %.0s, %.s|\n", "cadena", "cadena", "cadena", "cadena");	
	printf("%-.10s, %-.6s, %-.4s, %-.0s, %-.s|\n", "cadena", "cadena", "cadena", "cadena");
	printf("%10.10s, %6.6s, %4.4s, %0.0s, %10.s|\n", "cadena", "cadena", "cadena", "cadena");
	printf("%-10.10s, %-6.6s, %-4.4s, %-0.0s, %-10.s|\n", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%10s, %6s, %4s, %0s, %s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%-10s, %-6s, %-4s, %-0s, %-s|\n", "cadena", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%.10s, %.6s, %.4s, %.0s, %.s|\n", "cadena", "cadena", "cadena", "cadena");	
	ft_printf("%-.10s, %-.6s, %-.4s, %-.0s, %-.s|\n", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%10.10s, %6.6s, %4.4s, %0.0s, %10.s|\n", "cadena", "cadena", "cadena", "cadena");
	ft_printf("%-10.10s, %-6.6s, %-4.4s, %-0.0s, %-10.s|\n", "cadena", "cadena", "cadena", "cadena");

}*/
/*
int main()
{
	ft_printf("\n---CHARACTER CASE---\n");
	int len = printf("Printf: Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z',  '0' - 256, '0' + 256, ' ');
	int len1 = ft_printf("Ft_printf: Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z', '0' - 256, '0' + 256, ' ');
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
	ft_printf("\n---CHARACTER CASE BONUS---\n");
	ft_printf("\n --SIMPLE FLAGS TESTS-- \n");
	len += printf("Printf: %#c\n", 'a');
	len += printf("Printf: %0c\n", 'a');
	len += printf("Printf: %-c\n", 'a');
	len += printf("Printf: % c\n", 'a');
	len += printf("Printf: %+c\n", 'a');
	len += printf("Printf: %50c\n", 'a');
	len += printf("Printf: %.c\n", 'a');
	ft_printf("\n --MIXED FLAGS TESTS-- \n");
	len += printf("Printf1: %50.c\n", 'a');
	len += printf("Printf2: %50.4c\n", 'a');
	len += printf("Printf3: %.50c\n", 'a');
	len += printf("Printf4: %5.50c\n", 'a');
	len += printf("Printf5: % 50c\n", 'a');
	len += printf("Printf6: %+50c\n", 'a');
	len += printf("Printf7: %050c\n", 'a');
	len += printf("Printf8: %#50c\n", 'a');
	len += printf("Printf9: %-50c\n", 'a');
	len += printf("Printf10: %50c\n", 'a');
	len += printf("Printf11: %#050c\n", 'a');
	len += printf("Printf12: %#-50c\n", 'a');
	len += printf("Printf13: %# 50c\n", 'a');
	len += printf("Printf14: %#+50c\n", 'a');
	len += printf("Printf15: %#.50c\n", 'a');
	len += printf("Printf16: %+ -0#50c\n", 'a');

	len += ft_printf("Printf1: %50.c\n", 'a');
	len += ft_printf("Printf2: %50.4c\n", 'a');
	len += ft_printf("Printf3: %.50c\n", 'a');
	len += ft_printf("Printf4: %5.50c\n", 'a');
	len += ft_printf("Printf5: % 50c\n", 'a');
	len += ft_printf("Printf6: %+50c\n", 'a');
	len += ft_printf("Printf7: %050c\n", 'a');
	len += ft_printf("Printf8: %#50c\n", 'a');
	len += ft_printf("Printf9: %-50c\n", 'a');
	len += ft_printf("Printf10: %50c\n", 'a');
	len += ft_printf("Printf11: %#050c\n", 'a');
	len += ft_printf("Printf12: %#-50c\n", 'a');
	len += ft_printf("Printf13: %# 50c\n", 'a');
	len += ft_printf("Printf14: %#+50c\n", 'a');
	len += ft_printf("Printf15: %#.50c\n", 'a');
	len += ft_printf("Printf16: %+ -0#50c\n", 'a');
	
	len += printf("Printf: %.#0- +.50c.\n", 'a');
	len += printf("Printf: %#0 +50.c\n", 'a');
	//len1 += ft_printf("%#c\n", 'a');
	//len1 += ft_printf("%0c\n", 'a');
	//len1 += ft_printf("%-c\n", 'a');
	//len1 += ft_printf("% c\n", 'a');
	//len1 += ft_printf("%+c\n", 'a');
	//len1 += ft_printf("%.c\n", 'a');
	len1 += ft_printf("Ft_printf: %-50c\n", 'a');
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
}*/
