NAME := push_swap

CC := clang

SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR := obj
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

INCLUDES := -I ./include -I ./libft/include -I ./get_next_line/include
# CFLAGS ?= -Wall -Wextra -Werror -Wconversion $(INCLUDES)
CFLAGS ?= -Wall -Wextra -Wconversion $(INCLUDES)
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

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC)

norminette:
	norminette $(SRC)

format:
	c_formatter_42 $(SRC)

.PHONY: all test clean fclean re check norminette format
