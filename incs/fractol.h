#ifndef FRACTOL_H
#define FRACTOL_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 600
#define HEIGHT 400
#define MAX_ITER 300

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_win
{
	void *mlx_ptr;
	void *win_ptr;
	int height;
	int width;
} t_win;

typedef struct s_img
{
	t_win win;
	void *img_ptr;
	char *addr;
	int h;
	int w;
	int bpp;
	int endian;
	int line_len;
} t_img;

typedef struct s_var
{
	t_win *win;
	t_img *img_ptr;
	char *fractol;
	int off_set_x;
	int off_set_y;
	int zoom_y;
	int zoom_x;
	double real;
	double imag;
} t_var;

t_win new_program(int w, int h, char *str);
t_img new_img(int w, int h, t_win window);
void put_pixel_img(t_img img, int x, int y, int color);
int key_hook(int keycode, t_var *vars);
int mouse_hook(int keycode);
int mandelbrot_img(t_img image, int mouse_x, int mouse_y);
int julia_img(t_img img, int mouse_x, int mouse_y);
int exit_program(t_var *vars);
void zoom_in(t_var *vars);
void zoom_out(t_var *vars);
t_var *vars(void);
int gen_trgb(int opacity, int red, int green, int blue);
t_win new_program(int w, int h, char *str);
int mandelbrot(void);
int julia(void);
int mandelbrot_pix(double real, double imag, int maxIterations);
int map_color(int intensity, int max);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int put_image(void);
void move_up(t_var *vars);
void move_down(t_var *vars);
void move_left(t_var *vars);
void move_right(t_var *vars);
void new_fractol(void);
int snowflake_img(t_img img, int mouse_x, int mouse_y);
int snowflake_pix(double real, double imag, int maxIterations);
int snowflake(void);


#define ESC_KEY 53
#define CROSS -16778144
#define LEFT_CLICK 1
#define RIGHT_CLICK 2
#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define KEY_LEFT 123
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_RIGHT 124

#endif