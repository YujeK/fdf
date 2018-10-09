/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:11:22 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/09 17:33:46 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void    ft_printbucket(t_env *env)
{
    int i;
    int j;

    i = -1;
    while (++i < env->lin)
    {
        j = -1;
        while (++j < env->col)
        {
            ft_putnbr(env->bucket[i * env->col + j].z);
            ft_putchar(32);
        }
        ft_putchar('\n');
    }
}


#include "../INCLUDES/fdf.h"

void    ft_drawbucket(t_env *env)
{
    int x;
    int y;
    t_point point1;
    t_point point2;
    t_point point3;
    int wing;

    y = -1;
    while (++y < env->lin)
    {
        x = -1;
        while (++x < env->col)
        {
            wing = y * env->col + x;
            if (x != env->col - 1 && y != env->lin - 1)
                printf("P1 %d P2 %d P3 %d\n", env->bucket[wing].z, env->bucket[wing + 1].z, env->bucket[wing + env->col].z);
            point1.x = x * (Xenvdim - 2 * BORDER)  / (env->col - 1) + BORDER - (env->bucket[wing].z);
            point1.y = y * (Yenvdim - 2 * BORDER)  / (env->lin - 1) + BORDER - (env->bucket[wing].z);
            if (x != env->col - 1)
            {
                point2.x = (x + 1) * (Xenvdim - 2 * BORDER) / (env->col - 1) + BORDER - (env->bucket[wing + 1].z);
                point2.y = y * (Yenvdim - 2 * BORDER)  / (env->lin - 1) + BORDER - (env->bucket[wing + 1].z);
                line_drawer(env, point1, point2, PINK);
            }
            if (y != env->lin - 1)
            {
                point3.x = x * (Xenvdim - 2 * BORDER)  / (env->col - 1) + BORDER - (env->bucket[wing + env->col].z);
                point3.y = (y + 1) * (Yenvdim - 2 * BORDER)  / (env->lin - 1) + BORDER - (env->bucket[wing + env->col].z);
                line_drawer(env, point1, point3, BLUE);
            }
        }
        printf("\n");
    }
}
