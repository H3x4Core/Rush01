#include <stdlib.h>
#include <unistd.h>
#define MIN_N 4
#define MAX_N 9

#include "ft_atoi.c"	// DEBUG
#include <stdio.h>		// DEBUG

int ft_arg_count(char *str)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((!ft_isspace(str[i]) && ft_isspace(str[i + 1]))		// Check for char followed with space
			|| (!ft_isspace(str[i]) && str[i + 1] == 0)) 		// Check for word followed with end of string
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

int *get_index_cell(int x, int y, int n, int side,int *map)
{
	if (side == 0)
		return (&map[x + 1]);							//col_up
	if (side == 1)
		return (&map[(x + 1 + (n + 1) * (n + 2))]);		//col_down
	if (side == 2)
		return (&map[y * (n + 2) + n + 2]);				//row_left
	if (side == 3)
		return (&map[y * (n + 2) + 2 * (n + 2) - 1]);	//row_right
	return (0);
}

int *get_box_cell(int x, int y, int n, int *map)
{
	y *= n + 2; // place to the correct row
	y += n + 2; // offset row
	x += 1;		// offset col
	return (&map[x + y]);
}

int *get_adress(int i, int *map)
{
	return (&map[i]);
}

/*
int check(int x, int y, int n, int *map)
{
	int up;
	int down;
	int left;
	int right;
	int *index;
	
	while (i < n)
	{
		
	}
	
	return (0);
}
*/

//WARNING MALLOC
int *parser(char *str, int n, int arg)
{
	int i;
	int j;
	int k;
	int cel;
	int *map;

	i = 0;
	j = 0;
	map = malloc(sizeof(int) * (n + 2) * (n + 2));
	if (!map)
		return (0);
	while (j < arg && str[i])
	{
		k = 0;
		cel = get_pos_index_cell(j, n);
		map[cel] = ft_atoi_count(&str[i], &k);
		if (map[cel] < 1 || map[cel] > n || k != 1) // check if value in range && only 2 char have been processed
			return(0);
		i += k + 1;
		j++;
	}
	return (map);
}

void error(void)
{
	write(1, "Error\n", 6);
}

int main (int argc, char **argv)
{
	int arg;	// Count ARG
	int n;		// BOX Array SIZE
	int larray;	// FULL ARRAY SIZE
	int *map; 	// ARRAY
	
	if (argc == 1)	// DEBUG
	{
		argv[1] = "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4";
		argc++;
	}				// DEBUG
	
	
	if (argc != 2)
	{
		error();
		printf("argc count\n"); //DEBUG
		return (-1);
	}
	
	arg = ft_arg_count(argv[1]);

	if (!(arg % 4) && (4 * MIN_N) <= arg && arg <= (4 * MAX_N)) //Check if arg is multiple of 4, and it's in the correct range of 4 multiples
	{
		n = arg / 4;
		larray = n + 2;
		map = parser(argv[1], n, arg);
		if (!map)
		{
			error();
			printf("Arg parsing issue\n"); //DEBUG
			return (-1);
		}
	}
	else
	{
		error();
		printf("Arg count issue\n"); //DEBUG
		return (-1);
	}
	
	printf("n: %i\n", n); 	//DEBUG
	for (int i = 0; i < larray * larray; i++)
	{
		printf("%i", map[i]);
		if (!((i + 1) % larray))
			printf("\n");
	}						//DEBUG

	//DEBUG TEST ACCESS AND WRITE IN MAP
	printf("%i\n", *get_box_cell(1, 1, n, map));
	printf("%i\n", *get_index_cell(1, 1, n, 0, map));

	return (0);
}
