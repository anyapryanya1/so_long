/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:12:54 by truthe            #+#    #+#             */
/*   Updated: 2022/03/28 16:54:35 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_select_image(void **img, char ch)
{
	if (ch == '0')
		return (img[0]);
	if (ch == '1')
		return (img[1]);
	if (ch == 'P')
		return (img[2]);
	if (ch == 'C')
		return (img[4]);
	if (ch == 'V')
		return (img[5]);
	else
		return (img[3]);
}

void	**init_image(void *mlx_ptr)
{
	int		i;
	int		j;
	void	**img;

	img = (void **)malloc(sizeof(void *) * 6);
	img[0] = mlx_xpm_file_to_image(mlx_ptr, "image/pol.xpm", &i, &j);
	img[1] = mlx_xpm_file_to_image(mlx_ptr, "image/derevo.xpm", &i, &j);
	img[2] = mlx_xpm_file_to_image(mlx_ptr, "image/helga.xpm", &i, &j);
	img[3] = mlx_xpm_file_to_image(mlx_ptr, "image/arnold_flowers.xpm", &i, &j);
	img[4] = mlx_xpm_file_to_image(mlx_ptr, "image/heart.xpm", &i, &j);
	img[5] = mlx_xpm_file_to_image(mlx_ptr, "image/laila.xpm", &i, &j);
	return (img);
}

void	ft_draw_map(t_long *lon)
{
	int		i;
	int		y;
	int		x;
	char	*str;
	void	*pic;

	i = 0;
	y = 0;
	while (lon->map[i])
	{
		str = lon->map[i];
		x = 0;
		while (str[x])
		{
			pic = ft_select_image(lon->image, str[x]);
			mlx_put_image_to_window(lon->mlx_ptr, lon->mlx_win,
				pic, x * 130, y * 130);
			x++;
		}
		y++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_long	lon;
	int		x;
	int		y;
	int		len;

	if (argc != 2)
		error(5);
	lon.steps = 0;
	check_format(argv[1]);
	read_map(argv, &lon);
	check_symbols(lon.map);
	check_walls(&lon);
	lon.mlx_ptr = mlx_init();
	lon.mlx_win = mlx_new_window(lon.mlx_ptr,
			lon.width * 130, lon.height * 130, "so_long");
	lon.image = init_image(lon.mlx_ptr);
	ft_draw_map(&lon);
	mlx_key_hook(lon.mlx_win, key_hook, &lon);
	mlx_loop_hook(lon.mlx_ptr, &player_loop, &lon);
	mlx_loop(lon.mlx_ptr);
	return (0);
}
