S = srcs/
O = objs/
I = incs/

NAME = libftprintf.a
HEADER = ft_printf.h

SRCS = ft_printf.c ft_putlchar.c\
OBJS = $(patsubst $S%, $O%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

RM = rm -f
RMDIR = rmdir

all: $(NAME)

$O%.o: $S%.c
	@mkdir -p $O
	@echo "Compiling: $<"
	$(CC) $(CFLAGS) -I $I -c $< -o $@
	@echo "Successful compiling!"

$(NAME): $(OBJS)
	@echo "Compiling library: $<"
	$(LIBC) $(NAME) $(OBJS)
	@echo "Successful compiling!"

clean:
	$(RM) $(OBJS)
	@echo "Objects and their directory cleaned!"

fclean: clean
	$(RM) $(NAME)
	@echo "Executable cleanded!"

re: all clean fclean

.PHONY: all clean fclean re
