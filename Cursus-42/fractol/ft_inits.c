/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:18:48 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:18:52 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_f_mlx(t_f *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit_clean(f);
	if (f->f_type == 'j')
		f->mlx_win = mlx_new_window(f->mlx, W_WIDTH, W_HEIGHT, "Julia");
	else if (f->f_type == 'm')
		f->mlx_win = mlx_new_window(f->mlx, W_WIDTH, W_HEIGHT, "Mandelbrot");
	else
		f->mlx_win = mlx_new_window(f->mlx, W_WIDTH, W_HEIGHT, "BurningShip");
	f->mlx_img = mlx_new_image(f->mlx, W_WIDTH, W_HEIGHT);
	f->ptr_img = mlx_get_data_addr(f->mlx_img, &f->bits_per_pixel,
			&f->size_line, &f->endian);
}

t_f	*ft_init_fdata(char **av)
{
	t_f	*f;	

	f = malloc(sizeof(t_f));
	if (!f)
		exit(-1);
	if (av[1][0] && !av[1][1] && (av[1][0] == 'm' || av[1][0] == 'b' ||
			av[1][0] == 'j'))
		f->f_type = av[1][0];
	else
		exit_clean(f);
	f->x = 0;
	f->y = 0;
	f->custom_c = 0;
	f->cx = 0.285;
	f->cy = 0.01;
	f->offset_x = -2.0;
	f->offset_y = -1.5;
	f->zoom = 200;
	f->max_iter = 100;
	f->color_d = 0x664422;
	f->color_nd = 0x000000;
	ft_init_f_mlx(f);
	return (f);
}
