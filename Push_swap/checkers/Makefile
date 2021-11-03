NAME        = checker

SRCS        = checker.c \
  			  get_next_line.c \
			  rotation.c \
			  ft_putstr.c \
			  get_next_line_utils.c \
			  utils.c \
			  ft_atol.c

OBJS		=	$(SRCS:%.c=%.o)

INC_DIR		= include

INC			= $(INC_DIR)/checker.h


CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)

CC			= gcc

all:        $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME) : 	 $(OBJS)
			 $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:            fclean all

.PHONY:       all clean fclean re 
