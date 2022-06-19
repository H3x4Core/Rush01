/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:59:06 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 20:13:41 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct s_check
{
	t_coord	coord;
	int		index;
	int		height;
	int		highest_encounter;
	int		count;
	int		not_placed;
}	t_check;


int	index_check_up(t_coord coord, int n, int *map)
{
	t_check	check;

	check.not_placed = 0;
	check.index = *get_index_cell(coord, n, 1, map);
	check.coord.x = coord.x;
	check.coord.y = n - 1;
	check.height = 0;
	check.highest_encounter = 0;
	check.count = 0;
	while (check.coord.y < n)
	{
		check.height = *get_box_cell(check.coord, n, map);
		if (check.height == 0)
			check.not_placed++;
		if (check.height > check.highest_encounter)
		{
			check.count++;
			check.highest_encounter = check.height;
		}
		if (check.count > check.index)
			return (1);
		check.coord.y++;
	}
	if (!check.not_placed && check.count != check.index)
		return (1);
	return (0);
}

int	index_check_down(t_coord coord, int n, int *map)
{
	t_check	check;

	check.not_placed = 0;
	check.index = *get_index_cell(coord, n, 1, map);
	check.coord.x = coord.x;
	check.coord.y = n - 1;
	check.height = 0;
	check.highest_encounter = 0;
	check.count = 0;
	while (check.coord.y > -1)
	{
		check.height = *get_box_cell(check.coord, n, map);
		if (check.height == 0)
			check.not_placed++;
		if (check.height > check.highest_encounter)
		{
			check.count++;
			check.highest_encounter = check.height;
		}
		if (check.count > check.index)
			return (1);
		check.coord.y--;
	}
	if (!check.not_placed && check.count != check.index)
		return(1);
	return (0);
}

int	index_check_left(t_coord coord, int n, int *map)
{
	t_check	check;

	check.not_placed = 0;
	check.index = *get_index_cell(coord, n, 2, map);
	check.coord.x = 0;
	check.coord.y = coord.y;
	check.height = 0;
	check.highest_encounter = 0;
	check.count = 0;
	while (check.coord.x < n)
	{
		check.height = *get_box_cell(check.coord, n, map);
		if (check.height == 0)
			check.not_placed++;
		if (check.height > check.highest_encounter)
		{
			check.count++;
			check.highest_encounter = check.height;
		}
		if (check.count > check.index)
			return (1);
		check.coord.x++;
	}
	if (!check.not_placed && check.count != check.index)
		return(1);
	return (0);
}

int	index_check_right(t_coord coord, int n, int *map)
{
	t_check	check;

	check.not_placed = 0;
	check.index = *get_index_cell(coord, n, 3, map);
	check.coord.x = n - 1;
	check.coord.y = coord.y;
	check.height = 0;
	check.highest_encounter = 0;
	check.count = 0;
	while (check.coord.x > -1)
	{
		check.height = *get_box_cell(check.coord, n, map);
		if (check.height == 0)
			check.not_placed++;
		if (check.height > check.highest_encounter)
		{
			check.count++;
			check.highest_encounter = check.height;
		}
		if (check.count > check.index)
			return (1);
		check.coord.x--;
	}
	if (!check.not_placed && check.count != check.index)
		return (1);
	return (0);
}

int	index_check(t_coord coord, int n, int *map)
{
	if (index_check_up(coord, n, map)
		|| index_check_down(coord, n, map)
		|| index_check_left(coord, n, map)
		|| index_check_right(coord, n, map))
		return (1);
	return (0);
}
