NAME = so_long
SRC = $(addprefix src/, input_handlers.c rendering.c map.c game.c init_game.c )
#GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
#PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)
LIBFT	= libft/libft.a
OBJ := $(SRC:%.c=%.o)
#GNL_OBJ := $(GNL_SRC:%.c=%.o)
#PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CCFLAGS = -g -Wextra -Wall -Werror

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME):$(OBJ)
	gcc $(CCFLAGS) $^ -Lmlx -lmlx -L/usr/X11/lib -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT) 

#debug: $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
#	gcc $(CCFLAGS) -fsanitize=address $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(CCFLAGS) -Imlx -I/opt/X11/include -Isrc -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

mlx:
	@$(MAKE) re -C mlx/

re: fclean all
