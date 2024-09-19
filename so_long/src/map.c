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
		line = get_next_line(fd);
		data->base_height++;
	}
}
