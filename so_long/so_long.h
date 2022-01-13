#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>

# define IMG_PATH "./images/path.xpm"
# define IMG_COLLECTIBLE "./images/collectible.xpm"
# define IMG_EXIT "./images/exit.xpm"
# define IMG_WALL "./images/wall.xpm"
# define IMG_PLAYER "./images/player.xpm"

# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_ESC 53
# define PRINT_HERE() (printf("file: %s, line: %d\n", __FILE__, __LINE__))

typedef struct s_map
{
	char	**map;
	int		r;
	int		col;
}	t_map;

typedef struct s_player
{
	int		p_row;
	int		p_col;
	int		count_moves;
}	t_player;

typedef struct s_fields
{
	int		f_row;
	int		f_col;
	int		c_count;
	int		e_count;
	int		p_count;
}	t_fields;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		mid_width;
	int		mid_height;
	int		img_size;
}	t_window;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_fields	fields;
	t_img		*img[5];
	t_window	window;
}	t_game;

int			main(int argc, char **argv);
void		ft_mapalloc(char **argv, t_game *game);
void		ft_fill_map(char **argv, t_game *game, int fd);

void		ft_check_validmap_walls(t_game *game);
void		ft_check_validmap_content(t_game *game);
void		ft_validmap_content_count(t_game *game);

void		ft_alloc_images(t_game *game);
void		ft_create_surface(t_game *game);
void		*ft_which_img(t_game *game, int x, int y);

void		ft_start_game(t_game *game);
void		ft_find_playercoord(t_game *game);

int			ft_move(int key, t_game *game);

int			ft_strchr_so_long(const char *s, int c);
void		ft_exit(void);
int			ft_exitgame(void);
void		ft_reset(t_game *game);
void		ft_reset_2(t_game *game);

// void	ft_map(t_game *game);
#endif