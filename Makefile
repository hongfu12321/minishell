
CC			= gcc
RM			= rm -rf
NAME		= minishell
CFLAGS		= -Wall -Wextra -Werror
MEMORY		= -g
LIBFT 		= libft/libft.a
HEADER		= -I libft/includes	\
			  -I include
FUNCTIONS	= minishell.c

MY_FUNC		= ft_my_exit.c		\
			  ft_my_echo.c

FILES		= $(addprefix src/, $(FUNCTIONS))\
			  $(addprefix src/my_function/, $(MY_FUNC))

OBJECTS		= $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJECTS): $(FILES)
	@$(CC) $(CFLAGS) $(MEMORY) -c $(FILES) $(HEADER)
	@mv $(FUNCTIONS:.c=.o) src/
	@mv $(MY_FUNC:.c=.o) src/my_function/

libft: $(LIBFT)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJECTS)
	@echo -n 'Compiling $(NAME)...'
	@$(CC) $(CFLAGS) $(MEMORY) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "\t\t\033[32mDone!\033[0m"

clean:
	@echo -n 'Cleaning  $(NAME)...'
	@$(RM) $(OBJECTS)
	@echo "\t\t\033[31mDone!\033[0m"
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

re: fclean all
