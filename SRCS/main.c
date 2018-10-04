/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:50:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/04 14:03:57 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		main(void)
{
	t_env *env;
	t_point1 *point1;
	t_point2 *point2;

	if (!(point1 = ft_memalloc(sizeof(t_point1))))
		return (1);
	if (!(point2 = ft_memalloc(sizeof(t_point2))))
		return (1);
	if (!(env = ft_memalloc(sizeof(t_env))))
		return (1);

	point1->x1 = 15;
	point1->y1 = 15;
	point2->x2 = 400;
	point2->y2 = 15;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, Xenvdim, Yenvdim, "mlx 42");
	mlx_key_hook(env->win, key_manager, (void*)0);
	mlx_mouse_hook(env->win, mouse_manager, (void*)0);
	line_drawer(env, point1, point2, GREEN);
	point1->x1 = 400;
	point1->y1 = 15;
	point2->x2 = 400;
	point2->y2 = 400;
	line_drawer(env, point1, point2, YELLOW);
	point1->x1 = 400;
	point1->y1 = 400;
	point2->x2 = 15;
	point2->y2 = 400;
	line_drawer(env, point1, point2, BLUE);
	point1->x1 = 15;
	point1->y1 = 400;
	point2->x2 = 15;
	point2->y2 = 15;
	line_drawer(env, point1, point2, PURPLE);
	mlx_loop(env->mlx);
}
