#include "ft_point.h"
void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else
	{
		c = '0' + (nb % 10);
		nb = nb / 10;
		if (nb != 0)
			ft_putnbr(nb);
		write(1, &c, 1);
	}
}

int 	main(void)
{
	t_point point;
	set_point(&point);
	ft_putnbr(point.x);
	ft_putnbr(point.y);
	return (0);
}
