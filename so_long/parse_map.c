/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:30:09 by truthe            #+#    #+#             */
/*   Updated: 2022/03/28 16:06:56 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *argv)
{
	int		c;
	int		b;
	char	*form;

	form = ".ber";
	b = 4;
	c = ft_strlen(argv);
	while (argv[c] != '.')
	{
		if (argv[c] != form[b])
			error(1);
		c--;
		b--;
	}
	return (0);
}

void	check_walls(t_long *lon)
{
	int	i;
	int	j;

	i = -1;
	while (lon->map[++i])
	{
		j = -1;
		while (lon->map[i][++j])
		{
			if (i == 0 || i == lon->height - 1)
			{
				if (lon->map[i][j] != '1')
					error(2);
			}
			else
			{
				if (lon->map[i][0] != '1' || lon->map[i][lon->width - 1] != '1')
					error(2);
			}
		}
	}
}

void	check_symbol2(char **map)
{
	int		x;
	int		y;
	t_long	w;

	y = 0;
	w.c = 0;
	w.e = 0;
	w.p = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				w.e += 1;
			if (map[y][x] == 'C')
				w.c += 1;
			if (map[y][x] == 'P')
				w.p += 1;
			x++;
		}
		y++;
	}
	if (w.p == 0 || w.c == 0 || w.e == 0)
		error(3);
}

void	check_symbols(char **map)
{
	int	x;
	int	y;

	y = 0;
	check_symbol2(map);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'E'
			&& map[y][x] != 'C'
			&& map[y][x] != 'P' && map[y][x] != '\n' && map[y][x] != 'V')
				error(4);
			x++;
		}
		y++;
	}
}
