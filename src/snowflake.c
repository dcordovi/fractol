#include "../incs/fractol.h"

int snowflake_pix(double real, double imag, int maxIterations)
{
	double z_real;
	double z_imag;
	double new_real;
	double new_imag;
	int iter;

	z_real = real;
	z_imag = imag;
	iter = 0;
	while (iter < maxIterations && z_real * z_real + z_imag * z_imag < 4)
	{
		new_real = z_real * z_real * z_real - 3 * z_real * z_imag * z_imag + real;
		new_imag = 3 * z_real * z_real * z_imag - z_imag * z_imag * z_imag + imag;

		z_real = new_real;
		z_imag = new_imag;
		iter++;
	}
	return (iter);
}

int snowflake_img(t_img img, int mouse_x, int mouse_y)
{
	int y;
	int x;
	double real;
	double imag;

	y = mouse_y;
	while (y < HEIGHT + mouse_y)
	{
		x = mouse_x;
		while (x < WIDTH + mouse_x)
		{
			real = (x - img.w / 2.0) * 4.0 / img.w;
			imag = (y - img.h / 2.0) * 4.0 / img.w;
			put_pixel_img(img, x - mouse_x, y - mouse_y,
						  map_color(snowflake_pix(real, imag, MAX_ITER) * 2, MAX_ITER));
			x++;
		}
		y++;
	}
	return (0);
}

int snowflake(void)
{
	t_win tutorial;
	t_img img;

	tutorial = new_program(WIDTH, HEIGHT, "Snowflake");
	if (!tutorial.win_ptr)
		return (2);
	img = new_img(WIDTH, HEIGHT, tutorial);
	vars()->win = &tutorial;
	vars()->img_ptr = &img;
	snowflake_img(img, 0, 0);
	mlx_put_image_to_window(img.win.mlx_ptr, img.win.win_ptr,
							img.img_ptr, 0, 0);
	mlx_hook(tutorial.win_ptr, 2, 1L << 0, key_hook, vars());
	mlx_hook(tutorial.win_ptr, 17, 1L << 0, exit_program, vars());
	mlx_mouse_hook(tutorial.win_ptr, mouse_hook, vars());
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}