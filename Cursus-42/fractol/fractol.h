/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:57:14 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:17:20 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define DBL_MAX	1E+37
# define DBL_MIN	1E-37
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

# define W_WIDTH	1000
# define W_HEIGHT	1000

# define ESC	65307

# define LEFT 	65361
# define RIGHT  65363
# define DOWN	65364
# define UP	  	65362

# define A		97
# define D		100
# define W		119
# define S		115

# define SCROLL_UP		4
# define SCROLL_DOWN	5

typedef struct s_f
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	void	*ptr_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	f_type;
	int		x;
	int		y;
	int		custom_c;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zx;
	double	zy;
	double	zoom;
	int		max_iter;
	int		color_d;
	int		color_nd;

}	t_f;

// main
void		color_pixel(t_f *f, int color, int i);
int			draw_fractal(t_f *f);

// ft_inits
void		ft_init_f_mlx(t_f *f);
t_f			*ft_init_fdata(char **av);

// ft_params
int			ft_convert_color(t_f *f, char *str);
void		ft_param_julia(int ac, char **av, t_f *f);
void		ft_param_render(int ac, char **av, t_f *f);

// ft_calc

void		calc_burningship(t_f *f);
void		calc_julia(t_f *f);
void		calc_mandelbrot(t_f *f);

// ft_convert_base
int			ft_atoi_base(char *str, char *base);

// ft_key_mouse
int			key_input(int keycode, t_f *f);
int			apply_zoom(t_f *f, int x, int y, int dir);
int			mouse_input(int mouse_code, int x, int y, t_f *f);

// ft_exit
void		ft_input_msg(int n);
int			exit_clean(t_f *f);

// ft_utils
double		ft_d_absolute(double nbr);
int			ft_is_double(char *str);

// ft_atox
long long	ft_llong_atoi(const char *str);
double		ft_atof(const char *str);

#endif
