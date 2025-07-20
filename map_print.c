#include "so_long.h"
#include <fcntl.h>

int	check_ber(const char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i > 4)
	{
		if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b' && str[i
			- 4] == '.')
			return (0);
	}
	write(2, "Error\nWrong type of file\n", 26);
	exit(EXIT_FAILURE);
}
int	open_map_file(const char *path)
{
	int	fd;

	check_ber(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nFailed to open file\n", 27);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	size(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map[y])
	{
		y++;
	}
	while (map->map[0][x])
	{
		x++;
	}
	map->x = x;
	map->y = y;
}

char	**read_map(const char *path, t_game *game)
{
	int		fd;
	char	*content;
	char	*line;
	char	**map;


	fd = open_map_file(path);
	content = ft_strdup("");
	while ((line = ft_get_next_line(fd)) != NULL)
	{
		game->map.tmp = content;
		content = ft_strjoin(content, line);
		free(game->map.tmp);
		free(line);
	}
	map = ft_split(content, '\n');
	close(fd);
	free(content);
	return (map);
}

void	image_print(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x
			* IMG_PXL, y * IMG_PXL);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.empty, x
			* IMG_PXL, y * IMG_PXL);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x
			* IMG_PXL, y * IMG_PXL);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.collectible, x
			* IMG_PXL, y * IMG_PXL);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x
			* IMG_PXL, y * IMG_PXL);
	else
	{
		write(2, "Error: map not loaded\n", 22);
		exit(EXIT_FAILURE);
	}
}

void	map_print(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			image_print(game, map[y][x], x, y);
			x++;
		}
		y++;
	}
}
