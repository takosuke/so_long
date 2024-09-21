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
	t_sprite	*wall;
	t_sprite	*floor;
	t_sprite	*exit;

	//let's init the sprites elsewhere so they don't have to be loaded every
	//time
	j = 0;
	wall = init_sprite(data, WALL_IMG_PATH);
	floor = init_sprite(data, FLOOR_IMG_PATH);
	exit = init_sprite(data, EXIT_IMG_PATH);
	while (j < data->base_height)
	{
		printf("%s\n", data->map[j]);
		i = 0;
		while (i < data->base_width)
		{
			if (data->map[j][i] == '0' || data->map[j][i] == 'P' || data->map[j][i] == 'C' || data->map[j][i] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, floor->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			else if (data->map[j][i] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			i++;
		}
		j++;
	}
}

void	render_items(t_data *data)
{
	size_t		i;
	size_t		j;
	t_sprite	*collectible;


	j = 0;
	collectible = init_sprite(data, COLLECTIBLE_IMG_PATH);
	while (j < data->base_height)
	{
		i = 0;
		while (i < data->base_width)
		{
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, collectible->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			i++;
		}
		j++;
	}
}

void	render_player(t_data *data)
{
	size_t		i;
	size_t		j;
	t_sprite	*player;


	j = 0;
	player = init_sprite(data, PLAYER_IMG_PATH);
	while (j < data->base_height)
	{
		i = 0;
		while (i < data->base_width)
		{
			if (data->map[j][i] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			i++;
		}
		j++;
	}
}

void	render_exit(t_data *data)
{
	size_t		i;
	size_t		j;
	t_sprite	*exit;


	j = 0;
	exit = init_sprite(data, EXIT_IMG_PATH);
	while (j < data->base_height)
	{
		i = 0;
		while (i < data->base_width)
		{
			if (data->map[j][i] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, exit->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			i++;
		}
		j++;
	}
}
