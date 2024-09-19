#include "so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel= color;
}

void	render_tiles(t_data *data)
{
//	void	*img;
//	void	*img2;
//	char	*img_path ="./media/wooden.xpm";
//	char	*img_path2 ="./media/rock.xpm";
//	int		img_width;
//	int		img_height;
//	int		img2_width;
//	int		img2_height;
	size_t		i;
	size_t		j;
	char	*line;
	int		fd;
	t_sprite	*wall;
	t_sprite	*floor;


	j = 0;
	wall = init_sprite(data, WALL_IMG_PATH);
	floor = init_sprite(data, FLOOR_IMG_PATH);
//	img = mlx_xpm_file_to_image(data->mlx_ptr, img_path, &img_width, &img_height);
//	img2 = mlx_xpm_file_to_image(data->mlx_ptr, img_path2, &img2_width, &img2_height);
	fd = open(data->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (j < data->base_height)
	{
		i = 0;
		while (i < data->base_width)
		{
			if (line[i] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			else if (line[i] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, floor->img, i * TILE_WIDTH, j * TILE_HEIGHT);
			i++;
		}
		j++;
		line = get_next_line(fd);
	}
}

