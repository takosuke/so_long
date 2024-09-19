#include "so_long.h"

void		get_map_size(t_data *data)
{
	char		*line;
	int			fd;

	// check if file exists
	fd = open(data->map_path, O_RDONLY);
	line = get_next_line(fd);
	data->base_width = ft_strlen(line);
	if (ft_strrchr(line, '\n'))
	{
		data->base_width--;
	}
	// bunch of stuff to make sure the map is the right dimensions
	// rectangular, more than one line etc
	data->base_height = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->base_height++;
	}
}

void	init_map(t_data *data)
{
	size_t		i;
	char		*line;
	int			fd;

	// move to a general init function?
	get_map_size(data);
	data->map = malloc((data->base_height + 1) * sizeof(char *));
	// if null blahbla
	i = 0;
	fd = open(data->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
}

