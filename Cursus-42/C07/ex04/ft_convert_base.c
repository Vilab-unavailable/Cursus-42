/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:29:36 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/06 13:46:52 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			else if (base[i] == '+' || base[i] == '-' || base[j] == '+'
				|| base[j] == '-')
				return (0);
			else if ((base[i] >= 9 && base[i] <= 13) || (base[j] >= 9
					&& base[j] <= 13) || base[i] == 32 || base[j] == 32)
				return (0);
			j++ ;
		}
		i++ ;
	}
	if (i >= 2)
		return (i);
	else
		return (0);
}

int	ft_atoi_base_core(char *str, char *base, int base_len)
{
	int		i;
	int		j;
	int		res;
	char	in_base;

	i = 0;
	in_base = 'y';
	res = 0;
	while (in_base == 'y')
	{
		j = 0;
		while (base[j] && base[j] != str[i])
		{
			j++ ;
			if (base[j] == '\0')
				in_base = 'n';
		}
		if (in_base == 'y')
			res = res * base_len + j;
		i++ ;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	base_len;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++ ;
	}
	base_len = ft_check_base(base);
	if (base_len >= 2)
		res = ft_atoi_base_core(&str[i], base, base_len);
	return (res * sign);
}
