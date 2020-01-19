#include <unistd.h>

int isValid(int **grid, int i, int j, int e);

void	ft_print(int **grid)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &grid[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}

int	findFill(int **grid, int *vector)
{
	int k; int t = 0;

	k = 0;
	while (k < 4)
	{
		while (t < 4)
		{
		    if (grid[k][t] == 0)
		    {
			vector[0] = k; vector[1] = t;
                        return 1;
		    }
		    t += 1;
		}
		k += 1;
		
	}
	return (0);
}

int	ft_solve(int **grid, int i, int j)
{
        int vector[2];
	i = findFill(grid,vector);
        if (i == 0)
	{
	    ft_print(grid);
	}
        i = vector[0]; j = vector[1];
        int e = 1;
	while (e < 5)
	{
		if (isValid(grid, i, j, e))
		{
		    grid[i][j] = e;
		    if (ft_solve(grid, i, j))
		    {
		        return 0;
		    }
                    grid[i][j] = 0;
		}
		
		e += 1;
	}
	return (1);
}

