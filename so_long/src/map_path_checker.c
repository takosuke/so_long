#include "so_long.h"

void	fill(char **tab, t_point size, t_point cursor, char c, int *x)
{
	if (cursor.x < 0 || cursor.y < 0 || cursor.x >= size.x || cursor.y >= size.y)
		return ;
	if (tab[cursor.y][cursor.x] == 'x')
	{
		printf("Exit accessible at tab[%d][%d]\n", cursor.y, cursor.x);
		*x = 1;
		return ;
//		exit = &cursor;
	}
	if (tab[cursor.y][cursor.x] != c)
		return ;
	tab[cursor.y][cursor.x] = 'F';
	fill(tab, size, (t_point){cursor.x - 1, cursor.y}, c, x);
	fill(tab, size, (t_point){cursor.x + 1, cursor.y}, c, x);
	fill(tab, size, (t_point){cursor.x, cursor.y - 1}, c, x);
	fill(tab, size, (t_point){cursor.x, cursor.y + 1}, c, x);
	return ;
}

void	flood_fill(t_data *data)
{
	char	c;
	int		i;
	int		x;
//	t_point	*exit;

	//exit = NULL;
	i = 0;
	x = 0;
	if (data->player_pos[0] > data->base_width - 1 || data->player_pos[1] > data->base_height - 1)
		return ;
//	c = tab[begin.y][begin.x];
	fill(tab, size, begin, c, &x);
//	fill(tab, size, begin, c, exit);
	printf("x: %d\n", x);
}


