NAME := libft.a
TEST_NAME := test_libft
# HEADERFILES := libft.h
# SRCS := ft_isalpha.c
OBJS_DIR := obj
SRCS := $(wildcard ft*.c)
TEST_SRC := test.c
TEST_OBJ := $(patsubst %.c, $(OBJS_DIR)/%.o, $(TEST_SRC))
OBJS := $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
# TEST_SRCS := $(wildcard test/*.c)
# TEST_OBJS := $(patsubst %.c, %.o, $(TEST_SRCS))
# TEST_NAMES := $(basename $(TEST_SRCS))
CFLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcsu $@ $^

$(OBJS_DIR)/%.o: %.c
	@mkdir -p obj
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TEST_OBJ)
	rmdir $(OBJS_DIR)

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
