#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    /*
    printf("----- x TESTS -----\n");
    printf("OR --> %%x == %x\n", UINT_MAX);
    printf("OR --> %%x == %x\n", 0);
    printf("OR --> %%x == %x\n", -1764);
    printf("OR --> %%x == %x\n", 42);
    printf("OR --> %%x == %x\n", UINT_MAX - 1764 + 1);*/
    /*printf("----- + TESTS -----\n"); //EL + tiene un comportamiento indefinido en el caso de los hexadecimales
    printf("OR --> %%+x == %+x\n", UINT_MAX);
    printf("OR --> %%+x == %+x\n", 0);
    printf("OR --> %%+x == %+x\n", -1764);
    printf("OR --> %%+x == %+x\n", 42);
    printf("OR --> %%+x == %+x\n", UINT_MAX - 1764 + 1);*/
    printf("\n");
    printf("----- - TESTS -----\n");
    /*
        El menos sin width o con width igual a 0 no hace nada
        Si tiene width actua como siempre.
        el menos sustituye a los 0
    *//*
    printf("OR --> %%-x == %-x|\n", UINT_MAX);
    printf("OR --> %%-x == %-x|\n", 0);
    printf("OR --> %%-x == %-x|\n", -1764);
    printf("OR --> %%-x == %-x|\n", 42);
    printf("OR --> %%-x == %-x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("----- '.' TESTS -----\n");
    printf("OR --> %%.x == %.x\n", UINT_MAX);
    printf("OR --> %%.x == %.x\n", 0); // si hay precision no se escriben 0
    printf("OR --> %%.x == %.x\n", -1764);
    printf("OR --> %%.x == %.x\n", 42);
    printf("OR --> %%.x == %.x\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("----- WIDTH TESTS -----\n");
    printf("OR --> %%10x == %10x\n", UINT_MAX);
    printf("OR --> %%10x == %10x\n", 0); // si hay precision no se escriben 0
    printf("OR --> %%10x == %10x\n", -1764);
    printf("OR --> %%10x == %10x\n", 42);
    printf("OR --> %%10x == %10x\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("----- '#' TESTS -----\n");
    printf("OR --> %%#x == %#x\n", UINT_MAX);
    printf("OR --> %%#x == %#x\n", 0); // si hay precision no se escriben 0
    printf("OR --> %%#x == %#x\n", -1764);
    printf("OR --> %%#x == %#x\n", 42);
    printf("OR --> %%#x == %#x\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("----- '0' TESTS -----\n");
    printf("OR --> %%0x == %0x\n", UINT_MAX);
    printf("OR --> %%0x == %0x\n", 0); // si hay precision no se escriben 0
    printf("OR --> %%0x == %0x\n", -1764);
    printf("OR --> %%0x == %0x\n", 42);
    printf("OR --> %%0x == %0x\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("----- MIXED WIDTH TESTS -----\n");
    printf("----- '-' + WIDTH TESTS -----\n");
    printf("OR --> %%-0x == %-0x|\n", UINT_MAX);
    printf("OR --> %%-0x == %-0x|\n", 0);
    printf("OR --> %%-0x == %-0x|\n", -1764);
    printf("OR --> %%-0x == %-0x|\n", 42);
    printf("OR --> %%-0x == %-0x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%0x == %0x|\n", UINT_MAX);
    printf("OR --> %%0x == %0x|\n", 0);
    printf("OR --> %%0x == %0x|\n", -1764);
    printf("OR --> %%0x == %0x|\n", 42);
    printf("OR --> %%0x == %0x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%-10x == %-10x|\n", UINT_MAX);
    printf("OR --> %%-10x == %-10x|\n", 0);
    printf("OR --> %%-10x == %-10x|\n", -1764);
    printf("OR --> %%-10x == %-10x|\n", 42);
    printf("OR --> %%-10x == %-10x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%10x == %10x|\n", UINT_MAX);
    printf("OR --> %%10x == %10x|\n", 0);
    printf("OR --> %%10x == %10x|\n", -1764);
    printf("OR --> %%10x == %10x|\n", 42);
    printf("OR --> %%10x == %10x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%-20x == %-20x|\n", UINT_MAX);
    printf("OR --> %%-20x == %-20x|\n", 0);
    printf("OR --> %%-20x == %-20x|\n", -1764);
    printf("OR --> %%-20x == %-20x|\n", 42);
    printf("OR --> %%-20x == %-20x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%20x == %20x|\n", UINT_MAX);
    printf("OR --> %%20x == %20x|\n", 0);
    printf("OR --> %%20x == %20x|\n", -1764);
    printf("OR --> %%20x == %20x|\n", 42);
    printf("OR --> %%20x == %20x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%-20.x == %-20.x|\n", UINT_MAX);
    printf("OR --> %%-20.x == %-20.x|\n", 0);
    printf("OR --> %%-20.x == %-20.x|\n", -1764);
    printf("OR --> %%-20.x == %-20.x|\n", 42);
    printf("OR --> %%-20.x == %-20.x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%20.x == %20.x|\n", UINT_MAX);
    printf("OR --> %%20.x == %20.x|\n", 0);
    printf("OR --> %%20.x == %20.x|\n", -1764);
    printf("OR --> %%20.x == %20.x|\n", 42);
    printf("OR --> %%20.x == %-20.x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%-20.0x == %-20.0x|\n", UINT_MAX);
    printf("OR --> %%-20.0x == %-20.0x|\n", 0);
    printf("OR --> %%-20.0x == %-20.0x|\n", -1764);
    printf("OR --> %%-20.0x == %-20.0x|\n", 42);
    printf("OR --> %%-20.0x == %-20.0x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%20.0x == %20.0x|\n", UINT_MAX);
    printf("OR --> %%20.0x == %20.0x|\n", 0);
    printf("OR --> %%20.0x == %20.0x|\n", -1764);
    printf("OR --> %%20.0x == %20.0x|\n", 42);
    printf("OR --> %%20.0x == %20.0x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%-20.10x == %-20.10x|\n", UINT_MAX);
    printf("OR --> %%-20.10x == %-20.10x|\n", 0);
    printf("OR --> %%-20.10x == %-20.10x|\n", -1764);
    printf("OR --> %%-20.10x == %-20.10x|\n", 42);
    printf("OR --> %%-20.10x == %-20.10x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%20.10x == %20.10x|\n", UINT_MAX);
    printf("OR --> %%20.10x == %20.10x|\n", 0);
    printf("OR --> %%20.10x == %20.10x|\n", -1764);
    printf("OR --> %%20.10x == %20.10x|\n", 42);
    printf("OR --> %%20.10x == %20.10x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("\n");
    printf("OR --> %%-10.20x == %-10.20x|\n", UINT_MAX);
    printf("OR --> %%-10.20x == %-10.20x|\n", 0);
    printf("OR --> %%-10.20x == %-10.20x|\n", -1764);
    printf("OR --> %%-10.20x == %-10.20x|\n", 42);
    printf("OR --> %%-10.20x == %-10.20x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%10.20x == %10.20x|\n", UINT_MAX);
    printf("OR --> %%10.20x == %10.20x|\n", 0);
    printf("OR --> %%10.20x == %10.20x|\n", -1764);
    printf("OR --> %%10.20x == %10.20x|\n", 42);
    printf("OR --> %%10.20x == %10.20x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%#-10.20x == %#-10.20x|\n", UINT_MAX);
    printf("OR --> %%#-10.20x == %#-10.20x|\n", 0);
    printf("OR --> %%#-10.20x == %#-10.20x|\n", -1764);
    printf("OR --> %%#-10.20x == %#-10.20x|\n", 42);
    printf("OR --> %%#-10.20x == %#-10.20x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%#10.20x == %#10.20x|\n", UINT_MAX);
    printf("OR --> %%#10.20x == %#10.20x|\n", 0);
    printf("OR --> %%#10.20x == %#10.20x|\n", -1764);
    printf("OR --> %%#10.20x == %#10.20x|\n", 42);
    printf("OR --> %%#10.20x == %#10.20x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%#010.20x == %#010.20x|\n", UINT_MAX); //si hay cero y precision suda el 0
    printf("OR --> %%#010.20x == %#010.20x|\n", 0);
    printf("OR --> %%#010.20x == %#010.20x|\n", -1764);
    printf("OR --> %%#010.20x == %#010.20x|\n", 42);
    printf("OR --> %%#010.20x == %#010.20x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%#010.000000020x == %#010.000000020x|\n", UINT_MAX); //si hay cero y precision suda el 0
    printf("OR --> %%#010.000000020x == %#010.000000020x|\n", 0);
    printf("OR --> %%#010.000000020x == %#010.000000020x|\n", -1764);
    printf("OR --> %%#010.000000020x == %#010.000000020x|\n", 42);
    printf("OR --> %%#010.000000020x == %#010.000000020x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%#-20.10x == %#-20.10x|\n", UINT_MAX);
    printf("OR --> %%#-20.10x == %#-20.10x|\n", 0);
    printf("OR --> %%#-20.10x == %#-20.10x|\n", -1764);
    printf("OR --> %%#-20.10x == %#-20.10x|\n", 42);
    printf("OR --> %%#-20.10x == %#-20.10x|\n", UINT_MAX - 1764 + 1);
    printf("\n");
    printf("OR --> %%#20.10x == %#20.10x|\n", UINT_MAX);
    printf("OR --> %%#20.10x == %#20.10x|\n", 0);
    printf("OR --> %%#20.10x == %#20.10x|\n", -1764);
    printf("OR --> %%#20.10x == %#20.10x|\n", 42);
    printf("OR --> %%#20.10x == %#20.10x|\n", UINT_MAX - 1764 + 1);
    printf("\n");*/
    /*printf("----- ' ' TESTS -----\n"); //EL ' ' tiene un comportamiento indefinido en el caso de los hexadecimales
    printf("OR --> %% x == % x\n", UINT_MAX);
    printf("OR --> %% x == % x\n", 0);
    printf("OR --> %% x == % x\n", -1764);
    printf("OR --> %% x == % x\n", 42);
    printf("OR --> %% x == % x\n", UINT_MAX - 1764 + 1);
    printf("\n");*/

    printf("%#-10.5x|", UINT_MAX);
}