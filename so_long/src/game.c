#include "so_long.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data);
	render_items(data);
	render_player(data);
	if (data->victory)
		render_exit(data);

	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

	data.map_path = argv[1];
	if (argc > 1)
	{
		init_map(&data);
		printf("width: %zu height: %zu\n", data.base_width, data.base_height);
	}
	else
	{
		printf("Must supply a map file\n");
		exit(1);
	}
	if (!check_map(&data))
		exit(1);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, TILE_WIDTH * data.base_width, TILE_HEIGHT * data.base_height, "I have opened a window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	data.offset = 0;
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, TILE_WIDTH * data.base_width, TILE_HEIGHT * data.base_height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
//	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_expose_hook(data.win_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);

//	mlx_destroy_display(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    free(data.mlx_ptr);
}
