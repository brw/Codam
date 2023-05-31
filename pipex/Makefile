NAME := pipex


SRC := $(wildcard *.c) $(wildcard $(GET_NEXT_LINE_DIR)/*.c)
OBJ_DIR := obj
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
DEP := $(OBJ:%.o=%.d)

LIBFT_DIR := libft
LIBFT_NAME := $(LIBFT_DIR)/libftprintf.a

GET_NEXT_LINE_DIR := get_next_line
GET_NEXT_LINE_NAME := $(GET_NEXT_LINE_DIR)/get_next_line.a

INCLUDES := -I ./include -I $(LIBFT_DIR)/include -I $(GET_NEXT_LINE_DIR)/include
# CFLAGS ?= -Wall -Wextra -Werror -Wconversion -MMD $(INCLUDES)
CFLAGS ?= -Wall -Wextra -Wconversion -MMD $(INCLUDES)
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

$(NAME): $(LIBFT_NAME) $(GET_NEXT_LINE_NAME) $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBFT_NAME): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE_NAME): FORCE
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

clean:
	rm -f $(OBJ) $(DEP)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC)

norminette:
	norminette $(SRC)

format:
	c_formatter_42 $(SRC)

-include $(DEP)

.PHONY: all clean fclean re check norminette format
