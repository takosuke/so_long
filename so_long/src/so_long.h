
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define TILE_WIDTH 16
# define TILE_HEIGHT 16
# define MLX_ERROR 1
# define WALL_IMG_PATH "./media/wall.xpm"
# define FLOOR_IMG_PATH "./media/floor.xpm"
# define COLLECTIBLE_IMG_PATH "./media/collectible.xpm"
# define EXIT_IMG_PATH "./media/exit.xpm"
# define PLAYER_IMG_PATH "./media/player.xpm"

/*
typedef struct s_map
{
	char	**map;
//	int		rem_items;;
} t_map;
*/

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

typedef struct s_sprite
{
//	char	type;
	void	*img;
//	char	*img_path;
	int		width;
	int		height;
} t_sprite;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	base_width;
	size_t	base_height;
	char	*map_path;
	t_img	img;
	int		offset;
	char	**map;
} t_data;

typedef struct s_tile
{
	void	*player;
	void	*wall;
	void	*space;
	void	*item;
	void	*exit;
} t_tile;

t_sprite	*init_sprite(t_data *data, char *path);
//MAP
void	get_map_size(t_data *data);
void	init_map(t_data *data);
//INPUT
int		handle_keypress(int keysym, t_data *data);
//RENDERING
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_data *data);
void	render_items(t_data *data);
int		render(t_data *data);
void	render_player(t_data *data);

#endif
