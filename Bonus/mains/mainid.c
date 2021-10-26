#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

//la precision devuelve el minimo numero de digitos que deben aparecer. Si el valor convertido requiere
//menos digitos, se rellena a la izquierda con ceros-. Por defecto la precision es 1. Si es 0, la salida es vacia.
//LONG_MIN INT_MIN -101 -100 - 99 -42 -11 -10 -9 -1 0 1 9 10 11 42 99 100 101INT_MAX LONG_MAX UINT_MAX ULONG_MAX 9223372036854775807LL
int main()
{
	printf("%%d y %%i          | %d y %i\n", 42, -42);
	printf("%% d y %% i        | % d y % i\n", 42, -42); // con el menos le espacio no hace nada
	printf("%%.d y %%.i        | %.d y %.i\n", 42, -42);
	printf("%%-d y %%-i        | %-d y %-i\n", 42, -42); // el menos sin un numero detras no hace nada
	printf("%%+d y %%+i        | %+d y %+i\n", 42, -42); // el mas coloca un signo positivo delante de un numero positivo
	printf("%%5d y %%5i        | %5d y %5i\n", 42, -42); // width actua como siempre si esta solo
	printf("%%-5d y %%-5i      | %-5d y %-5i\n", 42, -42); // la combinacion de width con - actua como siempre
	printf("%%+5d y %%+5i      | %+5d y %+5i\n", 42, -42);
	printf("%%-5.d y %%+5.i    | %-5.d y %+5.i\n", 42, -42);
	printf("%%+5.0d y %%-5.0i  | %+5.0d y %-5.0i\n", 42, -42);
	printf("%%-5.5d y %%+5.5i  | %-5.5d y %+5.5i\n", 42, -42); // si width y precision los espacios son 
	//printf("% +5.5d y % -5.5i\n", 42, -42); //' ' flag ignored with '+' flag
	printf("%%+5.5d y %% -5.5i | %+5.5d y % -5.5i\n", 42, -42);
	//printf("%0-5.5d y %0+5.5i\n", 42, -42); // '0' flag ignores with precision and %d format
	printf("%% -3.3d y %%+3.3i | % -13.3d y %+13.3i\n", 42, -42);
	printf("%% 03d y %% +03i   | % 03d y %+03i\n", 42, -42);
	printf("%% .03d y %% .03i  | % .03d y % .03i\n", 42, -42);

	/* si aparecen el '0' y el '-' el 0 es ignorado. Si se da una precision con un conversor numerico
	(d, i , o, u, x,X) el '0' es ignorado.
//	ft_printf("\n-----SIGNED DECIMAL INTEGER TEST-----\n");
	printf("Printf   : %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf   : %i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	//ft_printf("Ft_printf: %d\t %d\t %d\t %d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10);
	//printf("Printf: %d Ft_printf: %d");
//	ft_printf("\n-----SIGNED DECIMAL INTEGER BONUS TEST-----\n");
	printf("Printf   : % d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : % d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\t% d\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf   : % i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : % i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\t% i\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	
	printf("Printf   : %+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\t%+d\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf   : %+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %+i\t%+i\t%-i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\t%+i\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);

	printf("Printf   : %-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t%-d\t% d\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf   : %-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t% i\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t%-i\t% i\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	
	printf("Printf   : %-10d\t%-8d\t%-6d\t%-4d\t%-2d\t%-0d\t%-2d\t%-4d\t%-6d\t%-8d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %-10d\t%-8d\t%-6d\t%-4d\t%-2d\t%-0d\t%-2d\t%-4d\t%-6d\t%-8d\t%-10d\t%-12d\t%-14d\t%-16d\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf   : %-10i\t%-8i\t%-6i\t%-4i\t%-2i\t%-0i\t%-2i\t%-4i\t%-6i\t%-8i\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %-10i\t%-8i\t%-6i\t%-4i\t%-2i\t%-0i\t%-2i\t%-4i\t%-6i\t%-8i\t%-10i\t%-12i\t%-14i\t%-16i\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	
	printf("Printf   : %.10d\t%.8d\t%.6d\t%.4d\t%.2d\t%.0d\t%.2d\t%.4d\t%.6d\t%.8d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %.10d\t%.8d\t%.6d\t%.4d\t%.2d\t%.0d\t%.2d\t%.4d\t%.6d\t%.8d\t%.10d\t%.12d\t%.14d\t%.16d\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf   : %.10i\t%.8i\t%.6i\t%.4i\t%.2i\t%.0i\t%.2i\t%.4i\t%.6i\t%.8i\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %.10i\t%.8i\t%.6i\t%.4i\t%.2i\t%.0i\t%.2i\t%.4i\t%.6i\t%.8i\t%.10i\t%.12i\t%.14i\t%.16i\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	
	printf("Printf   : %010d\t%08d\t%06d\t%04d\t%02d\t%0d\t%02d\t%04d\t%06d\t%08d\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %010d\t%08d\t%06d\t%04d\t%02d\t%0d\t%02d\t%04d\t%06d\t%08d\t%010d\t%012d\t%014d\t%016d\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf   : %010i\t%08i\t%06i\t%04i\t%02i\t%0i\t%02i\t%04i\t%06i\t%08i\n", LONG_MIN, INT_MIN, -101, -100, -99, -42, -11, -10, -9, -1);
	printf("Printf   : %010i\t%08i\t%06i\t%04i\t%02i\t%0i\t%02i\t%04i\t%06i\t%08i\t%010i\t%012i\t%014i\t%016i\n", 0, 1, 9, 10, 11, 42, 99, 100, 101, INT_MAX, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);

//	ft_printf("Ft_printf: % d\t% d\t% d\t% d\n", LONG_MIN, INT_MIN, -101, -100,-99, -42, -11, -10);
	return (0);*/
}