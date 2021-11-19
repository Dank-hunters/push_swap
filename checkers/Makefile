.SILENT:

NAME = ../checker

SRCS        = checker.c \
  			  get_next_line.c \
			  rotation.c \
			  get_next_line_utils.c \
			  utils.c \
			  ft_atol.c \
			  init.c

SRCS_DIR = srcs

OBJS = $(SRCS:.c=.o)

OBJS_DIR = obj

OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

INC = ../include


CFLAGS = -Wall -Wextra -Werror -I $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)/checker.h
	gcc $(CFLAGS) -c $< -o $@

all: create_obj_dir  $(NAME)


$(NAME) :	$(OBJS_PATH)
			gcc $(OBJS_PATH) $(LIBRARY) -o $(NAME)

create_obj_dir :
			rm -f obj || true
			mkdir -p obj

clean:
			rm -f $(OBJS_PATH)

fclean:
			rm -f $(OBJS_PATH)
			rm -f $(NAME)
			rm -rf obj

re:			fclean all

.PHONY:		all  create_obj_dir clean fclean re
