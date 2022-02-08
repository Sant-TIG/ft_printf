I = incs/
O = objs/
S = srcs/

NAME = libftprintf.a

SRCS_BONUS = $Sft_init.c\
	$Sft_printf_bonus.c\
	$Sft_get_precision.c  $Sft_get_width.c\
	$Sft_control_flags.c $Sft_control_flags_utils1.c $Sft_control_flags_utils2.c\
	$Sft_atoi.c $Sft_is_specifier.c $Sft_isdigit.c $Sft_nbrtoa_base.c $Sft_putchar.c\
	$Sft_strlen.c $Sft_strndup.c $Sft_strstr.c $Sft_strcpy.c $Sft_putstr.c\
	$Sft_process_char.c $Sft_process_str.c $Sft_process_hex.c $Sft_process_int.c $Sft_process_uint.c $Sft_process_negative_int.c\
	$Sft_process_pointer.c $Sft_process_precision_uint.c $Sft_process_precision.c $Sft_process_width.c\

OBJS_BONUS = $(SRCS_BONUS:$S%=$O%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

RM = -rm -r

all: $(NAME)

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS_BONUS): | $O

$(OBJS_BONUS): $O%.o: $S%
	@echo "Compiling: $<"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Successful compiling!"

$(NAME): $(OBJS_BONUS)
	@echo "Compiling library:"
	$(LIBC) $@ $^
	@echo "Successful compiling!"

bonus: all

clean:
	$(RM) $O
	@echo "Objects and directory cleaned!"


fclean: clean
	$(RM) $(NAME)
	@echo "Executable cleaned!"

re: fclean all

.PHONY: all fclean clean re
