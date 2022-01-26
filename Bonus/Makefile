I = incs/
M = mains/
P = printf/
C = char/
S = string/
U = unsigned/
F = flags/
W = width/
UT = utils/
PR = precision/
PP = pruebas/

NAME = printfmain.out

TM = totalmain.out
CM = charmain.out
SM = strmain.out
UM = uintmain.out

UINT_SRCS = $Muintmain.c\
			$Sft_putstr.c\
			$Cft_putchar.c\
			$Pft_printf_bonus_uint.c\
			$Wft_get_width.c $Wft_process_width.c\
			$(UN)ft_process_uint.c $(UN)ft_putunbr.c\
			$Uft_uitoa.c $Uft_strlen.c $Uft_isdigit.c $Uft_atoi.c\
			$Fft_control_conversion.c $Fft_is_specifier.c\
			$(PR)ft_process_precision.c $(PR)ft_get_precision.c\

STR_SRCS = $Mmain.c\
	$Cft_process_char.c $Cft_putchar.c\
	$Pft_printf_bonus.c\
	$Sft_process_string.c $Sft_putstr.c\
	$Wft_get_width.c $Wft_process_width.c\
	$Vft_control_conversion.c $Vft_is_specifier.c\
	$Uft_atoi.c $Uft_isdigit.c $Uft_strcpy.c $Uft_strlen.c $Uft_strndup.c\

CHAR_SRCS = $Mcharmain.c\
	$Pft_printf_bonus.c\
	$Cft_process_char.c $Cft_putchar.c\
	$Vft_control_conversion.c $Vft_is_specifier.c\
	$Wft_atoi.c $Wft_get_width.c $Wft_isdigit.c $Wft_process_width.c\

TOTAL_SRCS = $Mtotalmain.c\
	$Pft_printf_bonus.c\
	$Uft_process_uint.c $Uft_putunbr.c\
	$Cft_process_char.c $Cft_putchar.c\
	$Sft_process_string.c $Sft_putstr.c\
	$Wft_get_width.c $Wft_process_width.c\
	$Fft_control_conversion.c $Fft_is_specifier.c\
	$(PR)ft_get_precision.c $(PR)ft_process_precision.c\
	$(UT)ft_atoi.c $(UT)ft_isdigit.c $(UT)ft_strcpy.c $(UT)ft_strlen.c\
	$(UT)ft_strndup.c $(UT)ft_uitoa.c\


CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = -rm -r

all: $(NAME)

t: $(TOTAL_SRCS)
	$(CC) $(CFLAGS) $^ -I incs/ -o $(TM)
	./$(TM)

c: $(CHAR_SRCS)
	$(CC) $(CFLAGS) $^ -I incs/ -o $(CM)
	./$(CM)

s: $(STR_SRCS)
	$(CC) $(CFLAGS) $^ -I incs/ -o $(SM)
	./$(SM)

u: $(UINT_SRCS)
	$(CC) $(CFLAGS) $^ -I incs/ -o $(UM)
	./$(UM)

fclean:
	$(RM) *.out
	@echo "Executable cleaned!"

re: fclean all

.PHONY: all fclean clean re