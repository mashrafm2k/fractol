#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	validate_args(ac, av, &fractal);
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
