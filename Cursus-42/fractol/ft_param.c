/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:19:12 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:19:15 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_is_numeric(char *v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		if (v[i] < '0' || v[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_convert_color(t_f *f, char *str)
{
	int	i;

	if (ft_strlen(str) != 8 || !ft_strnstr(str, "0x", 2))
		return (0);
	i = 2;
	while (i < 8)
	{
		str[i] = ft_tolower(str[i]);
		if ((str[i] < '0' || str [i] > '9') && (str[i] < 'a' || str[i] > 'f'))
			return (0);
		i++ ;
	}
	f->color_d = ft_atoi_base(&str[2], "0123456789abcdef");
	if (f->color_d < 1 || f->color_d > 0xFFFFFF)
		return (0);
	return (1);
}

void	ft_param_julia(int ac, char **av, t_f *f)
{
	if (f->f_type == 'j' && ac >= 4)
	{
		if (!(ft_is_double(av[2]) && ft_is_double(av[3])))
		{
			ft_input_msg(1);
			exit_clean(f);
		}
		f->cx = ft_atof(av[2]);
		f->cy = ft_atof(av[3]);
		if (f->cx <= -2.0 || f->cx >= 2.0
			|| f->cy <= -2.0 || f->cx >= 2.0)
		{
			ft_input_msg(1);
			exit_clean(f);
		}
	}
}

void	ft_param_render(int ac, char **av, t_f *f)
{
	int			j_off;
	long long	temp;

	j_off = 0;
	if (f->f_type == 'j')
		j_off = 2;
	else if (ac > 4)
	{
		ft_input_msg(1);
		exit_clean(f);
	}
	if (ac - j_off == 4 && av[2 + j_off] && av[2 + j_off][0] &&
		av[3 + j_off] && av[2 + j_off][0])
	{
		temp = ft_llong_atoi(av[2 + j_off]);
		if (!ft_is_numeric(av[2 + j_off]) || !(temp > 0 && temp <= 1000)
			|| !ft_convert_color(f, av[3 + j_off]))
		{
			ft_input_msg(1);
			exit_clean(f);
		}
		f->max_iter = temp;
	}
}
