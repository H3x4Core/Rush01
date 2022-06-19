/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:49:23 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 17:53:14 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_arg_count(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((!ft_isspace(str[i]) && ft_isspace(str[i + 1]))
			|| (!ft_isspace(str[i]) && str[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

int	*parser(char *str, int n, int arg)
{
	int	i;
	int	j;
	int	k;
	int	cel;
	int	*map;

	i = 0;
	j = 0;
	map = malloc(sizeof(int) * (n + 2) * (n + 2));
	if (!map)
		return (0);
	while (j < arg && str[i])
	{
		k = 0;
		cel = get_pos_index_cell(j, n);
		map[cel] = ft_atoi_count(&str[i], &k);
		if (map[cel] < 1 || map[cel] > n || k != 1)
			return (0);
		i += k + 1;
		j++;
	}
	return (map);
}

int	check_forbidden_index(int n, int *map)
{
	t_coord	coord;
	int		sum;

	coord.x = 0;
	coord.y = 0;
	while (coord.x < n)
	{
		sum = *get_index_cell(coord, n, 0, map)
			+ *get_index_cell(coord, n, 1, map);
		if (sum > n + 1 || sum == 2)
			return (-1);
		coord.x++;
	}
	coord.x = 0;
	while (coord.y < n || sum == 2)
	{
		sum = *get_index_cell(coord, n, 2, map)
			+ *get_index_cell(coord, n, 3, map);
		if (sum > n + 1)
			return (-1);
		coord.y++;
	}
	return (0);
}
