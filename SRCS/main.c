/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:50:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/23 18:30:18 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		main(int ac, char **av)
{
	t_env *env;

	(void)ac;
	if (!(env = ft_memalloc(sizeof(t_env))))
		return (1);
	env->trans_ratio = 10;
	env->z_ratio = 1;
	env->zoom_ratio = 1;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, XENVDIM, YENVDIM, "mlx 42");
	mlx_hook(env->win, 2, 0, key_manager, env);
	mlx_mouse_hook(env->win, mouse_manager, (void*)0);
	parsemanager(env, av[1]);
	mlx_loop(env->mlx);
}
