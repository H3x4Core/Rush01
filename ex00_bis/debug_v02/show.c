/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:20:25 by btinturi          #+#    #+#             */
/*   Updated: 2022/06/19 20:36:10 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_grid(int n, int *map)
{
	t_coord	coord;
	char	cell;

	coord.x = 0;
	coord.y = 0;
	while (coord.y < n)
	{
		coord.x = 0;
		while (coord.x < n)
		{
			cell = *get_box_cell(coord, n, map) + 48;
			write(1, &cell, 1);
			if (coord.x == n - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			coord.x++;
		}
		coord.y++;
	}
	return (0);
}

int	error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}
