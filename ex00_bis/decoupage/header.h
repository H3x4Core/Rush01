#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>
# define MIN_N 4
# define MAX_N 9

typedef struct s_coordinate
{
	int x;
	int y;
}	t_coord;

int ft_arg_count(char *str);
/*
Count argument

Return: int of nbr of words in argument
*/

int get_pos_index_cell(int pos, int n);
/*
Get correct cell placement

Return: Return the map[cell] for index 
*/

int *get_index_cell(t_coord coord, int n, int side, int *map);
/*
Get index address

Return: pointer on index
*/

int *get_box_cell(t_coord coord, int n, int *map);
/*
Get box address

Unit test : ok

Return: pointer on box
*/

int row_check(t_coord box_coord, int box_height, int n, int *map);
/*
Check row for duplicate

Return:
1 - FAIL
0 - SUCCESS
*/

int col_check(t_coord box_coord, int box_height, int n, int *map);
/*
Check col for duplicate

Return:
1 - FAIL
0 - SUCCESS
*/

int duplicate_check(t_coord box_coord, int box_height, int n, int *map);
/*
Call for duplicate check
Want:
1 - FAIL
0 - SUCCESS

Return:
1 - FAIL
0 - SUCCESS
*/

int index_check_up(t_coord coord, int n, int *map);
/*
Count/check shown tower from up index

Return:
1 - FAIL
0 - SUCCESS
*/

int index_check_down(t_coord coord, int n, int *map);
/*
Count/check shown tower from down index

Return:
1 - FAIL
0 - SUCCESS
*/

int index_check_left(t_coord coord, int n, int *map);
/*
Count/check shown tower from left index

Return:
1 - FAIL
0 - SUCCESS
*/

int index_check_right(t_coord coord, int n, int *map);
/*
Count/check shown tower from right index

Return:
1 - FAIL
0 - SUCCESS
*/

int index_check(t_coord coord, int n, int *map);
/*
Call for index check

Want:
1 - FAIL
0 - SUCCESS

Return:
1 - FAIL
0 - SUCCESS
*/

int safe(t_coord coord, int box_height, int n, int *map);
/*
Call for duplicate
Put box
Call index check
Rollback if needed

Want:
1 - FAIL
0 - SUCCESS

Return:
1 - FAIL
0 - SUCCESS
*/

int solve(int n, int stock_box, int *map);
/*
Recursive backtracking

Want:
1 - FAIL
0 - SUCCESS

Return:
*/

int *parser(char *str, int n, int arg);
/*
Parse arguments

Return:
*/

void error(void);
/*
Error message

Return:
*/


#endif