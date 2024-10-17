NAME = so_long
SRC = $(addprefix src/, input_handlers.c rendering.c map.c game.c init_game.c map_checker.c)
#GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
#PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)
LIBFT	= libft/libft.a
OBJ := $(SRC:%.c=%.o)
#GNL_OBJ := $(GNL_SRC:%.c=%.o)
#PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)
CC = clang
MLXLIB = mlx/mlx.a


CCFLAGS = -g -Wextra -Wall -Werror
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx_linux -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx_macos -lmlx_macos -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
ifeq ($(shell uname), Linux)
	MLX_INCLUDES = -I/usr/include -Imlx_linux 
else
	MLX_INCLUDES = -Imlx_macos -I/opt/x11/include
endif

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CCFLAGS) $^ $(MLX_FLAGS) -o $(NAME) $(LIBFT) 

#debug: $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
#	$(CC) $(CCFLAGS) -fsanitize=address $^ $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(MLX_INCLUDES) -Isrc -Ilibft -c $< -o $@

$(LIBFT): 
	make -C ./libft

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C ./mlx_linux
	make clean -C ./libft
	rm -f $(NAME)

$(MLX_LIB):
	@$(MAKE) re -C ./mlx_linux

re: fclean all
