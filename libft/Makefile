NAME := libft.a

# BONUS_SRC := $(wildcard ft_*_bonus.c)
BONUS_SRC := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			 ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			 ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
			 ft_lstsize_bonus.c
# REGULAR_SRC := $(filter-out $(BONUS_SRC), $(wildcard ft_*.c))
REGULAR_SRC := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			   ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c \
			   ft_isspace.c ft_isupper.c ft_itoa.c ft_memchr.c ft_memcmp.c \
			   ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			   ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			   ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			   ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strndup.c \
			   ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			   ft_toupper.c ft_split_args.c

OBJ_DIR := obj
BONUS_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))
REGULAR_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(REGULAR_SRC))

ifdef WITH_BONUS
	OBJ = $(REGULAR_OBJ) $(BONUS_OBJ)
else
	OBJ = $(REGULAR_OBJ)
endif

TEST_NAME := test_libft
TEST_SRC := test.c
TEST_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))

INCLUDES := -I ./include
CFLAGS ?= -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS ?=

ifeq ($(shell uname), Linux)
	CFLAGS += -I /usr/include/bsd -D LIBBSD_OVERLAY
	LDFLAGS += -L /usr/lib -l bsd
endif

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
	LDFLAGS += -g -fsanitize=address
endif

VPATH := test

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?

$(OBJ_DIR)/%.o: %.c
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

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

# Use with Francinette, normal bonus target fails most of the time (but not every time lol)
# bonus: $(OBJ) $(BONUS_OBJ)
# 	ar rcsu $(NAME) $^

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean test re so bonus
