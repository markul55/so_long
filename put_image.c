#include "so_long.h"

void	put_image(t_game *game)
{
	int	width;
	int	height;

	game->img.player = mlx_xpm_file_to_image(game->mlx, "src/img/player.xpm",
			&width, &height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "src/img/wall.xpm",
			&width, &height);
	game->img.empty = mlx_xpm_file_to_image(game->mlx, "src/img/floor.xpm",
			&width, &height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, "src/img/gold.xpm",
			&width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "src/img/exit.xpm",
			&width, &height);
	if (!game->img.player || !game->img.wall || !game->img.empty
		|| !game->img.collectible || !game->img.exit)
	{
		write(2, "Error\nFailed to load one or more image files.\n", 47);
	}
}
