# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: bvan-den <bvan-den@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2023/06/01 21:52:09 by bvan-den      #+#    #+#                  #
#    Updated: 2023/06/15 16:08:36 by bvan-den      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := pipex

SRC_DIR := src
# BONUS_SRC := $(wildcard $(SRC_DIR)/*_bonus.c)
BONUS_SRC := src/execution_bonus.c src/handle_fds_bonus.c src/utils_bonus.c \
			 src/handle_args_bonus.c src/pipex_bonus.c
# SRC := $(filter-out $(BONUS_SRC), $(wildcard $(SRC_DIR)/*.c))
SRC := src/execution.c src/pipex.c src/handle_fds.c src/handle_args.c \
	   src/utils.c

OBJ_DIR := obj
BONUS_OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
ifdef BONUS
	OBJ := $(BONUS_OBJ)
endif

DEP := $(OBJ:%.o=%.d)
BONUS_DEP := $(BONUS_OBJ:%.o=%.d)

FT_PRINTF_DIR := ft_printf
FT_PRINTF_NAME := $(FT_PRINTF_DIR)/libftprintf.a

GET_NEXT_LINE_DIR := get_next_line
GET_NEXT_LINE_NAME := $(GET_NEXT_LINE_DIR)/get_next_line.a

INCLUDES := -I ./include \
			-I $(FT_PRINTF_DIR)/include \
			-I $(GET_NEXT_LINE_DIR) \
			-I $(FT_PRINTF_DIR)/libft/include
CFLAGS ?= -Wall -Wextra -Werror -Wconversion -MMD $(INCLUDES)
LDFLAGS ?=

ifeq ($(shell uname), Linux)
	CFLAGS += -I /usr/include/bsd -D LIBBSD_OVERLAY
	LDFLAGS += -L /usr/lib -l bsd
endif

ifdef DEBUG
	CFLAGS += -g
	LDFLAGS += -g
	ifeq ($(shell uname), Darwin)
		CFLAGS += -fsanitize=address
		LDFLAGS += -fsanitize=address
	endif
endif

all: $(NAME)

FORCE:

$(NAME): $(OBJ) $(FT_PRINTF_NAME) $(GET_NEXT_LINE_NAME)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(FT_PRINTF_NAME): FORCE
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GET_NEXT_LINE_NAME): FORCE
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(DEP) $(BONUS_DEP)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC) $(BONUS_SRC)
	$(MAKE) -C $(FT_PRINTF_DIR) check
	$(MAKE) -C $(GET_NEXT_LINE_DIR) check

norm:
	-@norminette $(SRC) $(BONUS_SRC)
	-@$(MAKE) -C $(FT_PRINTF_DIR) norm
	-@$(MAKE) -C $(GET_NEXT_LINE_DIR) norm

format:
	c_formatter_42 $(SRC) $(BONUS_SRC)

bonus:
	$(MAKE) all BONUS=1

rebonus: fclean bonus

-include $(DEP)

.PHONY: all clean fclean re check norm format bonus rebonus FORCE
