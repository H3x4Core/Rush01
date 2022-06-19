/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:20:25 by btinturi          #+#    #+#             */
/*   Updated: 2022/06/19 19:06:21 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_grid(t_coord coord, int n, int *map)
{
	char	cell;

	while (coord.x < n)
	{
		while (coord.y < n)
		{
			cell = get_box_cell(coord, n, *map) + 48;
			write(1, &cell, 1);
			if (coord.y == n - 1)
				write(1, "\n", 1);
			else
				write(1, ' ', 1);
			coord.y++;
		}
		coord.x++;
	}
	return (0);
}

int	error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}
