/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:22:56 by truthe            #+#    #+#             */
/*   Updated: 2022/03/28 16:25:48 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h> 
# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	char	**map;
	int		width;
	int		height;
	void	*mlx_win;
	void	*mlx_ptr;
	void	**image;
	int		steps;
	int		c;
	int		e;
	int		p;
}			t_long;

void	read_map(char **argv, t_long *lon);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_draw_map(t_long *lon);
void	ft_putnbr_fd(int n, int fd);
int		key_hook(int key, t_long *w);
void	check_walls(t_long *lon);
int		animation_render(t_long *w);
int		check_c(char **map);
void	find_player(char **map, int *x, int *y);

//error
void	check_symbols(char **map);
void	error(int i);
void	check_symbol2(char **map);
int		check_format(char *argv);

//bonus
int		player_loop(t_long *map);
char	*ft_itoa(int n);

#endif