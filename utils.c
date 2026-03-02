#include "fractol.h"

void	handle_error(void)
{
	write(2, "Error: invalid arguments.\n", 26);
	write(2, "Usage: ./fractol mandelbrot\n", 28);
	write(2, "Usage: ./fractol julia <re> <im>\n", 33);
	exit(1);
}

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
