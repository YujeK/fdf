/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboardinputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:54:01 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/23 17:34:42 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	trans_manager(int key, t_env *env)
{
	if (key == 83)
		env->trans_ratio++;
	if (key == 82 && env->trans_ratio > 1)
		env->trans_ratio--;
	if (key == 125)
		env->trans_y -= env->trans_ratio;
	if (key == 124)
		env->trans_x -= env->trans_ratio;
	if (key == 123)
		env->trans_x += env->trans_ratio;
	if (key == 126)
		env->trans_y += env->trans_ratio;
}

void	z_manager(int key, t_env *env)
{
	if (key == 14 && env->z_ratio > 1)
		env->z_ratio--;
	if (key == 12)
		env->z_ratio++;
	if (key == 13)
		env->z_modify += env->z_ratio;
	if (key == 1)
		env->z_modify -= env->z_ratio;
	if (key == 49)
	{
		env->trans_y = 0;
		env->trans_x = 0;
		env->z_modify = 0;
	}
}

void	zoom_manager(int key, t_env *env)
{
	if (key == 75 && env->zoom_ratio > 1)
		env->zoom_ratio--;
	if (key == 67)
		env->zoom_ratio++;
	if (key == 78)
		env->zoom_modify += env->zoom_ratio;
	if (key == 69)
		env->zoom_modify -= env->zoom_ratio;
}

int		key_manager(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	ft_putstr("keyinput :");
	ft_putnbr(key);
	ft_putchar('\n');
	trans_manager(key, env);
	z_manager(key, env);
	zoom_manager(key, env);
	mlx_clear_window(env->mlx, env->win);
	ft_drawbucket(env);
	return (0);
}
