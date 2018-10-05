/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:11:22 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/05 18:25:23 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_printbucket(t_env *env, t_wing *bucket)
{
    int i;
    int j;
    int wing;

    i = -1;
    wing = 0;
    while (i < env->lin)
    {
        while (j < env->col)
        {
        printf("%d ", bucket[wing].z);
        wing++;
        j++;
        }
        ft_putchar("\n");
    i++;
    }
}
