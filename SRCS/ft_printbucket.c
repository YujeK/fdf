/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:11:22 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/06 18:50:47 by asamir-k         ###   ########.fr       */
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
