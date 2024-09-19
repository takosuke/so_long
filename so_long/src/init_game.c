#include "so_long.h"

t_sprite	*init_sprite(t_data *data, char *path)
{
	t_sprite	*sprite;
	
	sprite = malloc(sizeof(t_sprite));
	sprite->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &sprite->width, &sprite->height);
	return (sprite);	
}
