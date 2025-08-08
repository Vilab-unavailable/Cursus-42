#include "fractol.h"






int  key_hook(int keycode, t_fdata fdata)
{
  if (keycode == ESC)
    exit(1);
  else if(keycode = L_ARROW)
}

int  main(int ac, char ** av)
{
  t_fdata  fdata;

  if  (ac != 2)
  {
    ft_putstr_fd("input : ./fractol <1 for julia / 2 for mandelbrot>\n", 1);
    return (0);
  }
  fdata = ft_init_fdata(av);
  ft_init_mlx(fdata);
  mlx_key_hook(fdata->win_list, key_hook, fdata);
  
    
}
