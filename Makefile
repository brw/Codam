NAME := libft.a
# HEADERFILES := libft.h
# OBJ := ft_isalpha.o
# SRC := ft_isalpha.c
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))
CFLAGS ?= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar rcsu $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out

.PHONY: clean fclean
