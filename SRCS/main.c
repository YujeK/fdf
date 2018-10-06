/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:50:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/06 19:20:56 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		main(int ac, char *av[])
{
	t_env *env;
	t_point point1;
	t_point point2;
	(void) ac;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (1);

	point1.x = 15;
	point1.y = 15;
	point2.x = 400;
	point2.y = 15;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, Xenvdim, Yenvdim, "mlx 42");
	mlx_key_hook(env->win, key_manager, (void*)0);
	mlx_mouse_hook(env->win, mouse_manager, (void*)0);
	parsemanager(env, av[1]);
	line_drawer(env, point1, point2, GREEN);
	mlx_loop(env->mlx);
}
