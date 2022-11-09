NAME := libftprintf.a

LIBFT_DIR := libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a

OBJ_DIR := obj
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

TEST_NAME := test_ft_printf
TEST_DIR := test
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(TEST_SRC)))

INCLUDES := -I./include -I./libft/include
# CFLAGS ?= -Wall -Wextra -Werror -Wconversion $(INCLUDES)
CFLAGS ?= -Wall -Wextra -Wconversion $(INCLUDES)
LDFLAGS ?=
ifdef DEBUG
	CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_NAME) $(NAME)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(NAME)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TEST_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

retest: fclean test

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC) $(TEST_SRC)

.PHONY: all clean fclean re test check
