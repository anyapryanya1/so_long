/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:23:55 by truthe            #+#    #+#             */
/*   Updated: 2022/03/28 16:08:30 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_walker_keybord(int *x, int *y, int key)
{
	if (key == 0)
		*x -= 1;
	if (key == 1)
		*y += 1;
	if (key == 2)
		*x += 1;
	if (key == 13)
		*y -= 1;
}

void	ft_walk2(t_long *w, int key)
{
	int	x;
	int	y;

	if (check_c(w->map) == 0)
		w->image[3] = mlx_xpm_file_to_image(w->mlx_ptr,
				"image/hwitha.xpm", &x, &y);
	if (key == 2)
		w->image[2] = mlx_xpm_file_to_image(w->mlx_ptr,
				"image/helga2.xpm", &x, &y);
	if (key == 0)
		w->image[2] = mlx_xpm_file_to_image(w->mlx_ptr,
				"image/helga.xpm", &x, &y);
}

int	ft_walk(t_long *w, int key)
{
	int	x;
	int	y;
	int	x2;
	int	y2;

	find_player (w->map, &x, &y);
	x2 = x;
	y2 = y;
	ft_walker_keybord(&x, &y, key);
	if ((w->map[y][x] == 'E' && check_c(w->map) == 0) || w->map[y][x] == 'V')
		exit(0);
	if (w->map[y][x] == '1' || w->map[y][x] == 'E')
		return (0);
	else
	{
		w->map[y][x] = 'P';
		w->map[y2][x2] = '0';
	}
	ft_walk2(w, key);
	return (1);
}

int	key_hook(int key, t_long *w)
{
	static int	step;

	if (key == 53)
		exit (0);
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		step += ft_walk(w, key);
		w->steps = step;
		write (1, "step:", 5);
		ft_putnbr_fd(step, 1);
		write(1, "\n", 1);
	}
	return (0);
}
