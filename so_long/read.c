/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:12:01 by truthe            #+#    #+#             */
/*   Updated: 2022/03/28 16:41:46 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char **argv)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str[0] == '\0')
			break ;
		free(str);
		i++;
	}
	free(str);
	close (fd);
	return (i);
}

void	read_map(char **argv, t_long *lon)
{
	int		fd;
	int		j;
	int		len;

	lon->height = count_line(argv);
	j = 0;
	len = 0;
	lon->map = malloc(sizeof(char *) * (lon->height + 1));
	if (!lon->map)
		exit(1);
	fd = open(argv[1], O_RDONLY);
	while (j < lon->height)
	{
		lon->map[j] = get_next_line(fd);
		if (len == 0)
			len = ft_strlen(lon->map[j]);
		if (len != ft_strlen(lon->map[j]))
			error(6);
		j++;
	}
	lon->width = ft_strlen(lon->map[0]);
	lon->map[j] = 0;
	close(fd);
}
