.SILENT:

NAME        = push_swap
 
SRCS        = push_swap.c \
			  utils_to_parse.c \
			  rotation.c \
			  init_stack.c \
			  utils.c \
			  parsing.c \
			  utils_sort.c \
			  print_lst.c \
			  sort_utils.c


SRCS_DIR	= srcs

OBJS		=	$(SRCS:%.c=%.o)

OBJS_DIR	=	objs

OBJS_P		= $(addprefix $(OBJS_DIR)/, $(OBJS))

INC_DIR		= include

INC			= $(INC_DIR)/push_swap.h

LIBFT		= dependency/libft/libft.a

CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)

CC			= gcc

all:        creat_obj_dir lib $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME) : 	 $(OBJS_P) $(LIBFT)
			 $(CC) $(CFLAGS) $(OBJS_P) $(LIBFT) -o $(NAME)
			printf "Compilation push_swap completed\n"

lib:
			make -s -C dependency/libft
			printf "Compilation lib completed\n"
checker :
			make -C checkers

checker_clean :
			make -C checkers clean

checker_fclean :
			make  -C checkers fclean
checker_re :
			make  -C checkers re

creat_obj_dir :
			rm -rf objs || true
			mkdir -p objs
			printf "objs dir created\n"

clean:
			rm -f $(OBJS)
			rm -rf $(OBJS_DIR)
			$(MAKE)	-C dependency/libft clean

fclean:		clean
			rm -f $(NAME)
			printf "All clean\n"

re:            fclean all

.PHONY:       all clean fclean re lib checker checker_fclean checker_re creat_obj_dir 
