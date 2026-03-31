/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:37:45 by moashraf          #+#    #+#             */
/*   Updated: 2026/03/31 12:26:45 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define NUM_THREADS 12
# define MANDELBROT 1
# define JULIA 2

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			type;
	double		julia_re;
	double		julia_im;
	double		zoom;
	double		shift_x;
	double		shift_y;
	int			iterations;
}	t_fractal;

typedef struct s_thread
{
	t_fractal	*fractal;
	int			y_start;
	int			y_end;
}	t_thread;

/* init.c */
void		fractal_init(t_fractal *f);

/* fractal_math.c */
int			iterate(t_complex z, t_complex c, int max_iter);
int			in_mandelbrot_bulb(t_complex c);

/* render.c */
void		handle_pixel(int x, int y, t_fractal *f);
int			dynamic_iterations(double zoom);
void		fractal_render(t_fractal *f);

/* hooks.c */
int			handle_mouse(int button, int x, int y, t_fractal *f);
int			handle_key(int keysym, t_fractal *f);
int			close_handler(t_fractal *f);

/* parse.c */
void		validate_args(int ac, char **av, t_fractal *f);

/* color.c */
int			get_color(int iter, t_fractal *f);

/* complex.c */
t_complex	sum_complex(t_complex c1, t_complex c2);
t_complex	square_complex(t_complex c);

/* utils.c */
double		map(double val, double new_min, double new_max, double old_max);
double		ft_atof(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		handle_error(void);

#endif
