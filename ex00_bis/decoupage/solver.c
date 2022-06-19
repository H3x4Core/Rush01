/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:05:20 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 18:06:50 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	safe(t_coord coord, int box_height, int n, int *map)
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

int	solve(int n, int stock_box, int *map)
{
	t_coord	coord;
	int		box_height;

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
