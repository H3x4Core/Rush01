/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <matwinte@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:07:10 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/14 01:54:14 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}

int	ft_char_is_sign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

int	ft_isspace(char c)
{
	if ((8 < c && c < 14) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	while (ft_char_is_sign(str[i]))
			sign *= ft_char_is_sign(str[i++]);
	while (ft_char_is_numeric(str[i]))
	{
		nbr *= 10;
		nbr += (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
