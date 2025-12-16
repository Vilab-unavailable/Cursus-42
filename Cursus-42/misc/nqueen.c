#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++ ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++ ;
	}
	return (res * sign);
}
void	print(int **grid, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (grid[i][j] == 1)
				printf("%s", "Q");
			else
				printf("%s", ".");
			printf("%s", " ");
			j++;
		}
		printf("\n");
		i++ ;
	}
}

int** makegrid(int n)
{
	int	**grid;
	int		i;
	int		j;

	i = 0;
	grid = malloc((n) * sizeof(int*));
	if (!grid)
		return(NULL);
	while (i < n)
	{
		grid[i] = malloc((n) * sizeof(int));
		if (!grid[i])
			return(NULL);
		j = 0;
		while (j < n)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return(grid);
}

int	issafe(int **grid, int r, int c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//row
	while (j < n)
	{
		if (grid[r][j] == 1 && j != c)
			return(0);
		j++;
	}
	// col
	while (i < n)
	{
		if (grid[i][c] == 1 && i != r)
			return(0);
		i++;
	}
	//diag up left
	i = r;
	j = c;
	while (i > 0 && j > 0)
	{
		i--;
		j--;
	}
	while (i < n && j < n)
	{
		if (grid[i][j] == 1 && i != r && j != c)
			return(0);
		i++;
		j++;
	}
		//diag up right
	i = r;
	j = c;
	while (i > 0 && j < n - 1)
	{
		i--;
		j++;
	}
	while (i < n && j >= 0)
	{
		if (grid[i][j] == 1 && i != r && j != c)
			return(0);
		i++;
		j--;
	}
	return(1);
}

int	solvenq(int **grid, int n, int r, int* sols)
{
	int		c;

	if (r >= n)
	{
		(*sols)++ ;
		print(grid, n);
		printf("\n");
		return(0);
	}
	c = 0;
	while (c < n)
	{
		if (issafe(grid, r, c, n))
		{
			grid[r][c] = 1;
			solvenq(grid, n, r + 1, sols);
			grid[r][c] = 0;
		}
		c++;
		
	}
	return(0);
}

void	freegrid(int **grid, int n)
{
	int	r;
	r = 0;
	while (r < n)
	{
		if (grid[r])
			free(grid[r]);
		r++ ;
	}
	free(grid);
}


int	main(int argc, char** argv)
{
	int	**grid;
	int	sols;
    int n;

	sols = 0;
	grid = NULL;
	if (argc != 2)
		return(0);
	n = ft_atoi(argv[1]);
	if (n <= 0)
		return(0);
	grid = makegrid(n);
	if (!grid)
		return(0);
	solvenq(grid, n, 0, &sols);
	printf("%d", sols);
	freegrid(grid, n);
	return(sols);
}