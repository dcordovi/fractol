#include "../incs/fractol.h"
int	key_hook(int keycode, t_var *vars)
{
    printf("%d\n", keycode);
	if (keycode == ESC_KEY || keycode == CROSS)
		exit_program(vars);
	else if (keycode == KEY_UP)
		move_up(vars);
	else if (keycode == KEY_DOWN)
		move_down(vars);
	else if (keycode == KEY_LEFT)
		move_left(vars);
	else if (keycode == KEY_RIGHT)
		move_right(vars);
	return (0);
}

int	mouse_hook(int keycode)
{
	if (keycode == SCROLL_UP)
		zoom_in(vars());
	else if (keycode == SCROLL_DOWN)
		zoom_out(vars());
	else if (keycode == LEFT_CLICK)
		new_fractol();
	return (0);
}