#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <float.h>

# define W_WIDTH 			800
# define W_HEIGHT			600

# define ESC          53

# define LEFT         123
# define RIGHT        124
# define DOWN         125
# define UP           126

# define A           
# define D           
# define W           
# define S           


# define SCROLL_UP    4
# define SCROLL_DOWN  5

typedef struct s_f
{
  void    *mlx;
  void    *mlx_win;
  void    *mlx_img;
  char    f_type;
  int     x;
  int     y;
  int     custom_c;
  double  cx;
  double  cy;
  double  offset_x;
  double  offset_y;
  double  zx;
  double  zy;
  double  zoom;
  int     max_iter;
  
}  t_f;
  

 fdata.x = 0;
  fdata.y = 0;
  fdata.x_delta = 0;
  fdata.y_delta = 0;
  fdata.zoom = 0;
  fdata.max_iter = 50;
  fdata.color = 0xFCBE11;

#endifdef
