#include "fractol.h"
void calc_julia(t_f *f)
{
 int    i;
 double temp_zx;

 f->zx = (f->x / f->zoom) + f->offset_x;
 f->zy = (f->y / f->zoom) + f->offset_y;
 i = 0;
 while ( i < f->max_iter || (f->zx * f->zx) + (f->zy * f->zy) >= DOUBLE_MAX)
 {
  temp_zx = f->zx;
  f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
  f->zy = 2 * f->zy * temp_zx + f->cy;
  i++ ;
 }
 if (i == f->max_iter)
  color_pixel(f, 0x000000);
 else
  color_pixel(f, i); 
}

void calc_mandelbrot(tf *f)
{
  int    i;
 double temp_zx;

 f->zx = 0.0;
 f->zy = 0.0;
 f->cx = (f->x / f->zoom) + f->offset_x;
 f->cy = (f->y / f->zoom) + f->offset_y;
 i = 0;
 while ( i < f->max_iter || (f->zx * f->zx) + (f->zy * f->zy) >= DOUBLE_MAX)
 {
  temp_zx = f->zx;
  f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
  f->zy = 2 * f->zy * temp_zx + f->cy;
  i++ ;
 }
 if (i == f->max_iter)
  color_pixel(f, 0x000000);
 else
  color_pixel(f, i); 
}

int draw_fractal(t_f *f)
{
 f->x = 0;
 while (f->x < WIDTH)
 {
  fdata->y = 0;
  while (f->y < HEIGHT)
  {
   if (f->f_type == 'j')
   {
    if (f->custom_c == 0)
    {
     f->cx = 0.285;
     f->cy = 0.01;
    }
    calc_julia(f, cx, cy);
   }
   else if (f->f_type == 'm')
    calc_mandelbrot(f);
   fractal->y++;
  }
  fractal->x++;
 }
 mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img, 0,
  0);
 return (0);
}




int  key_hook(int keycode, t_fdata *fdata)
{
  if (keycode == ESC)
    exit(1);
  else if(keycode = LEFT)
    f->offset_x -= 20 / fdata->zoom;
  else if(keycode = RIGHT)
    f->offset_x += 20 / fdata->zoom;
  else if(keycode = LEFT)
    f->offset_y -= 20 / fdata->zoom;
  else if(keycode = LEFT)
    f->offset_y += 20 / fdata->zoom;
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

t_f  *ft_init_fdata(char **av)
{
  t_fdata  fdata;

  f = malloc(sizeof(t_f));
  if (!f)
    exit(-1);
  if (!(av[1] && av[1][0] && !av[1][1] && (av[1][0] == 'j' || av [1][0] == 'm')))
       exit(free(f), 1);
  f.f_type = av[1][0];
  f.x = 0;
  f.y = 0;
  f.custom_c = 0;
  f.cx = 0.285;
  f.cy = 0.01;
  f.offset_x = 0;
  f.offset_y = 0;
  f.zoom = 0;
  f.max_iter = 50;
  f.color = 0xFCBE11;
  
  
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
