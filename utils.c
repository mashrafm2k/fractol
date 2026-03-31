/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moashraf <moashraf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:38:53 by moashraf          #+#    #+#             */
/*   Updated: 2026/03/31 12:07:43 by moashraf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_error(void)
{
	int	r;

	r = write(2, "Error: invalid arguments.\n", 26);
	r += write(2, "Usage: ./fractol mandelbrot\n", 28);
	r += write(2, "Usage: ./fractol julia <re> <im>\n", 33);
	(void)r;
	exit(1);
}

/*
** Maps a value from [0, old_max] to [new_min, new_max].
*/
double	map(double val, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * val / old_max + new_min);
}

double	ft_atof(char *s)
{
	long	int_part;
	double	dec_part;
	double	pow;
	int		sign;

	int_part = 0;
	dec_part = 0;
	sign = 1;
	pow = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
		int_part = int_part * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		pow /= 10;
		dec_part = dec_part + (*s++ - '0') * pow;
	}
	return ((int_part + dec_part) * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
