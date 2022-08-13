/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:23:16 by truthe            #+#    #+#             */
/*   Updated: 2022/03/28 16:53:27 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_loop(t_long *map)
{
	static int	flag;
	int			i;
	int			j;
	char		*gop;

	gop = ft_itoa(map->steps);
	if (flag < 10)
	{
		map->image[5] = mlx_xpm_file_to_image(map->mlx_ptr,
				"image/laila.xpm", &i, &j);
		ft_draw_map(map);
		flag++;
	}
	else if (flag < 30)
	{
		map->image[5] = mlx_xpm_file_to_image(map->mlx_ptr,
				"image/laila2.xpm", &i, &j);
		ft_draw_map(map);
		flag++;
	}
	else
		flag = 0;
	mlx_string_put(map->mlx_ptr, map->mlx_win, 20, 20, 0xFFFFFF, gop);
	free(gop);
	return (0);
}
