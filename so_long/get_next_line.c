/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:21:58 by truthe            #+#    #+#             */
/*   Updated: 2022/03/26 21:22:54 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (0);
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*get_next_line(int fd)
{
	int		byte;
	char	*str;
	char	buf[2];

	byte = 1;
	str = malloc(1);
	if (!str)
		exit(0);
	str[0] = '\0';
	buf[1] = '\0';
	while (byte > 0)
	{
		byte = read(fd, &buf, 1);
		if (byte == -1)
			return (NULL);
		if (buf[0] == '\n' || byte == 0)
			break ;
		str = ft_strjoin(str, buf);
	}
	return (str);
}
