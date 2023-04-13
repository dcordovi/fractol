#include "../incs/fractol.h"

int	map_color(int intensity, int max)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)intensity / max;
	r = (int)(255 * (1 - t) * t * t * t * 6);
	g = (int)(255 * (1 - t) * (1 - t) * t * t * 6);
	b = (int)(255 * (1 - t) * (1 - t) * (1 - t) * t * 6);
	return (gen_trgb(0, r, g, b));
}

int	gen_trgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}