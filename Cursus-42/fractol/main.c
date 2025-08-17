/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:57:29 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:17:33 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixel(t_f *f, int color, int i)
{
	char	*pix;

	pix = f->ptr_img + (f->y * (f->size_line) + f->x * (f->bits_per_pixel / 8));
	*(unsigned int *)pix = color * i % 0xffffff;
}

int	draw_fractal(t_f *f)
{
	f->y = 0;
	while (f->y < W_HEIGHT)
	{
		f->x = 0;
		while (f->x < W_WIDTH)
		{
			if (f->f_type == 'j')
			{
				calc_julia(f);
			}
			else if (f->f_type == 'm')
				calc_mandelbrot(f);
			else if (f->f_type == 'b')
				calc_burningship(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_f	*f;

	if (!(ac == 2 || ac == 4 || ac == 6))
	{
		ft_input_msg(1);
		return (0);
	}
	f = ft_init_fdata(av);
	if (ac > 2 && f->f_type == 'j')
		ft_param_julia(ac, av, f);
	if (ac > 2)
		ft_param_render(ac, av, f);
	mlx_key_hook(f->mlx_win, key_input, f);
	mlx_mouse_hook(f->mlx_win, mouse_input, f);
	mlx_hook(f->mlx_win, 17, 0, exit_clean, f);
	draw_fractal(f);
	mlx_loop(f->mlx);
	exit_clean(f);
	return (0);
}
