/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:18:38 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:18:40 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_input_msg(int n)
{
	if (n == 1)
	{
		ft_putstr_fd("in: <f_type : m, b> + opt(<max_iter> <0xcolor>)\n", 1);
		ft_putstr_fd(" or <f_type : j> + opt(<double cx> <double cy>)\n", 1);
		ft_putstr_fd(" or <f_type : j> + <double cx> <double cy> +"
			" opt(<max_iter> <0xcolor>)\n", 1);
		ft_putstr_fd("\ncustom Julia parameters MUST be set "
			"before rendering options\n", 1);
		ft_putstr_fd("cx and cy must be between -2.0 an 2.0\n", 1);
		ft_putstr_fd("custom max_iter (1->1000) and color "
			"(0x000001->0xFFFFFF) can only be set both at once\n", 1);
	}
}

int	exit_clean(t_f *f)
{
	if (!f)
		exit(1);
	if (f->mlx_img)
	{
		mlx_destroy_image(f->mlx, f->mlx_img);
		f->mlx_img = NULL;
	}
	if (f->mlx_win)
	{
		mlx_clear_window(f->mlx, f->mlx_win);
		mlx_destroy_window(f->mlx, f->mlx_win);
		f->mlx_win = NULL;
	}
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	free(f);
	exit(1);
	return (0);
}
