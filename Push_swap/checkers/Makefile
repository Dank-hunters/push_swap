.SILENT:
NAME        = ../checker

SRCS        = checker.c \
  			  get_next_line.c \
			  rotation.c \
			  ft_putstr.c \
			  get_next_line_utils.c \
			  utils.c \
			  ft_atol.c

SRCS_DIR	= srcs

OBJS		=	$(SRCS:%.c=%.o)

OBJS_DIR	= objs

OBJS_P		= $(addprefix $(OBJS_DIR)/, $(OBJS))

INC_DIR		= ../include

INC			= $(INC_DIR)/checker.h

CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)

CC			= gcc

all:        creat_obj_dir $(NAME)


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : 	 $(OBJS_P) $(LIBFT)
			 $(CC) $(CFLAGS) $(OBJS_P) $(LIBFT) -o $(NAME)
			printf "Compilation checker completed\n"

clean:
			rm -f $(OBJS)
			rm -rf $(OBJS_DIR)

fclean:		clean
			rm -f $(NAME)
			printf "All clean in checker dir\n"
creat_obj_dir:
				rm -rf objs || true
				mkdir objs

re:            fclean all

.PHONY:       all clean fclean creat_obj_dir re 
