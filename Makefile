NAME := libft.a
TEST_NAME := test_libft
# HEADERFILES := libft.h
# SRCS := ft_isalpha.c
SRCS := $(wildcard *.c)
TEST_SRC := test/test.c
TEST_OBJ := $(patsubst %.c, %.o, $(TEST_SRC))
OBJS := $(patsubst %.c, %.o, $(SRCS))
# TEST_SRCS := $(wildcard test/*.c)
# TEST_OBJS := $(patsubst %.c, %.o, $(TEST_SRCS))
# TEST_NAMES := $(basename $(TEST_SRCS))
CFLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcsu $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

# clean:
# 	rm -f $(OBJS) $(TEST_OBJS)
#
# fclean: clean
# 	rm -f $(NAME) $(TEST_NAMES)
#
# $(TEST_NAMES): $(TEST_OBJS) $(NAME)
# 	$(CC) -o $@ $^
#
# test: $(TEST_NAMES) $(TEST_OBJS)
# 	$(foreach test, $(TEST_NAMES), ./test/test.sh $(test);)

$(TEST_NAME): $(TEST_OBJ) $(NAME)
	$(CC) -o $@ $^

test: $(TEST_NAME)
	./$<

re: fclean all

.PHONY: all clean fclean test re
