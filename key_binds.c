#include "so_long.h"

int	key_binds(int keycode, t_game *game)
{
	if (keycode == UP) // W lub strzałka w górę
		move_up(game);
	if (keycode == DOWN) // S lub strzałka w dół
	    move_down(game);
	if (keycode == LEFT) // A lub strzałka w lewo
	    move_left(game);
	if (keycode == RIGHT) // D lub strzałka w prawo
	    move_right(game);
	if (keycode == ESC) // ESC
		close_window(game);
	return (0);
}