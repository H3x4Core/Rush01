#include <stdlib.h>
#include <unistd.h>

#include "ft_atoi.c"
#include <stdio.h>

int ft_arg_count(char *str)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((!ft_isspace(str[i]) && ft_isspace(str[i + 1]))		//Check for char followed with space
			|| (!ft_isspace(str[i]) && str[i + 1] == 0)) 		//check for word followed with end of string
			words++;
		i++;
	}
	return (words);
}

int get_pos_index_cell(int pos, int n)
{
	pos += 1;
	int larray = n + 2;
	if (pos <= n)
		return (pos);
	if (n < pos && pos <= (2 * n))
		return ((pos - n) + (larray - 1) * larray);
	if ((2 * n) < pos && pos <= (3 * n))
		return ((pos - 2 * n) * larray);
	if (3 * n < pos && pos <= n * 4)
		return ((pos - 3 * n) * larray + (larray - 1));
	return (0);
}

int *parser(char *str, int n, int arg, int *index)
{
	int i;
	int j;
	int cel;

	i = 0;
	j = 0;
	while (j < arg && str[i])
	{
		cel = get_pos_index_cell(j, n);
		index[cel] = ft_atoi(&str[i]);
		if (index[cel] < 1 || index[cel] > n)
			return(0);
		i += 2;
		j++;
	}
	return (index);
}

void error(void)
{
	write(1, "Error\n", 6);
}

int main (void)
{
	char *argv = "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4";
	int arg;
	int n;
	int larray;
	int *index;
	int *map = 0;
	//int **pindex = &index;

	arg = ft_arg_count(argv);
	n = arg / 4;
	larray = n + 2;
	
	index = malloc(sizeof(int) * larray);
	
	if (!index)
	{
		printf("Malloc Error\n");
		return (-1);
	}

	map = parser(argv, n, arg, index);
	
	for (int i = 0; i < larray * larray; i++)
	{
		printf("%i", map[i]);
		if (!((i + 1) % larray))
			printf("\n");
	}

	//int **tab = malloc((n + 2) * (n + 2));

}