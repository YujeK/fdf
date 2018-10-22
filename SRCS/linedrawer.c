/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedrawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:03:54 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/22 19:01:44 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		signdetector(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}

void	ft_brosenham(t_env *env, t_line *line, int color, int swap)
{
	int i;

	i = 1;
	while (i <= line->dx)
	{
		mlx_pixel_put(env->mlx, env->win, line->x, line->y, color);
		while (line->d >= 0)
		{
			line->d = line->d - 2 * line->dx;
			if (swap)
				line->x = line->x + line->s1;
			else
				line->y = line->y + line->s2;
		}
		if (swap)
			line->y = line->y + line->s2;
		else
			line->x = line->x + line->s1;
		line->d = line->d + 2 * line->dy;
		i++;
	}
}

void	line_drawer(t_env *env, t_point point1, t_point point2, int color)
{
	t_line	*line;
	int		swap;
	int		temp;

	swap = 0;
	line = ft_memalloc(sizeof(t_line));
	line->dx = abs(point2.x - point1.x);
	line->dy = abs(point2.y - point1.y);
	line->s1 = signdetector(point2.x - point1.x);
	line->s2 = signdetector(point2.y - point1.y);
	if (line->dy > line->dx)
	{
		temp = line->dx;
		line->dx = line->dy;
		line->dy = temp;
		swap = 1;
	}
	line->d = 2 * line->dy - line->dx;
	line->x = point1.x;
	line->y = point1.y;
	ft_brosenham(env, line, color, swap);
	free(line);
}
