/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:54:31 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 17:56:25 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_pos_index_cell(int pos, int n)
{
	int	larray;

	pos += 1;
	larray = n + 2;
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

int	*get_index_cell(t_coord coord, int n, int side, int *map)
{
	if (side == 0)
		return (&map[coord.x + 1]);
	if (side == 1)
		return (&map[(coord.x + 1 + (n + 1) * (n + 2))]);
	if (side == 2)
		return (&map[coord.y * (n + 2) + n + 2]);
	if (side == 3)
		return (&map[coord.y * (n + 2) + 2 * (n + 2) - 1]);
	return (0);
}

int	*get_box_cell(t_coord coord, int n, int *map)
{
	coord.y *= n + 2;
	coord.y += n + 2;
	coord.x += 1;
	return (&map[coord.x + coord.y]);
}
