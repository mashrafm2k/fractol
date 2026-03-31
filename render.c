/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:38:47 by moashraf          #+#    #+#             */
/*   Updated: 2026/03/31 12:32:35 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

int	dynamic_iterations(double zoom)
{
	int	iter;

	iter = (int)(50 + 50 * log(1.0 / zoom));
	if (iter < 50)
		iter = 50;
	if (iter > 500)
		iter = 500;
	return (iter);
}

void	handle_pixel(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	z.re = map(x, -2.0, 2.0, WIDTH) * f->zoom + f->shift_x;
	z.im = map(y, 2.0, -2.0, HEIGHT) * f->zoom + f->shift_y;
	if (f->type == MANDELBROT)
	{
		c = z;
		if (in_mandelbrot_bulb(c))
		{
			put_pixel(x, y, 0x000000, &f->img);
			return ;
		}
	}
	else
	{
		c.re = f->julia_re;
		c.im = f->julia_im;
	}
	iter = iterate(z, c, f->iterations);
	if (iter == f->iterations)
		put_pixel(x, y, 0x000000, &f->img);
	else
		put_pixel(x, y, get_color(iter, f), &f->img);
}

static void	*render_thread(void *arg)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)arg;
	y = t->y_start;
	while (y < t->y_end)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, t->fractal);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	fractal_render(t_fractal *f)
{
	pthread_t	threads[NUM_THREADS];
	t_thread	data[NUM_THREADS];
	int			i;
	int			chunk;

	f->iterations = dynamic_iterations(f->zoom);
	chunk = HEIGHT / NUM_THREADS;
	i = 0;
	while (i < NUM_THREADS)
	{
		data[i].fractal = f;
		data[i].y_start = i * chunk;
		data[i].y_end = (i + 1) * chunk;
		if (i == NUM_THREADS - 1)
			data[i].y_end = HEIGHT;
		pthread_create(&threads[i], NULL, render_thread, &data[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}
