#include "fractol.h"
void calc_julia

int draw_fractal(t_fdata *fdata)
{
 fdata->x = 0;
 while (fdata->x < WIDTH)
 {
  fdata->y = 0;
  while (fdata->y < HEIGHT)
  {
   if (fdata->f_type == 'j')
   {
    if (f_data->custom_c == 0)
    {
     f_data->cx = 0.285;
     f_data->cy = 0.01;
    }
    calc_julia(fdata, cx, cy);
   }
   else if (fdata->f_type == 'm')
    calc_mandelbrot(fdata);
   fractal->y++;
  }
  fractal->x++;
 }
 mlx_put_image_to_window(fdata->mlx, fdata->mlx_win, fdata->image, 0,
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
  if (!(av[1] && av[1][0] && !av[1][1] && (av[1][0] == 'j' || av [1][0] == 'm')))
       exit(free(fdata), 1);
  fdata.f_type = av[1][0];
  fdata.x = 0;
  fdata.y = 0;
  f_data.custom_c = 0;
  f_data.cx = 0.285;
  f_data.cy = 0.01;
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
    ft_putstr_fd("input <j> for julia or <m> for mandelbrot>\n", 1);
    return (0);
  }
  fdata = ft_init_fdata(av);
  mlx_key_hook(fdata->mlx_win, key_hook, fdata);
  mlx_mouse_hook(fdata->mlx_win, mouse_hook, fdata);
  mlx_hook(fdata->mlx_win, 17, 0L, exit_prog, fdata);   // mask 0L ou (1L << 0) ?
  draw_fractal(fdata, fdata->type);
  mlx_loop(fractal->mlx);  
  free(fdata);
}
