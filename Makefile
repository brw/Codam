NAME := libft.a
TEST_NAME := test_libft
# HEADERFILES := libft.h
# SRC := ft_isalpha.c
OBJ_DIR := obj
SRC := $(wildcard ft_*.c)
TEST_SRC := test.c
TEST_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
CFLAGS ?= -Wall -Wextra -Werror
LDFLAGS ?=

all: $(NAME)

$(NAME): $(OBJ)
	ar rcsu $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p obj
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(NAME)
	$(CC) $(LDFLAGS) -o $@ $^

test: $(TEST_NAME)
	./$<

re: fclean all

retest: fclean test

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean test re so
