/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:23:07 by moashraf          #+#    #+#             */
/*   Updated: 2026/03/31 12:23:10 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate(t_complex z, t_complex c, int max_iter)
{
	int	i;

	i = 0;
	while (i < max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.re * z.re) + (z.im * z.im) > 4.0)
			return (i);
		i++;
	}
	return (max_iter);
}

int	in_mandelbrot_bulb(t_complex c)
{
	double	q;

	q = (c.re - 0.25) * (c.re - 0.25) + c.im * c.im;
	if (q * (q + (c.re - 0.25)) <= 0.25 * c.im * c.im)
		return (1);
	if ((c.re + 1) * (c.re + 1) + c.im * c.im <= 0.0625)
		return (1);
	return (0);
}
