/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:59:06 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 18:04:41 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	index_check_up(t_coord coord, int n, int *map)
{
	t_coord	check_coord;
	int		index;
	int		height;
	int		highest_encounter;
	int		count;

	index = *get_index_cell(coord, n, 0, map);
	check_coord.x = coord.x;
	check_coord.y = 0;
	height = 0;
	highest_encounter = 0;
	count = 0;
	while (check_coord.y < n)
	{
		height = *get_box_cell(check_coord, n, map);
		if (height > highest_encounter)
		{
			count++;
			highest_encounter = height;
		}
		if (count > index)
			return (1);
		check_coord.y++;
	}
	return (0);
}

int	index_check_down(t_coord coord, int n, int *map)
{
	t_coord	check_coord;
	int		index;
	int		height;
	int		highest_encounter;
	int		count;

	index = *get_index_cell(coord, n, 1, map);
	check_coord.x = coord.x;
	check_coord.y = n - 1;
	height = 0;
	highest_encounter = 0;
	count = 0;
	while (check_coord.y > -1)
	{
		height = *get_box_cell(check_coord, n, map);
		if (height > highest_encounter)
		{
			count++;
			highest_encounter = height;
		}
		if (count > index)
			return (1);
		check_coord.y--;
	}
	return (0);
}

int	index_check_left(t_coord coord, int n, int *map)
{
	t_coord	check_coord;
	int		index;
	int		height;
	int		highest_encounter;
	int		count;

	index = *get_index_cell(coord, n, 2, map);
	check_coord.x = 0;
	check_coord.y = coord.y;
	height = 0;
	highest_encounter = 0;
	count = 0;
	while (check_coord.x < n)
	{
		height = *get_box_cell(check_coord, n, map);
		if (height > highest_encounter)
		{
			count++;
			highest_encounter = height;
		}
		if (count > index)
			return (1);
		check_coord.x++;
	}
	return (0);
}

int	index_check_right(t_coord coord, int n, int *map)
{
	t_coord	check_coord;
	int		index;
	int		height;
	int		highest_encounter;
	int		count;

	index = *get_index_cell(coord, n, 3, map);
	check_coord.x = n - 1;
	check_coord.y = coord.y;
	height = 0;
	highest_encounter = 0;
	count = 0;
	while (check_coord.x > -1)
	{
		height = *get_box_cell(check_coord, n, map);
		if (height > highest_encounter)
		{
			count++;
			highest_encounter = height;
		}
		if (count > index)
			return (1);
		check_coord.x--;
	}
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
