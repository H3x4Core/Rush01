/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:57:16 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 17:58:26 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	row_check(t_coord box_coord, int box_height, int n, int *map)
{
	t_coord	check_coord;

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

int	col_check(t_coord box_coord, int box_height, int n, int *map)
{
	t_coord	check_coord;

	check_coord.x = box_coord.x;
	check_coord.y = 0;
	while (check_coord.y < n)
	{
		if (*get_box_cell(check_coord, n, map) == box_height)
			return (1);
		check_coord.y++;
	}
	return (0);
}

int	duplicate_check(t_coord box_coord, int box_height, int n, int *map)
{
	if (col_check(box_coord, box_height, n, map)
		|| row_check(box_coord, box_height, n, map))
		return (1);
	return (0);
}
