#ifndef FT_H
# define FT_H
# include <stdlib.h>
# define MIN_N 4
# define MAX_N 9

int	ft_atoi(char *str);


//structure de lobjet grille
struct s_grid
{
	char	**grid_solv;
	int		**col;
	int		**row;
	int		*int_left;
	size_t	size;
}s_var_grid;

//init grille
//pour int_left Left[0]  represete 1, donc[n] represente n-1
int	init_grid(struct *grid, int n, size_t len)
{
	int	nb;

	nb = 0;
	grid->size = len;
	grid->grid_solv[n][n];
	grid->col[n][2];
	grid->row[2][n];
	grid->int_left[n];
	if (!grid || (n < 4 && n > 9))
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (1);
	}
	while (nb < n)
	{
		int_left[nb] = n;
		nb++;	
	}
	return (0);
}

//vidage objet grille
int	empty_grid(struct *arr[], size_t len)
{
	int	i;

	i = 0;
	if (!grid)
	{
		return (1);
	}
	while (i < len)
	{
		free(arr[i]);
	}
	return (0);
}
#endif
