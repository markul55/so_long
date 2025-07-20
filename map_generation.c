#include "so_long.h"
#include <stdio.h>

int	check_char(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->map.p = 0;
	game->map.c = 0;
	game->map.e = 0;
	while (game->map.y > ++y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.map[y][x] == 'P')
				game->map.p++;
			else if (game->map.map[y][x] == 'C')
				game->map.c++;
			else if (game->map.map[y][x] == 'E')
				game->map.e++;
		}
	}
	if (game->map.p != 1 || game->map.e != 1 || game->map.c < 1)
		return (1);
	return (0);
}

int	is_immigrant_char(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.y > y)
	{
		while (x < game->map.x)
		{
			if (game->map.map[y][x] != 'P' && game->map.map[y][x] != 'C'
				&& game->map.map[y][x] != 'E' && game->map.map[y][x] != '0'
				&& game->map.map[y][x] != '1')
				return (1);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	is_rectangle(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		if ((int)ft_strlen(game->map.map[y]) != game->map.x)
		{
			return (1);
		}
		y++;
	}
	return (0);
}

int	edge_one(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (game->map.map[y])
	{
		while (game->map.map[y][x])
		{
			if (game->map.map[0][x] != '1')
				return (1);
			if (game->map.map[game->map.y - 1][x] != '1')
				return (1);
			x++;
		}
		if (game->map.map[y][game->map.x - 1] != '1'
			|| game->map.map[y][0] != '1')
			return (1);
		x = 0;
		y++;
	}
	return (0);
}

int	fill(char **map, int y, int x)
{
	int	c;

	c = 0;
	if (map[y][x] != 127 && map[y][x] != '1')
	{
		if (map[y][x] == 'C')
		{
			c++;
		}
		if (map[y][x] == 'E')
		{
			c++;
		}
		map[y][x] = 127;
		c += fill(map, y - 1, x);
		c += fill(map, y + 1, x);
		c += fill(map, y, x - 1);
		c += fill(map, y, x + 1);
	}
	return (c);
}

int	checking_all_the_things_that_need_to_be_checked(t_game *game, char *path)
{
	char	**copy;

	if (is_rectangle(game))
		return (1);
	if (is_immigrant_char(game))
		return (1);
	if (check_char(game))
		return (1);
	if (edge_one(game))
		return (1);
	copy = read_map(path, game);
	if (!(fill(copy, game->player.y, game->player.x) - 1 == game->map.c))
	{
		free_map(copy);
		return (1);
	}
	return (0);
}
