/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:37:15 by moashraf          #+#    #+#             */
/*   Updated: 2026/03/29 18:37:19 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Bernstein polynomial smooth coloring.
** Maps iteration count to an RGB value using polynomial curves,
** producing a smooth "psychedelic" gradient effect.
*/
int	get_color(int iter, t_fractal *f)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / (double)f->iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}
