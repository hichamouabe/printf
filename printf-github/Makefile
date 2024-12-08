NAME = libftprintf.a

SRCS = src/ft_buffer_utils.c src/ft_char_utils.c src/ft_general_utils.c \
       src/ft_number_utils.c src/ft_padding_utils.c src/ft_parser.c \
       src/ft_printf.c src/ft_too_many_functions.c

OBJS = $(SRCS:src/%.c=obj/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)
bonus: $(NAME)
obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -Iinclude -o $@

obj:
	mkdir -p obj

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all
