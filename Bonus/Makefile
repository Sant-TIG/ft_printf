S = srcs/
O = objs/
I = incs/

NAME = libftprint.a

SRCS_BONUS = $Sft_atoi.c \
	$Sft_get_precision.c \
	$Sft_get_width.c \
	$Sft_is_specifier.c \
	$Sft_isdigit.c \
	$Sft_prclen.c \
	$Sft_printf.c \
	$Sft_process_precision.c \
	$Sft_process_string.c \
	$Sft_process_width.c \
	$Sft_putchar.c \
	$Sft_putstr.c \
	$Sft_strlen.c

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
	@echo "Declaring folder as "order-only prerequisite"

$(OBJS_BONUS): $O%.o: $S%
	@echo "Compiling: $<"
	$(CC) -c $< -o $@
	@echo "Successful compiling!"

$(NAME): $(OBJS_BONUS)
	@echo "Compiling library:"
	$(LIBC) $@ $^
	@echo "Successful compiling!"

clean:
	$(RM) $O
	@echo "Objects and directory cleaned!"

fclean: clean
	$(RM) $(NAME)
	@echo "Executable cleaned!"

re: fclean all

.PHONY: all clean fclean re
