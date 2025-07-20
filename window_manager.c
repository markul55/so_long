#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map.map);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.empty)
		mlx_destroy_image(game->mlx, game->img.empty);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup_game(game);
	exit(EXIT_SUCCESS);
}
