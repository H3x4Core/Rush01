/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:37:02 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 21:06:24 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# define MIN_N 4
# define MAX_N 9

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_check
{
	t_coord	coord;
	int		index;
	int		height;
	int		highest_encounter;
	int		count;
	int		not_placed;
}	t_check;

int	ft_char_is_numeric(char c);
int	ft_char_is_sign(char c);
int	ft_isspace(char c);
int	ft_atoi_count(char *str, int *k);
int	ft_arg_count(char *str);
int	*parser(char *str, int n, int arg);
int	check_forbidden_index(int n, int *map);
int	get_pos_index_cell(int pos, int n);
int	*get_index_cell(t_coord coord, int n, int side, int *map);
int	*get_box_cell(t_coord coord, int n, int *map);
int	row_check(t_coord box_coord, int box_height, int n, int *map);
int	col_check(t_coord box_coord, int box_height, int n, int *map);
int	duplicate_check(t_coord box_coord, int box_height, int n, int *map);
int	index_check_up(t_coord coord, int n, int *map);
int	index_check_down(t_coord coord, int n, int *map);
int	index_check_left(t_coord coord, int n, int *map);
int	index_check_right(t_coord coord, int n, int *map);
int	index_check(t_coord coord, int n, int *map);
int	safe(t_coord coord, int box_height, int n, int *map);
int	solve(int n, int stock_box, int *map);
int	print_grid(int n, int *map);
int	error(void);

#endif