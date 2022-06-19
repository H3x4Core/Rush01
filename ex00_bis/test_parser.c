#include <stdlib.h>
#include <unistd.h>

#define MIN_N 4
#define MAX_N 9

#include "ft_atoi.c"	//DEBUG
#include <stdio.h>		//DEBUG

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

int get_index_cell(int x, int y, int n)
{
	int array[4];
	array[0] 	//col_up
	array[1]	//col_down
	array[2]	//row_left
	array[3]	//row_right
	
	return ();
}

int get_box_cell(int x, int y, int n)
{
	y *= n + 2; // place to the correct row
	y += n + 2; // offset row
	x += 1;		// offset col
	return (x + y);
}


int main (void)
{
	int x = 1;
	int y = 4;
	int n = 5;

	printf("%i", get_box_cell(x, y, n));
	return (0);
}
