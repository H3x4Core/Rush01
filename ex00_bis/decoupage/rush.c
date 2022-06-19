/* HEADER START */

#include <stdlib.h>
#include <unistd.h>
#define MIN_N 4
#define MAX_N 9

typedef struct s_coordinate
{
	int x;
	int y;
}	t_coord;

/* HEADER STOP */

/* DEBUG START */
#include "ft_atoi.c"
#include <stdio.h>

void debug_print(int n, int *map, int data, char *str)
{
	printf("%s: %i\n", str, data);
	for (int i = 0; i < (n + 2) * (n + 2); i++)
	{
		printf("%i", map[i]);
		if (!((i + 1) % (n + 2)))
			printf("\n");
	}
}
/* DEBUG STOP */

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

int *get_index_cell(t_coord coord, int n, int side, int *map)
{
	if (side == 0)
		return (&map[coord.x + 1]);								//col_up
	if (side == 1)
		return (&map[(coord.x + 1 + (n + 1) * (n + 2))]);		//col_down
	if (side == 2)
		return (&map[coord.y * (n + 2) + n + 2]);				//row_left
	if (side == 3)
		return (&map[coord.y * (n + 2) + 2 * (n + 2) - 1]);		//row_right
	return (0);
}

int *get_box_cell(t_coord coord, int n, int *map)
{
	coord.y *= n + 2; 	// place to the correct row
	coord.y += n + 2; 	// offset row
	coord.x += 1;		// offset col
	return (&map[coord.x + coord.y]);
}

int row_check(t_coord box_coord, int box_height, int n, int *map)
{
	t_coord check_coord;
	
	check_coord.x = 0;
	check_coord.y = box_coord.y;
	while (check_coord.x < n)
	{
		if (*get_box_cell(check_coord, n, map) == box_height)
			return (1);
		check_coord.x++;
	}
	return (0);
}

int col_check(t_coord box_coord, int box_height, int n, int *map)
{
	t_coord check_coord;

	check_coord.x = box_coord.x;
	check_coord.y = 0;
	while (check_coord.y < n)
	{
		if (*get_box_cell(check_coord, n, map) == box_height)	// col
			return (1);
		check_coord.y++;
	}
	return (0);
}

int duplicate_check(t_coord box_coord, int box_height, int n, int *map)
{
	if (col_check(box_coord, box_height, n, map)
		|| row_check(box_coord, box_height, n, map))
		return (1);
	return (0);
}

int index_check_up(t_coord coord, int n, int *map)
{
	int index;
	t_coord check_coord;
	int height;
	int prev_box_height;
	int count;

	index = *get_index_cell(coord, n, 0, map);
	check_coord.x = coord.x;
	check_coord.y = 0;
	height = 0;
	prev_box_height = 0;
	count = 0;
	while (check_coord.y < n)
	{
		height = *get_box_cell(check_coord, n, map);
		if ( height > prev_box_height)
			count++;
		if (count > index)
			return (1);
		check_coord.y++;		
	}
	return (0);
}

int index_check_down(t_coord coord, int n, int *map)
{
	int index;
	t_coord check_coord;
	int height;
	int prev_box_height;
	int count;

	index = *get_index_cell(coord, n, 1, map);
	check_coord.x = coord.x;
	check_coord.y = n - 1;
	height = 0;
	prev_box_height = 0;
	count = 0;
	while (check_coord.y > -1)
	{
		height = *get_box_cell(check_coord, n, map);
		if ( height > prev_box_height)
			count++;
		if (count > index)
			return (1);
		check_coord.y--;		
	}
	return (0);
}

int index_check_left(t_coord coord, int n, int *map)
{
	int index;
	t_coord check_coord;
	int height;
	int prev_box_height;
	int count;

	index = *get_index_cell(coord, n, 2, map);
	check_coord.x = 0;
	check_coord.y = coord.y;
	height = 0;
	prev_box_height = 0;
	count = 0;
	while (check_coord.y < n)
	{
		height = *get_box_cell(check_coord, n, map);
		if ( height > prev_box_height)
			count++;
		if (count > index)
			return (1);
		check_coord.y--;		
	}
	return (0);
}

int index_check_right(t_coord coord, int n, int *map)
{
	int index;
	t_coord check_coord;
	int height;
	int prev_box_height;
	int count;

	index = *get_index_cell(coord, n, 3, map);
	check_coord.x = n - 1;
	check_coord.y = coord.y;
	height = 0;
	prev_box_height = 0;
	count = 0;
	while (check_coord.y > -1)
	{
		height = *get_box_cell(check_coord, n, map);
		if ( height > prev_box_height)
			count++;
		if (count > index)
			return (1);
		check_coord.y--;		
	}
	return (0);
}

int index_check(t_coord coord, int n, int *map)
{
	if (index_check_up(coord, n, map)
		|| index_check_down(coord, n, map)
		|| index_check_right(coord, n, map)
		|| index_check_right(coord, n, map))
		return (1);
	
	return (0);
}

int safe(t_coord coord, int box_height, int n, int *map)
{
	if (duplicate_check(coord, box_height, n, map))
		return (1);
	*get_box_cell(coord, n, map) = box_height;
	if (index_check(coord, n, map))
	{
		*get_box_cell(coord, n, map) = 0;
		return (1);
	}
	return (0);	
}

// Backtracking
int solve(int n, int stock_box, int *map)
{
	t_coord coord;
	int box_height;
	
	coord.x = 0;
	while (coord.x < n)
	{
		box_height = 1 + stock_box / n;
		coord.y = stock_box % n;
		if (*get_box_cell(coord, n, map) == 0)
		{
			if (!safe(coord, box_height, n, map))
			{
				if (stock_box == 0)
					return (1);
				if (solve(n, stock_box - 1, map))
					return (1);
				*get_box_cell(coord, n, map) = 0; 
			}
		}
		coord.x++;
	}
	return (0);
}

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
	int *map; 	// MAP
	
	if (argc == 1)	// DEBUG
	{
		argv[1] = "2 3 1 3 3 2 2 1 2 1 2 4 2 4 2 1";
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

	debug_print(n, map, 0, " -- original --");
	solve(n, (n * n - 1), map);
	debug_print(n, map, 0, " -- solved --");


	//DEBUG TEST ACCESS AND WRITE IN MAP
	t_coord coord;
	coord.x = 1;
	coord.y = 1;
	printf("%i\n", *get_box_cell(coord, n, map));
	printf("%i\n", *get_index_cell(coord, n, 0, map));
	//DEBUG TEST END

	free(map);
	return (0);
}
