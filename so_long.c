#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac == 2)
	{
		game.map.map = read_map(av[1], &game);
		find_player(&game);
		printf("dupa\n");
		if (error_win_size(&game))
			close_window(&game);
		printf("dupa\n");
		if (checking_all_the_things_that_need_to_be_checked(&game, av[1]))
		{
			if (error_map())
				close_window(&game);
		}
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, IMG_PXL * game.map.x, IMG_PXL
				* game.map.y, WND_NAME);
		put_image(&game);
		map_print(&game, game.map.map);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_key_hook(game.win, key_binds, &game);
		mlx_loop(game.mlx);
		return (0);
	}
}
