# NAME := get_next_line
NAME := get_next_line.a

BONUS_SRC := $(wildcard *_bonus.c)
MAIN := main.c
SRC := $(filter-out $(BONUS_SRC) $(MAIN), $(wildcard *.c))

OBJ_DIR := obj
BONUS_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))

ifdef BONUS
	OBJ := $(BONUS_OBJ)
else
	OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
endif

# CFLAGS ?= -Wall -Wextra -Werror -Wconversion
CFLAGS ?= -Wall -Wextra -Wconversion
LDFLAGS ?=

ifdef DEBUG
	CFLAGS += -g
	LDFLAGS += -g
	ifeq ($(shell uname), Darwin)
		CFLAGS += -fsanitize=address
		LDFLAGS += -fsanitize=address
	endif
endif

ifdef BUFFER_SIZE
	CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(LDFLAGS) -o $@ $^

$(NAME): $(OBJ)
	ar rcs $@ $?

bonus:
	$(MAKE) BONUS=1 all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# test: $(NAME)
# 	./$(NAME)

# retest: fclean test

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC)

norm:
	-norminette $(SRC) $(BONUS_SRC)

.PHONY: all test retest clean fclean re check bonus norm
