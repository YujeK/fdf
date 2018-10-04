/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:33:35 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/04 18:43:17 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     first_open(char *str)
{
	char    *line;
	int     fd;
	int		i;
	int		fsize;
	t_wing *bucket;

	i = -1;
	ft_readverif(char *str);
	while (get_next_line(fd, &line) == 1)
	{
		if (i = -1)
			fsize = ft_countwords(*line);
		else if (ft_countwords(*line) != fsize)
			ft_error(__func__, __LINE__);
	i++;
	}
	if (!(bucket = ft_memalloc(sizeof(t_wing) * fsize * i)))
		return (0);
    close(fd);
    free(line);
	return (*bucket);
}

/*
int     read(char *str)
{
	char    *line;
	int     fd;
	int     c;

	ft_readverif(char *str);
	while (get_next_line(fd, &line) == 1)
	{
		if c = -1;
        {
			{
				if parsing(*line) == 1;
				stock_line(*line)
			}
		}
	}

	int     parsing (char *str)
	{
		int i;

		i = 0;
		while (str[i] && str[i] != '\n')
		{
			if (ft_atoi(str) == TRUE)
				return (TRUE);
		}
	}
}
*/
