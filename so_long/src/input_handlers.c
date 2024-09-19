#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	/*
	if (keysym == XK_Left)
	{
		printf("lef\n");
		data->offset -= 10;
		render_fg(data);
	}
	if (keysym == XK_Right)
	{
		printf("RIGH\n");
		data->offset += 10;
		render_fg(data);
	}
	*/
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}
