#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_solve(int **grid, int i, int j);
void	ft_print(int **grid);

static int colup[4];
static int coldown[4];
static int rowleft[4];
static int rowright[4];

int longdp(*temp)
{
    int LISi[4];
    LISi[0] = 1;
    int i = 0;
    int j = 0;
    while (i < 4)
	{
            k = 0;
            while (j < i)
                {
                    // 必ず,A[i]を使う場合のLISを考える.
		    if (temp[j] < temp[i] && LISi[j] > LISi[k])
			{
			    k = j;
			}
                LISi[i] = LISi[k] + 1;
                
 		}
	}
    int t = 0;
    int max = LISi[0];
    while (t < 4)
	{
	    if (max < LISi[t])
		{
		    max = LISi[t];
		}
	}
    return max;
}

int count(int i, int j, int flag, int **grid)
{
    int temp[4];
    int t = 0;
    int len;
    if (flag == 0)
    {
        while (t < 4)
	{
	    temp[t] = grid[t][j];
            t++;
	}
    } else if (flag == 1) {
        while (t < 4)
	{
	    temp[t] = grid[3-t][j];
            t++;
	}
    } else if (flag == 2) {
        while (t < 4)
	{
	    temp[t] = grid[i][t];
            t++;
	}
    } else if (flag == 3) {
        while (t < 4)
	{
	    temp[t] = grid[i][3-t];
            t++;
	}
    }
    len = longdp(temp);
    return len;

}

int isValid(int **grid, int i, int j, int e)
{
        grid[i][j] = e;
        if (colup[j] == count(i, j, 0, grid))
	{
	    if (coldown[j] == count(i, j, 1, grid))
	    {
                if (rowleft[i] == count(i, j, 2, grid))
                {
		    if (rowright[i] == count(i,j, 3, grid))
		    {
			return 0;
		    }
		}
            }
	}
	grid[i][j] = 0;
        return 1; /*成功しないならreturn 1.*/
}

int	main(int argc, char **argv)
{
        int i = 0;
        int j = 0;

        int **grid;
        grid = (int **)malloc(sizeof(int *) * 4);
        int p = 0;
	while (p < 4)
	{
		grid[p] = (int *)malloc(sizeof(int) * 4);
		p += 1;
	}
   
	if (argc == 16)
	{
		while (i < 4)
		{
		    while (j < 4)
			{
			    if (i == 0) {
				colup[j] = argv[i*4+j];			       
			    } else if (i == 1) {
			        coldown[j] = argv[i*4+j];
       			    } else if (i == 2) {
	                        rowleft[j] = argv[i*4+j];
			    } else if (i == 3) {
			        rowright[j] = argv[i*4+j];
			    } 
			    j++;
			    
			}
		    i++;
		}
		if (ft_solve(grid, 0, 0) == 1)
		    write(1, "Error\n", 6);
	}
	return (0);
}
