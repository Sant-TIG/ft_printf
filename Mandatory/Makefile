O = objs/
I = incs/
S = srcs/

NAME = libftprintf.a

SRCS = $Sft_printf.c $Sft_putlchar.c $Sft_putlhex.c $Sft_putlnbr.c $Sft_putlstr.c $Sft_putlunbr.c $Sft_strlen.c
OBJS = $(SRCS:$S%=$O%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

RM = -rm -r


all: $(NAME)

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $O
	@echo "Declaring folder as "order-only prerequisite"

$(OBJS): $O%.o: $S%
	@echo "Compiling: $<"
	$(CC) -c $< -o $@
	@echo "Successful compiling!"

$(NAME): $(OBJS)
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
