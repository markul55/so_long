#include "so_long.h"

int	error_map(void)
{
	write(2,
		"Error\nThere is something wrong with the map. Check if map is:\na rectangle\nall the edges are 1\nhas only these characters:1 0 P C E\nhas at least one C and player can get to it\nhas only one P and one E\nthere is a path from P to E\n",
		227);
	return (1);
}

int	error_win_size(t_game *game)
{
	if (1920 < game->map.x * IMG_PXL || 1080 < game->map.y * IMG_PXL)
	{
		write(2, "Error\nMap is too big\n", 21);
		return (1);
	}
	return(0);
}

int	error_arg(void)
{
	write(2, "Error\nWrong number of arguments\n", 32);
	return (1);
}