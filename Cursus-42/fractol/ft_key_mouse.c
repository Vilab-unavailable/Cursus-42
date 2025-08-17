/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:19:03 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:19:05 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_input(int keycode, t_f *f)
{
	if (keycode == ESC)
		exit_clean(f);
	else if (keycode == LEFT)
		f->offset_x -= W_WIDTH / 10 / f->zoom;
	else if (keycode == RIGHT)
		f->offset_x += W_WIDTH / 10 / f->zoom;
	else if (keycode == DOWN)
		f->offset_y += W_HEIGHT / 10 / f->zoom;
	else if (keycode == UP)
		f->offset_y -= W_HEIGHT / 10 / f->zoom;
	else if (keycode == W || keycode == S || keycode == D || keycode == A)
	{
		f->custom_c = 1;
		if (keycode == W && f->cy < DBL_MAX - 0.001)
			f->cy += 0.001;
		else if (keycode == S && f->cy > DBL_MIN + 0.001)
			f->cy -= 0.001;
		else if (keycode == D && f->cx < DBL_MAX - 0.001)
			f->cx += 0.001;
		else if (keycode == A && f->cx > DBL_MIN + 0.001)
			f->cx -= 0.001;
	}
	draw_fractal(f);
	return (0);
}

int	apply_zoom(t_f *f, int x, int y, int dir)
{
	double	zoom_step;
	double	center_x;
	double	center_y;

	zoom_step = 1.2;
	center_x = ((W_WIDTH / 2.0) / f->zoom) + f->offset_x;
	center_y = ((W_HEIGHT / 2.0) / f->zoom) + f->offset_y;
	if (dir == 1)
		f->zoom *= zoom_step;
	else
		f->zoom /= zoom_step;
	f->offset_x = center_x - ((W_WIDTH / 2.0) / f->zoom);
	f->offset_y = center_y - ((W_WIDTH / 2.0) / f->zoom);
	return (x + y + f->x);
}

int	mouse_input(int mouse_code, int x, int y, t_f *f)
{
	if (mouse_code == SCROLL_UP)
	{
		apply_zoom(f, x, y, 1);
	}
	else if (mouse_code == SCROLL_DOWN)
		apply_zoom(f, x, y, -1);
	draw_fractal(f);
	return (0);
}
