NAME := libftprintf.a

LIBFT_DIR := libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a

OBJ_DIR := obj
SRC_DIR := src
# SRC := $(wildcard $(SRC_DIR)/*.c)
SRC := src/ft_printf.c src/print.c
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

TEST_NAME := test_ft_printf
TEST_DIR := test
# TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_SRC := test/test_ft_printf.c
TEST_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(TEST_SRC)))

INCLUDES := -I ./include -I ./libft/include
# CFLAGS ?= -Wall -Wextra -Wconversion $(INCLUDES)
CFLAGS ?= -Wall -Wextra -Werror -Wconversion $(INCLUDES)
LDFLAGS ?=

ifeq ($(shell uname), Linux)
	CFLAGS += -I /usr/include/bsd -D LIBBSD_OVERLAY
	LDFLAGS += -L /usr/lib -l bsd
endif

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
	LDFLAGS += -g -fsanitize=address
endif

all: $(NAME)

FORCE:

$(NAME): $(OBJ) $(LIBFT_NAME)
	cp $(LIBFT_NAME) $(NAME)
	ar rcs $@ $<

$(LIBFT_NAME): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

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

.PHONY: all clean fclean re test retest check
