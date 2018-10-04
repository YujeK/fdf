/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedrawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:03:54 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/18 20:05:59 by asamir-k         ###   ########.fr       */
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
			if (swap)
				line->x = line->x + line->s1;
			else
			{
				line->y = line->y + line->s2;
				line->d = line->d - 2 * line->dx;
			}
		}
		if (swap)
			line->y = line->y + line->s2;
		else
		{
			line->x = line->x + line->s1;
			line->d = line->d + 2 * line->dy;
		}
		i++;
	}
}

void	line_drawer(t_env *env, t_point1 *point1, t_point2 *point2, int color)
{
	t_line	*line;
	int		swap;
	int		temp;

	swap = 0;
	line = ft_memalloc(sizeof(t_line));
	line->dx = abs(point2->x2 - point1->x1);
	line->dy = abs(point2->y2 - point1->y1);
	line->s1 = signdetector(point2->x2 - point1->x1);
	line->s2 = signdetector(point2->y2 - point1->y1);
	if (line->dy > line->dx)
	{
		temp = line->dx;
		line->dx = line->dy;
		line->dy = temp;
		swap = 1;
	}
	line->d = 2 * line->dy - line->dx;
	line->x = point1->x1;
	line->y = point1->y1;
	ft_brosenham(env, line, color, swap);
}
