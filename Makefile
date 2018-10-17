
CC			= gcc
RM			= rm -rf
NAME		= minishell
CFLAGS		= -Wall -Wextra -Werror
MEMORY		= -g
LIBFT 		= libft/libft.a
HEADER		= -I libft/includes\
			  -I include
FUNCTIONS	= minishell.c\

FILES		= $(addprefix src/, $(FUNCTIONS))

OBJECTS		= $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJECTS): $(FILES)
	@$(CC) $(CFLAGS) $(MEMORY) -c $(FILES) $(HEADER)
	@mv $(FUNCTIONS:.c=.o) src/

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
