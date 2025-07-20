#include "so_long.h"
#include <stdio.h>

void	find_player(t_game *game)
{
	int	x;
	int	y;

	size(&game->map);
	x = 0;
	y = 0;
	game->map.c = 0;
	game->player.c = 0;
	game->player.count_move = 0;
	while (game->map.y > y)
	{
		while (x < game->map.x)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
			}
			else if (game->map.map[y][x] == 'C')
				game->map.c++;
			x++;
		}
		y++;
		x = 0;
	}
}

void	moves(t_game *game, int x, int y)
{
	
	if (game->map.map[y][x] == 'E' && game->player.c != game->map.c)
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x
			* IMG_PXL, y * IMG_PXL);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img.empty, x
			* IMG_PXL, y * IMG_PXL);
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->player.c++;
		game->map.map[game->player.y][game->player.x] = '0';
	}
	if (game->map.map[game->player.y][game->player.x] == 'E'
		&& game->player.c == game->map.c)
	{
		ft_printf("🎉 YOU WIN 🎉\n");
		close_window(game);
	}
	game->player.count_move++;
	ft_printf("Number of steps: %d\n", game->player.count_move);
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (game->map.map[y - 1][x] != '1')
	{
		game->player.y--;
		moves(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x
			* IMG_PXL, (y - 1) * IMG_PXL);
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (game->map.map[y + 1][x] != '1')
	{
		game->player.y++;
		moves(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x
			* IMG_PXL, (y + 1) * IMG_PXL);
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (game->map.map[y][x - 1] != '1')
	{
		game->player.x--;
		moves(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, (x - 1)
			* IMG_PXL, y * IMG_PXL);
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (game->map.map[y][x + 1] != '1')
	{
		game->player.x++;
		moves(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, (x + 1)
			* IMG_PXL, y * IMG_PXL);
	}
}
