#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define W_WIDTH 			800
# define W_HEIGHT			600

# define ESC          53
# define LEFT         123
# define RIGHT        124
# define DOWN         125
# define UP           126
# define UP           126
# define UP           126
# define UP           126
# define UP           126


# define SCROLL_UP    4
# define SCROLL_DOWN  5

typedef struct s_fdata
{
  void    *mlx;
  void    *mlx_win;
  char    f_type;
  int     x;
  int     y;
  double  x_i;
  double  y_i;
  double  x_delta;
  double  y_delta;
  double  sx;
  double  sy;
  double  zoom;
  int     max_iter;
  

  

 fdata.x = 0;
  fdata.y = 0;
  fdata.x_delta = 0;
  fdata.y_delta = 0;
  fdata.zoom = 0;
  fdata.max_iter = 50;
  fdata.color = 0xFCBE11;

#endifdef
