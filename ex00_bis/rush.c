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

//WARNING MALLOC
int *get_index_cell(int x, int y, int n)
{
	int *array;
	array = malloc(sizeof(int) * 4);
	array[0] = 	x + 1;							//col_up
	array[1] =	x + 1 + (n + 1) * (n + 2);		//col_down
	array[2] =	y * (n + 2) + n + 2;			//row_left
	array[3] =	y * (n + 2) + 2 * (n + 2) - 1;	//row_right
	
	return (array);
}

int get_box_cell(int x, int y, int n)
{
	y *= n + 2; // place to the correct row
	y += n + 2; // offset row
	x += 1;		// offset col
	return (x + y);
}


int *parser(char *str, int n, int arg)
{
	int i;
	int j;
	int k;
	int cel;
	int *index;

	i = 0;
	j = 0;
	index = malloc(sizeof(int) * (n + 2) * (n + 2));
	if (!index)
		return (0);
	while (j < arg && str[i])
	{
		k = 0;
		cel = get_pos_index_cell(j, n);
		index[cel] = ft_atoi_count(&str[i], &k);
		if (index[cel] < 1 || index[cel] > n || k != 1) // check if value in range && only 2 char have been processed
			return(0);
		i += k + 1;
		j++;
	}
	return (index);
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
	int *index; // ARRAY
	
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
		index = parser(argv[1], n, arg);
		if (!index)
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
		printf("%i", index[i]);
		if (!((i + 1) % larray))
			printf("\n");
	}						//DEBUG
	return (0);
}