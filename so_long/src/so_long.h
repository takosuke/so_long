
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
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1
# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00
# define WHITE_PIXEL 0x00FAFAFA
# define WALL_IMG_PATH "./media/rock.xpm"
# define FLOOR_IMG_PATH "./media/wooden.xpm"
// crap
# define TEST_BG "./media/bg.xpm"
# define TEST_ALPHA "./media/alpha.xpm"

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
} t_data;

typedef struct s_tile
{
	void	*player;
	void	*wall;
	void	*space;
	void	*item;
	void	*exit;
} t_tile;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
} t_rect;

t_sprite	*init_sprite(t_data *data, char *path);
void	get_map_size(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
//void	render_background(t_data *data);
void	render_tiles(t_data *data);
int		render(t_data *data);

#endif
