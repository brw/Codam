NAME := libft.a
TEST_NAME := test_libft
# HEADERFILES := libft.h
# SRC := ft_isalpha.c
OBJ_DIR := obj
BONUS_SRC := $(wildcard ft_*_bonus.c)
BONUS_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))
REGULAR_SRC := $(filter-out $(BONUS_SRC), $(wildcard ft_*.c))
REGULAR_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(REGULAR_SRC))
ifdef WITH_BONUS
	OBJ = $(REGULAR_OBJ) $(BONUS_OBJ)
else
	OBJ = $(REGULAR_OBJ)
endif
TEST_SRC := test.c
TEST_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))
CFLAGS ?= -Wall -Wextra -Werror
LDFLAGS ?=

all: $(NAME)

$(NAME): $(OBJ)
	ar rcsu $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p obj
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(BONUS_OBJ) $(NAME)
	$(CC) $(LDFLAGS) -o $@ $^

test: $(TEST_NAME)
	./$<

re: fclean all

retest: fclean test

bonus:
	$(MAKE) WITH_BONUS=1 all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean test re so bonus
