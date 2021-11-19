.SILENT:
NAME = push_swap

SRCS        = push_swap.c \
			  utils_to_parse.c \
			  rotation.c \
			  init_stack.c \
			  utils.c \
			  parsing.c \
			  utils_sort.c \
			  print_lst.c \
			  sort_utils.c

SRCS_DIR = srcs

OBJS = $(SRCS:.c=.o)

OBJS_DIR = obj

OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

INC    = include

LIBRARY = dependency/libft/libft.a

FSAN	=  -fsanitize=address -g3

CFLAGS    = -Wall -Wextra -Werror -I $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)/push_swap.h $(LIBRARY)	
			gcc $(CFLAGS) -c $< -o $@

all: create_obj_dir lib $(NAME)

lib:
			make -C dependency/libft

$(NAME) :    $(OBJS_PATH)
			gcc  $(CFLAGS) $(OBJS_PATH) $(LIBRARY) -o $(NAME)
			printf "Push_swap compilation completed"
checkers :
			make -C ./checkers
			printf "Checker compilation completed"

checkers_clean :
				make -C ./checkers clean

checkers_fclean :
				make -C ./checkers fclean
checkers_re :
				make -C ./checkers re

create_obj_dir :
				rm -f obj || true
				mkdir -p obj

clean:
				rm -f $(OBJS_PATH)
	           make -C dependency/libft clean

fclean:
	           rm -f $(OBJS_PATH)
	           rm -f $(NAME)
	           rm -rf obj
	           make -C dependency/libft fclean

re:            fclean all

.PHONY:        all lib create_obj_dir clean fclean re checkers checkers_clean \
            checkers_fclean checkers_re
