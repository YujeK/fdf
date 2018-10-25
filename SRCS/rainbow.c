/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:47:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/25 13:20:55 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		rbw(t_env *env, int z)
{
	int			color;
	int			whichcolor;
	int			thiscolor;
	const int	rainbow[7] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE};

	color = 0;
	whichcolor = env->z_max / 7;
	thiscolor = 0;
	while (color < 6)
	{
		thiscolor = thiscolor + whichcolor;
		if (z <= thiscolor)
			return (rainbow[color]);
		color++;
	}
	return (rainbow[color]);
}
