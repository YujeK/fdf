/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:47:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/11/01 18:22:48 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		rbw(t_env *env, int z)
{
	int			color;
	int			whichcolor;
	int			thiscolor;
	static int	rainbow[7] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE};

	color = 0;
	whichcolor = (env->z_max) / 7;
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
