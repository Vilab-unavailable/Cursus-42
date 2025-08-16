/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:57:14 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/16 20:57:16 by vilabard         ###   ########.fr       */
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
//# include <float.h>

# define DBL_MAX	1E+37
# define DBL_MIN	1E-37

# define W_WIDTH	10
# define W_HEIGHT 10

# define ESC	53

# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126

# define A		97
# define D		100
# define W		119
# define S		115


# define SCROLL_UP		4
# define SCROLL_DOWN	5

typedef struct s_f
{
  void		*mlx;
  void		*mlx_win;
  void		*mlx_img;
  void    *ptr_img;
  int     bits_per_pixel;
  int     size_line;
  int     endian;
  char		f_type;
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
  int		  max_iter;
  int     color;

  
}  t_f;
#endif
