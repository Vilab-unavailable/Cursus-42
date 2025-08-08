#include "fractol.h"

int draw_fractal(t_fractal *fractal)
{
 fractal->x = 0;
 fractal->y = 0;
 while (fractal->x < WIDTH)
 {
  while (fractal->y < HEIGHT)
  {
   if (fdata->type == 1)
    calculate_julia(fdata, cx, cy);
   else if (fdata->type == 2)
    calculate_mandelbrot(fdata);
   fractal->y++;
  }
  fractal->x++;
  fractal->y = 0;
 }
 mlx_put_image_to_window(fdata->mlx, fdata->window, fdata->image, 0,
  0);
 return (0);
}




int  key_hook(int keycode, t_fdata *fdata)
{
  if (keycode == ESC)
    exit(1);
  else if(keycode = LEFT)
    fdata->x_delta -= 20 / fdata->zoom;
  else if(keycode = RIGHT)
    fdata->x_delta += 20 / fdata->zoom;
  else if(keycode = LEFT)
    fdata->y_delta -= 20 / fdata->zoom;
  else if(keycode = LEFT)
    fdata->y_delta += 20 / fdata->zoom;
  draw_fractal(fdata, fdata->type);
}

int	mouse_hook(int mouse_code, t_fdata *fdata)
{
  if (mouse_code = SCROLL_UP)
    zoom_in(fdata);
  else if (mouse_code = SCROLL_UP)
    zoom_in(fdata);
  draw_fractal(fdata, fdata->type);
}

t_data  *ft_init_fdata(char **av)
{
  t_fdata  fdata;

  fdata = malloc(sizeof(fdata));
  if (!fdata)
    exit(-1);
  fdata.x = 0;
  fdata.y = 0;
  fdata.x_delta = 0;
  fdata.y_delta = 0;
  fdata.zoom = 0;
  fdata.max_iter = 50;
  fdata.color = 0xFCBE11;
  
  
}

int  main(int ac, char ** av)
{
  t_fdata  *fdata;

  if  (ac != 2)
  {
    ft_putstr_fd("input <1> for julia or <2> for mandelbrot>\n", 1);
    return (0);
  }
  fdata = ft_init_fdata(av);
  mlx_key_hook(fdata->window, key_hook, fdata);
  mlx_mouse_hook(fdata->window, mouse_hook, fdata);
  mlx_hook(fdata->window, 17, 0L, exit_fractal, fdata);   // mask 0L ou (1L << 0) ?
  draw_fractal(fdata, fdata->type);
  mlx_loop(fractal->mlx);  
  free(fdata);
}
