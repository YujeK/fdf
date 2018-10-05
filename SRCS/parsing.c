/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:33:35 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/05 18:23:22 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_wing	*bucketcreation(char *str, t_env *env)
{
	char    *line;
	int     fd;
	int		i;
	int		fsize;
	t_wing	*bucket;

	i = -1;
	fd = ft_readverif(str);
	while (get_next_line(fd, &line) == 1)
	{
		if (i = -1)
			fsize = ft_countwords(*line);
		else if (ft_countwords(*line) != fsize)
			ft_error(__func__, __LINE__);
		free(line);
		i++;
	}
	env->col = fsize;
	env->lin = i;
	if (!(bucket = ft_memalloc(sizeof(t_wing) * fsize * (i + 1))))
		ft_error(__func__, __LINE__);
    close (fd);
	return (bucket, env);
}

void     wingscheck(char *str, t_env *env, t_wing *bucket)
{
	char    *line;
	int     fd;
	int		wing;

	fd = ft_readverif(str);
	wing = 0;
	while (get_next_line(fd, &line) == 1)
	{
		collectingwings(line, bucket, wing, env->col);
		free (line);
		wing++;
	}
	close (fd);
}

void	collectingwings(char *line, t_wing *bucket, int wing, int wing_multiplicator)
{
	wing = wing * wing_multiplicator;
	while (*line)
	{
		while (*line && *line == ' ')
			*line++;
		bucket[wing].z = ft_atoi(*line);
		bucket[wing].colors = PINK;
		while (*line && *line != ' ')
			*line++;
		wing++;
	}
}

t_wing	*parsemanager(char *str)
{

	t_env	*env;
	t_wing	*bucket;

	if (!(env = ft_memalloc(sizeof(env))))
		ft_error(__func__, __LINE__);
	bucketcreation (str, env);
	wingscheck (str, env, bucket);
	ft_printbucket(env);
}
