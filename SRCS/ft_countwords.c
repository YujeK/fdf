/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:45:02 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/04 18:04:05 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     ft_countwords(char *str)
{
    int i;
    int countwords;
    int word;

    i = 0;
    countwords = 0;
    while (str[i] != '\n')
    {
        word = 0;
        while (str[i] == ' ' && str[i])
            i++;
        while (str[i] && (str[i] != ' '))
        {
            i++;
            word = 1;
        }
        if (word == 1)
        countwords++;
    }
    return (countwords);
}
