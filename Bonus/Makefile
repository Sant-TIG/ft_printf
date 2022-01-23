I = incs/
M = mains/
P = printf/
C = char/
S = string/
V = conversion/
W = width/
U = utils/


NAME = printfmain.out

TM = totalmain.out
CM = charmain.out
SM = strmain.out

STR_SRCS = $Mstrmain.c\
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
	$Wft_atoi.c $Wft_get_width.c $Wft_isdigit.c $Wft_process_width.c

TOTAL_SRCS = $Mtotalmain.c\
	$Pft_printf_bonus.c\
	$Cft_process_char.c $Cft_putchar.c\
	$Sft_process_string.c $Sft_putstr.c\
	$Wft_get_width.c $Wft_process_width.c\
	$Vft_control_conversion.c $Vft_is_specifier.c\
	$Uft_atoi.c $Uft_isdigit.c $Uft_strcpy.c $Uft_strlen.c $Uft_strndup.c\


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

fclean:
	$(RM) *.out
	@echo "Executable cleaned!"

re: fclean all

.PHONY: all fclean clean re