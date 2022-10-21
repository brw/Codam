NAME := libft.a
TEST_NAME := test_libft
# HEADERFILES := libft.h
# SRC := ft_isalpha.c
OBJ_DIR := obj
SRC := $(wildcard ft*.c)
TEST_SRC := test.c
TEST_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
# TEST_SRC := $(wildcard test/*.c)
# TEST_OBJ := $(patsubst %.c, %.o, $(TEST_SRC))
# TEST_NAMES := $(basename $(TEST_SRC))
CFLAGS ?= -Wall -Wextra -Werror

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

# clean:
# 	rm -f $(OBJ) $(TEST_OBJ)
#
# fclean: clean
# 	rm -f $(NAME) $(TEST_NAMES)
#
# $(TEST_NAMES): $(TEST_OBJ) $(NAME)
# 	$(CC) -o $@ $^
#
# test: $(TEST_NAMES) $(TEST_OBJ)
# 	$(foreach test, $(TEST_NAMES), ./test/test.sh $(test);)

$(TEST_NAME): $(TEST_OBJ) $(NAME)
	$(CC) -o $@ $^

test: $(TEST_NAME)
	./$<

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean test re
