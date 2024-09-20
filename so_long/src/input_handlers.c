#include "so_long.h"

void	move_left(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				if (data->rem_items == 0 && data->map[j][i - 1])
					data->victory = 1;
				else if (data->map[j][i - 1] == '1')
					return ;
				else if (data->map[j][i - 1] == 'C')
					data->rem_items--;
				data->map[j][i - 1] = 'P';
				data->map[j][i] = '0';
				render(data);	
			}
			i++;
		}
		j++;
	}
}
					

	// generalize it to move_anywhere?
	// look thru map, check where player is and if he can move left
	// moves++
	// check if there's an item
	// if there's one, remove it from item remaining list and replace it in map
	// with the player
	// if theres no items left, check if there's the exit
	// update the map
	// re render everything
	// optional - load a left facing sprite?(or move spritesheet)
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Left)
	{
		printf("lef\n");
		move_left(data);
//		data->offset -= 10;
//		render_fg(data);
	}
	/*
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
//		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}
