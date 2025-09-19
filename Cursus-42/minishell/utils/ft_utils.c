#include "../include/minishell.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(little);
	if (len2 == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && (big[i + j] == little[j])
			&& j + i < len)
		{
			j++ ;
			if (j == len2)
				return ((char *)&big[i]);
		}
		i++ ;
	}
	return (NULL);
}
