/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:18:33 by truthe            #+#    #+#             */
/*   Updated: 2022/03/26 21:20:02 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int i)
{
	if (i == 1)
	{
		write (1, "Incorrect map format\n", 21);
		exit(1);
	}
	if (i == 2)
	{
		write(1, "map error\n", 11);
		exit (1);
	}
	if (i == 3 || i == 4)
	{
		write(1, "symbols error\n", 15);
		exit (1);
	}
	if (i == 5)
	{
		write (1, "arguments error\n", 16);
		exit(1);
	}
	if (i == 6)
	{
		write (1, "wrong line length\n", 18);
		exit(1);
	}
}
