NAME := pipex

CC := clang

SRC := $(wildcard *.c)
OBJ_DIR := obj
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
LIBFT_DIR := libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a

INCLUDES := -I ./include -I ./libft/include
# CFLAGS ?= -Wall -Wextra -Werror -Wconversion $(INCLUDES)
CFLAGS ?= -Wall -Wextra -Wconversion $(INCLUDES)
LDFLAGS ?=

ifeq ($(shell uname), Linux)
	CFLAGS += -I /usr/include/bsd -D LIBBSD_OVERLAY
	LDFLAGS += -L /usr/lib -l bsd
endif

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
	LDFLAGS += -g fasnitize=address
endif

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: *.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C  $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C  $(LIBFT_DIR) fclean

re: fclean all

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC)

norminette:
	norminette: $(SRC)

format:
	c_formatter_42 $(SRC)

.PHONY: all clean fclean re check norminette format