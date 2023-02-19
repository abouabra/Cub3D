SRC =  main.c key_movement.c map_check.c info_list_stuff.c map_operation.c

OSRC=$(SRC:.c=.o)

NAME = cub3d
CFLAGS= -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit 
INCLUDE = -I. -I libft

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all :$(NAME)

$(NAME) : $(OSRC)
	@make -C libft
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDE) $(OSRC) libft/libft.a -o $@

%.o : %.c
	@printf "hana kan compili f$(GREEN) $< $(RESET) \n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $<

clean:
	@make -C libft clean
	@rm -rf *.o

fclean:
	@make -C libft fclean
	@rm -rf *.o $(NAME)

re: fclean all

.PHONY: all clean fclean all
