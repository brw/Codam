NAME := get_next_line

CC := clang
SRC := $(wildcard *.c)
# SRC := get_next_line.c
OBJ_DIR := obj
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# CFLAGS ?= -Wall -Wextra -Werror -Wconversion
CFLAGS ?= -Wall -Wextra -Wconversion
LDFLAGS ?=

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
	LDFLAGS += -g -fsanitize=address
endif

ifdef BUFFER_SIZE
	CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(NAME)
	./$(NAME)

retest: fclean test

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC)

.PHONY: all test retest clean fclean re check
