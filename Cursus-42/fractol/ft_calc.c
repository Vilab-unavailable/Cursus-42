/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:18:03 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:18:05 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_burningship(t_f *f)
{
	int		i;
	double	temp_zx;

	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iter && (f->zx * f->zx) + (f->zy * f->zy) < 4.0)
	{
		temp_zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = ft_d_absolute(2 * f->zy * f->zx + f->cy);
		f->zx = temp_zx;
		i++ ;
	}
	if (i == f->max_iter)
		color_pixel(f, f->color_nd, 1);
	else
		color_pixel(f, f->color_d, i);
}

void	calc_julia(t_f *f)
{
	int		i;
	double	temp_zx;

	f->zx = (f->x / f->zoom) + f->offset_x;
	f->zy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iter && (f->zx * f->zx) + (f->zy * f->zy) < 4.0)
	{
		temp_zx = f->zx;
		f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2 * f->zy * temp_zx + f->cy;
		i++ ;
	}
	if (i == f->max_iter)
		color_pixel(f, f->color_nd, 1);
	else
		color_pixel(f, f->color_d, i);
}

void	calc_mandelbrot(t_f *f)
{
	int		i;
	double	temp_zx;

	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iter && (f->zx * f->zx) + (f->zy * f->zy) < 4.0)
	{
		temp_zx = f->zx;
		f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2 * f->zy * temp_zx + f->cy;
		i++ ;
	}
	if (i == f->max_iter)
		color_pixel(f, f->color_nd, 1);
	else
		color_pixel(f, f->color_d, i);
}
