NAME = libftprintf.a
SRCS = 
OBJS = $(SRCS:.c=.o)
DEPS = libftprintf.h
LIBFT = libft/libft.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT) $(NAME) 
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -I libft -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean