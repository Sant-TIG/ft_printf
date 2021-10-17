#include <stdio.h>
#include "../incs/ft_printf_bonus.h"

int main()
{
	printf("%-50c\n", 'a');
	printf("%050c\n", 'a');
	printf("%#c\n", 'a');
	printf("%0c\n", 'a');
	printf("%+c\n", 'a');
	printf("% c\n", 'a');
	printf("%.c\n", 'a');
	ft_printf("%-50c\n", 'a');
	ft_printf("%050c\n", 'a');
	ft_printf("%#c\n", 'a');
	ft_printf("%0c\n", 'a');
	ft_printf("%+c\n", 'a');
	ft_printf("% c\n", 'a');
	ft_printf("%.c\n", 'a');
	return (0);	
}

/*
int main()
{
	int	len = 0, len1 = 0;

	printf("\n--- + FLAG ---\n");
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%+d, %+d, %+d, %+d, %+d, %+d, %+d, %+d, %+d, %+d, %+d\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%+i, %+i, %+i, %+i, %+i, %+i, %+i, %+i, %+i, %+i, %+i\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("\n--- - FLAG ---\n");
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%-d, %-d, %-d, %-d, %-d, %-d, %-d, %-d, %-d, %-d, %-d\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%-i, %-i, %-i, %-i, %-i, %-i, %-i, %-i, %-i, %-i, %-i\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("\n--- 0 FLAG ---\n");
	printf("%01d, %03d, %05d, %07d, %09d, %01d, %011d, %013d, %015d, %017d, %019d\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%01i, %03i, %05i, %07i, %09i, %01i, %011i, %013i, %015i, %017i, %019i\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%01u, %03u, %05u, %07u, %09u, %01u, %011u, %013u, %015u, %017u, %019u\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%01x, %03x, %05x, %07x, %09i, %01x, %011x, %013x, %015x, %017x, %019x\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
	printf("%01X, %#X, %05X, %07X, %09X, %01X, %011X, %013X, % i, %017X, %019X\n", -11, -10, -9, -5, -1, 0, 1, 5, 9, 10 , 11);
}*/
