#include "check_duplicate.c"
#include "check_index.c"
#include "coordinate.c"
#include "parser.c"
#include "show.c"
#include "solver.c"
#include "utils.c"

/* DEBUG START */
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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

int *get_box_cell(t_coord coord, int n, int *map);

void debug_print_coord(int n, int *map, t_coord coord, char *str)
{
	printf("%s: (%i,%i)\n", str, coord.x, coord.y);
	for (int i = 0; i < (n + 2) * (n + 2); i++)
	{
		if (&map[i] == get_box_cell(coord, n, map))
			printf(ANSI_COLOR_RED "%i" ANSI_COLOR_RESET, map[i]);
		else
			printf("%i", map[i]);
		if (!((i + 1) % (n + 2)))
			printf("\n");
	}
}
/* DEBUG STOP */


#if 1
int main (int argc, char **argv)
{
	int arg;	// Count ARG
	int n;		// BOX Array SIZE
	int *map; 	// MAP
	
	if (argc == 1)	// DEBUG
	{
		argv[1] = "1 2 2 2 4 2 1 3 1 2 2 3 3 1 2 2";
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

	//debug_print(n, map, 0, " -- original --");
	if (solve(n, (n * n - 1), map))
	{
		write(1, "solved !!\n", 10);
		print_grid(n, map);
	}
	else
	{
		write(1, "Fail!!!!\n", 9);
		print_grid(n, map);
	}
	
	debug_print(n, map, 0, "FINAL");

	free(map);
	return (0);
}

#endif

#if 0
int main (void)
{
	int n = 5;
	int map[49] = {0, 3, 1, 2, 4, 2, 0,
					2, 0, 0, 0, 0, 0, 3,
					2, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 5,
					3, 0, 0, 5, 0, 0, 3,
					3, 0, 0, 0, 0, 0, 2,
					0, 2, 3, 2, 1, 2, 0};
	
	debug_print(n, map, 0, "Original");

	solve(n, 24, map);

	debug_print(n, map, 1, "Solved");

#if 0
	t_coord coord;
	for (coord.x = 0; coord.x < n; coord.x++)
	{
		for (coord.y = 0; coord.y < n; coord.y++)
		{
			*get_box_cell(coord, n, map) = 9;
			debug_print_coord(n, map, coord, "Coo: ");
		}
		
	}
#endif

}

#endif