#include <unistd.h>
#include "ft_abs.h"

int	main(void)
{
	int	i;
	
	i = -3;
	if (ABS(i) == 3)
		write(1, "ABS(-3) == 3, ok\n", 19);
	i = 3;
	if (ABS(i) == 3)
		write(1, "ABS(3) == 3, ok\n", 17);
	i = 0;
	if (ABS(i) == 0)
		write(1, "ABS(0) == 0, ok\n", 17);
}
