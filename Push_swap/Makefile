NAME        = push_swap

SRCS        = push_swap.c \
			  utils_to_parse.c \
			  rotation.c \
			  init_stack.c \
			  utils.c \
			  parsing.c \
			  utils_sort.c \
			  print_lst.c


OBJS		=	$(SRCS:%.c=%.o)

INC_DIR		= include

INC			= $(INC_DIR)/push_swap.h

LIBFT		= dependency/libft/libft.a

CFLAGS		= -g3 -fsanitize=address -Wall -Wextra -Werror -I $(INC_DIR)

CC			= gcc

all:        lib $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME) : 	 $(OBJS) $(LIBFT)
			 $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

lib:
			make -s -C dependency/libft

clean:
			rm -f $(OBJS)
			$(MAKE)	-C dependency/libft clean

fclean:		clean
			rm -f $(NAME)

re:            fclean all

.PHONY:       all clean fclean re lib
