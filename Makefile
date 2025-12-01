CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
AR = ar rcs
RM = rm -f

NAME = libftprintf.a

SRC_DIR = src/
INC_DIR = includes/
OBJ_DIR = .obj/

SRCS = $(addprefix $(SRC_DIR), \
	ft_printf_chars.c \
	ft_printf_nbrs_unsigned.c \
	ft_printf_nbrs.c \
	ft_printf_utils.c \
	ft_printf_voidp.c \
	ft_printf.c)

HEADERS = $(addprefix $(INC_DIR), ft_printf.h)

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
