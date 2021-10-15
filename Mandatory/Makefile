O = objs/
I = incs/
S = srcs/

NAME = libftprintf.a

SRCS = $Sft_printf.c $Sft_putlchar.c $Sft_putlhex.c $Sft_putlnbr.c $Sft_putlstr.c $Sft_putlunbr.c $Sft_strlen.c
OBJS = $(SRCS:$S%=$O%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

RM = rm -f
RMDIR = rmdir


all: $(NAME)

$O:
	mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	@echo "Compiling: $<"
	$(CC) -c $< -o $@
	@echo "Successful compiling!"

$(NAME): $(OBJS)
	@echo "Compiling library:"
	$(LIBC) $@ $^
	@echo "Successful compiling!"

clean:
	$(RM) $(OBJS)
	@echo "Objects cleaned!"
	$(RMDIR) $O
	@echo "Object's directory cleaned!"

fclean: clean
	$(RM) $(NAME)
	@echo "Executable cleaned!"

re: fclean all

.PHONY: all clean fclean re
