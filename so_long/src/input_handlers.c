#include "so_long.h"


void	find_player(t_data *data)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_pos[0] = j;
				data->player_pos[1] = i;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	move(t_data *data, int x, int y)
{
	int		player_x;
	int		player_y;

	printf("MOVE!\n");
	find_player(data);
	printf("player: %d %d\n", data->player_pos[0], data->player_pos[1]);
	player_x = data->player_pos[0];
	player_y = data->player_pos[1];
	if (data->map[player_y + y][player_x + x] == '1')
		return ;
	else if (data->map[player_y + y][player_x + x] == 'C')
	{
		data->rem_items--;
		if (data->rem_items == 0)
			data->victory = 1;
	}
	data->map[player_y + y][player_x + x] = 'P';
	data->map[player_y][player_x] = '0';

	/*
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				printf("found player at map[%d][%d]\n", j, i);
				printf("moving player to map[%d][%d]\n", j + y, i + x);
				if (data->rem_items == 0 && data->map[j + y][i + x])
					data->victory = 1;
				else if (data->map[j + y][i + x] == '1')
					return ;
				else if (data->map[j + y][i + x] == 'C')
					data->rem_items--;
				data->map[j + y][i + x] = 'P';
				data->map[j][i] = '0';
			}
			i++;
			
		}
		i = 0;
		j++;
	}
	*/
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
	//if (keysym == 0)
  if (keysym == XK_a)
	{
		printf("lef\n");
		move(data, -1, 0);
		render(data);	
	}
	//if (keysym == 2)
  if (keysym == XK_d)
	{
		printf("RIGHT\n");
		move(data, 1, 0);
		render(data);	
	}
	//if (keysym == 13)
  if (keysym == XK_w)
	{
		printf("up\n");
		move(data, 0, -1);
		render(data);	
	}
	//if (keysym == 1)
  if (keysym == XK_s)
	{
		printf("down\n");
		move(data, 0, 1);
		render(data);	
	}
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
