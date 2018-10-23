/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:33:35 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/23 11:16:28 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	bucketcreation(char *str, t_env *env)
{
	char	*line;
	int		fd;
	int		i;
	int		fsize;

	i = -1;
	fd = ft_readverif(str);
	while (get_next_line(fd, &line) == 1)
	{
		if (i == -1)
			fsize = ft_countwords(line);
		else if (ft_countwords(line) != fsize)
			ft_error(__func__, __LINE__);
		free(line);
		i++;
	}
	env->col = fsize;
	env->lin = i + 1;
	if (!(env->bucket = ft_memalloc(sizeof(t_wing) * fsize * (i + 1))))
		ft_error(__func__, __LINE__);
	close(fd);
}

void	collectingwings(t_env *env, char *line, int wing)
{
	wing = wing * env->col;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		env->bucket[wing].z = ft_atoi(line);
		if (env->z_max < env->bucket[wing].z)
			env->z_max = env->bucket[wing].z;
		while (*line && *line != ' ')
			line++;
		wing++;
	}
}

void	wingscheck(char *str, t_env *env)
{
	char	*line;
	int		fd;
	int		wing;

	fd = ft_readverif(str);
	wing = 0;
	while (get_next_line(fd, &line) == 1)
	{
		collectingwings(env, line, wing);
		free(line);
		wing++;
	}
	close(fd);
}

void	parsemanager(t_env *env, char *str)
{
	bucketcreation(str, env);
	wingscheck(str, env);
	ft_printbucket(env);
	ft_drawbucket(env);
}
