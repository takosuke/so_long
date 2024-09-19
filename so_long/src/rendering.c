#include "so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel= color;
}

void	render_background(t_data *data)
{
	size_t		i;
	size_t		j;
	char	*line;
	int		fd;
	t_sprite	*wall;
	t_sprite	*floor;
	t_sprite	*collectible;
	t_sprite	*exit;


	j = 0;
	wall = init_sprite(data, WALL_IMG_PATH);
	floor = init_sprite(data, FLOOR_IMG_PATH);
	collectible = init_sprite(data, COLLECTIBLE_IMG_PATH);
	exit = init_sprite(data, EXIT_IMG_PATH);
	fd = open(data->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (j < data->base_height)
	{
		i = 0;
		while (i < data->base_width)
		{
			if (line[i] == '0' || line[i] == 'P' || line[i] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, floor->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			else if (line[i] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			else if (line[i] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, exit->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			i++;
		}
		j++;
		line = get_next_line(fd);
	}
}

