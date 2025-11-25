CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

NAME = libft.a
NAME_BONUS = libft.a

SRCS = ft_atoi.c \
	ft_itoa.c \
	ft_putnbr_fd.c \
	ft_strlcpy.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_memchr.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_memcmp.c \
	ft_split.c \
	ft_strmapi.c \
	ft_isalnum.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_isalpha.c \
	ft_memmove.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_isascii.c \
	ft_memset.c \
	ft_striteri.c \
	ft_strrchr.c \
	ft_isdigit.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_isprint.c \
	ft_putendl_fd.c \
	ft_strlcat.c \
	ft_substr.c

SRCS_BONUS = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstmap_bonus.c

HEADERS = libft.h

MANDATORY = .mandatory
BONUS = .bonus

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY) $(OBJS)

$(MANDATORY): $(OBJS) $(HEADERS)
	$(AR) $(NAME) $(OBJS)
	touch $(MANDATORY)
	rm -rf $(BONUS)

bonus: $(BONUS) $(OBJS_BONUS) $(OBJS)

$(BONUS): $(OBJS) $(OBJS_BONUS) $(HEADERS)
	$(AR) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS)
	touch $(BONUS)
	rm -rf $(MANDATORY)

%.o: %.c $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(MANDATORY) $(BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
