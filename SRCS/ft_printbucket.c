/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:11:22 by asamir-k          #+#    #+#             */
/*   Updated: 2018/11/01 17:14:51 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void				get_corners(t_env *env)
{
	if (env->c <= env->lin)
		env->size = (((XDIM - 2 * BORDER) / (env->c - 1)) - env->zoom_modify);
	else
		env->size = (((YDIM - 2 * BORDER) / (env->lin - 1)) - env->zoom_modify);
	env->corner1 = 0;
	env->corner4 = (env->c + env->lin) * (env->size) / 4;
	env->height = abs(env->corner1 - env->corner4);
	env->corner2 = (env->c) * (env->size) / 2;
	env->corner3 = (0 - env->lin) * (env->size) / 2;
	env->width = abs(env->corner3 - env->corner2);
}

t_point				get_coord_pt1(int x, int y, t_env *env)
{
	t_point		pt[3];

	env->w = y * env->c + x;
	pt[0].x = (x - y) * (env->size) / 2;
	pt[0].y = ((x + y) * (env->size) / 4);
	pt[0].y -= (env->bckt[env->w].z * env->z_modify);
	pt[0].x += XDIM / 2 - (env->width / 6);
	pt[0].x += env->trans_x;
	pt[0].y += YDIM / 2 - (env->height / 2);
	pt[0].y += env->trans_y;
	return (pt[0]);
}

t_point				get_coord_pt2(int x, int y, t_env *env)
{
	t_point		pt[3];

	pt[1].x = ((x + 1) - y) * (env->size) / 2;
	pt[1].y = ((x + 1) + y) * (env->size) / 4;
	pt[1].y -= (env->bckt[env->w + 1].z * env->z_modify);
	pt[1].x += XDIM / 2 - (env->width / 6);
	pt[1].x += env->trans_x;
	pt[1].y += YDIM / 2 - (env->height / 2);
	pt[1].y += env->trans_y;
	return (pt[1]);
}

t_point				get_coord_pt3(int x, int y, t_env *env)
{
	t_point			pt[3];

	pt[2].x = (x - (y + 1)) * env->size / 2;
	pt[2].y = (x + (y + 1)) * env->size / 4;
	pt[2].y -= (env->bckt[env->w + env->c].z * env->z_modify);
	pt[2].x += XDIM / 2 - (env->width / 6);
	pt[2].x += env->trans_x;
	pt[2].y += YDIM / 2 - (env->height / 2);
	pt[2].y += env->trans_y;
	return (pt[2]);
}

void				ft_drawbucket(t_env *env)
{
	int			x;
	int			y;
	t_point		pt[3];

	get_corners(env);
	y = -1;
	while (++y < env->lin)
	{
		x = -1;
		while (++x < env->c)
		{
			pt[0] = get_coord_pt1(x, y, env);
			if (x != env->c - 1)
			{
				pt[1] = get_coord_pt2(x, y, env);
				dl(env, pt[0], pt[1], rbw(env, env->bckt[env->w + env->c].z));
			}
			if (y != env->lin - 1)
			{
				pt[2] = get_coord_pt3(x, y, env);
				dl(env, pt[0], pt[2], rbw(env, env->bckt[env->w + env->c].z));
			}
		}
		ft_putchar('\n');
	}
}
