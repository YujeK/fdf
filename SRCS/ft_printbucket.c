/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:11:22 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/22 18:55:39 by asamir-k         ###   ########.fr       */
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

int     ft_abs(int n)
{
    return (n < 0 ? -n : n);
}

void    ft_drawbucket(t_env *env)
{
    int x;
    int y;
    t_point point1;
    t_point point2;
    t_point point3;
    int wing;
    int size;
    int height;
    int width;

    if (env->col <= env->lin)
        size = (Xenvdim - 2 * BORDER)  / (env->col - 1);
    else
        size = (Yenvdim - 2 * BORDER)  / (env->lin - 1);

    env->corner1/*y*/ = 0;
    env->corner4/*y*/ = (env->col + env->lin) * (size) / 4/* + BORDER*//*- (env->bucket[wing].z)*/;
    height = ft_abs(env->corner1 - env->corner4);

    env->corner2/*x*/ = (env->col) * (size) / 2/* + BORDER*//*- (env->bucket[wing].z)*/;
    env->corner3/*x*/ = (0 - env->lin) * (size) / 2/* + BORDER*//*- (env->bucket[wing].z)*/;
    width = ft_abs(env->corner3 - env->corner2);

    printf("hauteur : %d\nlargeur : %d\n", height, width);

    y = -1;
    while (++y < env->lin)
    {
        x = -1;
        while (++x < env->col)
        {
            wing = y * env->col + x;
            point1.x = (x - y) * (size) / 2/* + BORDER*//*- (env->bucket[wing].z)*/;
            point1.y = ((x + y) * (size) / 4)/* + BORDER*//*- (env->bucket[wing].z)*/;
            point1.y -= (env->bucket[wing].z);
            point1.x += Xenvdim / 2 - (width / 6);
            point1.y += Yenvdim / 2 - (height / 2);
            if (x != env->col - 1)
            {
                point2.x =((x + 1) - y) * (size) / 2/* + BORDER*//* - (env->bucket[wing + 1].z)*/;
                point2.y =((x + 1) + y) * (size) / 4/* + BORDER*//* - (env->bucket[wing + 1].z)*/;
                point2.y -= (env->bucket[wing + 1].z);
                point2.x += Xenvdim / 2 - (width / 6);
                point2.y += Yenvdim / 2 - (height / 2);
                line_drawer(env, point1, point2, get_color(env, env->bucket[wing + env->col].z));
            }
            if (y != env->lin - 1)
            {
                point3.x =(x - (y + 1)) * size / 2/* + BORDER*//* - (env->bucket[wing + env->col].z)*/;
                point3.y = (x + (y + 1)) * size / 4/* + BORDER*//* - (env->bucket[wing + env->col].z)*/;
                point3.y -= (env->bucket[wing + env->col].z);
                point3.x += Xenvdim / 2 - (width / 6);
                point3.y += Yenvdim / 2 - (height / 2);
                line_drawer(env, point1, point3, get_color(env, env->bucket[wing + env->col].z));
            }
        }
        printf("\n");
    }
}
