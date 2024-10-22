#include "so_long.h"

int	check_map(t_data *data)
{
    if (!check_map_is_square(data) || !check_map_is_enclosed(data) || !check_map_elements(data))
//  if (!check_map_is_square(data) || check_map_is_enclosed(data))
    return (0);
  else
		return (1);
}

int	check_map_is_square(t_data *data)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != len)
		{
			perror("Map is not square");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_is_enclosed(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	enclosed;

	i = -1;
	j = -1;
	enclosed = 1;
	while (data->map[++i])
	{
		if (i == 0 || i == data->base_height - 1)
		{
			while (data->map[i][++j])
				if (data->map[i][j] != '1')
					enclosed = 0;
			j = -1;
		}
		else
			if (data->map[i][0] != '1' || data->map[i][data->base_width - 1] != '1')
				enclosed = 0;
	}
	if (!enclosed)
		perror("Map not enclosed");
	return (enclosed);
}

int	check_map_elements(t_data *data)
{
	size_t	exit;
	size_t	items;
	size_t	player;
	size_t	i;
	size_t	j;

	printf("why not arriving here\n");
	i = -1;
	j = -1;
	exit = 0;
	player = 0;
	items = 0;
	while (data->map[++i])
	{
		while (data->map[i][++j])
			if (data->map[i][j] == 'E')
				exit++;
			else if (data->map[i][j] == 'C')
				items++;
			else if (data->map[i][j] == 'P')
				player++;
		j = -1;
	}
	printf("Num exits: %zu Num players: %zu Num items: %zu\n", exit, player, items);
	if (exit != 1 || items < 1 || player != 1)
	{
		perror("incorrect map elements");
		return (0);
	}
	return (1);
}
