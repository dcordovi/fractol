#include "../incs/fractol.h"

void	move_up(t_var *vars)
{
	vars->off_set_y -= 40;
	put_image();
}

void	move_down(t_var *vars)
{
	vars->off_set_y += 40;
	put_image();
}

void	move_left(t_var *vars)
{
	vars->off_set_x -= 40;
	put_image();
}

void	move_right(t_var *vars)
{
	vars->off_set_x += 40;
	put_image();
}

int exit_program(t_var *vars)
{
    mlx_destroy_image(vars->win->mlx_ptr, vars->img_ptr->img_ptr);
    mlx_destroy_window(vars->win->mlx_ptr, vars->win->win_ptr);
    free(vars->win->mlx_ptr);
    exit(0);
}