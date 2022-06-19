/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:13:51 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/19 18:16:47 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int	arg;
	int	n;
	int	*map;

	if (argc != 2)
		return (error());
	arg = ft_arg_count(argv[1]);
	if (!(arg % 4) && (4 * MIN_N) <= arg && arg <= (4 * MAX_N))
	{
		n = arg / 4;
		map = parser(argv[1], n, arg);
		if (!map || check_forbidden_index(n, map))
			return (error());
	}
	else
		return (error());
	if (solve(n, (n * n) - 1, map))
	{
		free(map);
		return (0);
	}
	free(map);
	return (error());
}
