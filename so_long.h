#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libs/mlx.h"

# define UP 119    // 'w'
# define DOWN 115  // 's'
# define LEFT 97   // 'a'
# define RIGHT 100 // 'd'
# define ESC 65307 // Escape
# define IMG_PXL 32
# define WND_NAME "so_long"

typedef struct s_player
{
	int			y;
	int			x;
	int			c;
	int			count_move;

}				t_player;

typedef struct s_img
{
	void		*empty;
	void		*collectible;
	void		*wall;
	void		*exit;
	void		*player;
}				t_img;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		**map;
	char		**copy;
	char		*tmp;
	int			y;
	int			x;
	int			e;
	int			c;
	int			p;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_map		map;
}				t_game;

int				close_window(void *param);
int				movement(int keycode);
int				key_binds(int keycode, t_game *game);
void			put_image(t_game *game);
int				open_map_file(const char *path);
void			map_print(t_game *game, char **map);
char			**read_map(const char *path, t_game *game);
void			move_up(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			move_down(t_game *game);
void			find_player(t_game *game);
void			size(t_map *map);
int				checking_all_the_things_that_need_to_be_checked(t_game *game,
					char *path);
int				check_map_size(t_game *game);
int				error_map(void);
int				error_win_size(t_game *game);
void			free_map(char **map);
int				error_arg(void);

#endif