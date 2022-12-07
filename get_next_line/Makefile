NAME := get_next_line

CC := clang

BONUS_SRC := $(wildcard *_bonus.c)
SRC := $(filter-out $(BONUS_SRC), $(wildcard *.c))

OBJ_DIR := obj
BONUS_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

ifdef BONUS
	OBJ = $(BONUS_OBJ) main.c
endif

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

bonus: $(BONUS_OBJ)
	$(MAKE) BONUS=1 all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(NAME)
	./$(NAME)

retest: fclean test

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC)

.PHONY: all test retest clean fclean re check bonus
