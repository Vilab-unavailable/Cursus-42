/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:57:29 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/16 20:57:31 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_clean(t_f *f)
{
	if (!f)
		exit(1);
	if (f->mlx_img)
 		mlx_destroy_image(f->mlx, f->mlx_img);
	if (f->mlx_win)
		mlx_destroy_window(f->mlx, f->mlx_win);
	if (f->mlx)
		free(f->mlx);
	free(f);
	exit(1);
	return (0);
}

void	color_pixel(t_f *f, int color, int i)
{
	char	*pix;

	pix = f->ptr_img + (f->y * (f->size_line) + f->x * (f->bits_per_pixel / 8));
	*(unsigned int*)pix = color * i;
}

//void	color_pixel(t_f *f, )
void calc_julia(t_f *f)
{
	int    i;
	double temp_zx;

	f->zx = (f->x / f->zoom) + f->offset_x;
	f->zy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iter && (f->zx * f->zx) + (f->zy * f->zy) < DBL_MAX)
	{
		temp_zx = f->zx;
		f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2 * f->zy * temp_zx + f->cy;
		i++ ;
		if (i >= f->max_iter)////////////////////////WWWWWWHHHHHHHHHHYYYYYYYYYYYYYYYYYYYYYYY?????????????
			color_pixel(f, 0x0000ff, 1); /////////////////////////////////////////////
		else if ((f->zx * f->zx) + (f->zy * f->zy) >= DBL_MAX)
			color_pixel(f, f->color, i); /////////////////////////////////////////////
	}
}

void calc_mandelbrot(t_f *f)
{
	int    i;
	double temp_zx;

	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while ( i < f->max_iter || (f->zx * f->zx) + (f->zy * f->zy) < DBL_MAX)
	{
		temp_zx = f->zx;
		f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2 * f->zy * temp_zx + f->cy;
		i++ ;
	}
	if (i == f->max_iter)
		color_pixel(f, 0x0000ff, 1);
	else
		color_pixel(f, f->color, i); 
}

int	draw_fractal(t_f *f)
{
	f->x = 0;
	while (f->x < W_WIDTH)
	{
		f->y = 0;
		while (f->y < W_HEIGHT)
		{
			if (f->f_type == 'j')
			{
			//	if (f->custom_c == 0)
			//	{
			//		f->cx = 0.285;
			//		f->cy = 0.01;
			//	}
				calc_julia(f);
			}
			else if (f->f_type == 'm')
				calc_mandelbrot(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img, 0, 0);
	return (0);
}

int	key_input(int keycode, t_f *f)
{
	if (keycode == ESC)
		exit_clean(f);
	else if(keycode == LEFT)
		f->offset_x -= 20 / f->zoom;
	else if(keycode == RIGHT)
		f->offset_x += 20 / f->zoom;
	else if(keycode == LEFT)
		f->offset_y -= 20 / f->zoom;
	else if(keycode == LEFT)
		f->offset_y += 20 / f->zoom;
	else if(keycode == W || keycode == S || keycode == D || keycode == A)
	{
		f->custom_c = 1;
		if(keycode == W && f->cy < DBL_MAX - 0.01)
			f->cy += 0.01;
		else if(keycode == S && f->cy > DBL_MIN + 0.01)
			f->cy -= 0.01;
		else if(keycode == D && f->cx < DBL_MAX - 0.01)
			f->cx += 0.01;
		else if(keycode == A && f->cx > DBL_MIN + 0.01)
			f->cx -= 0.01;
	}
	draw_fractal(f);
	return (0);
}

int	zoom_in(t_f *f)
{
	return (0 * f->x);
}

int	zoom_out(t_f *f)
{
	return (0 * f->y);
}

int	mouse_input(int mouse_code, t_f *f)
{
	if (mouse_code == SCROLL_UP)
		zoom_in(f);
	else if (mouse_code == SCROLL_UP)
		zoom_out(f);
	draw_fractal(f);
	return (0);
}

void	ft_init_f_mlx(t_f *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit_clean(f);
	if (f->f_type == 'j')
		f->mlx_win = mlx_new_window(f->mlx, W_WIDTH, W_HEIGHT, "Julia");
	else
		f->mlx_win = mlx_new_window(f->mlx, W_WIDTH, W_HEIGHT, "Mandelbrot");
	f->mlx_img = mlx_new_image(f->mlx, W_WIDTH, W_HEIGHT);
	f->ptr_img = mlx_get_data_addr(f->mlx_img, &f->bits_per_pixel,
		&f->size_line, &f->endian);
}

t_f  *ft_init_fdata(char **av)
{
	t_f  *f;	
	f = malloc(sizeof(t_f));
	if (!f)
		exit(-1);
	if (!(av[1] && av[1][0] && !av[1][1] && (av[1][0] == 'j' || av [1][0] == 'm')))
	{
		free(f);
		exit(1);
	}
	f->f_type = av[1][0];
	f->x = 0;
	f->y = 0;
	f->custom_c = 0;
	f->cx = 0.285;
	f->cy = 0.01;
	f->offset_x = 0;
	f->offset_y = 0;
	f->zoom = 1;
	f->max_iter = 5;
	f->color = 0x004a10; //FCBE11
	ft_init_f_mlx(f);
	return (f);
}

int  main(int ac, char ** av)
{
	t_f  *f;	
	if  (ac != 2)
	{
		ft_strlen(av[0]);
		ft_putstr_fd("input <j> for julia or <m> for mandelbrot>\n", 1);
		return (0);
	}
	f = ft_init_fdata(av);
	mlx_key_hook(f->mlx_win, key_input, f);
	mlx_mouse_hook(f->mlx_win, mouse_input, f);
	mlx_hook(f->mlx_win, 17, 0, exit_clean, f);   // mask 0L ou (1L << 0) ?
	draw_fractal(f);
	mlx_loop(f->mlx);  
//	exit_clean(f);
	return (0);
}
