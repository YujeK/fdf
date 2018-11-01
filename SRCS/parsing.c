/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:33:35 by asamir-k          #+#    #+#             */
/*   Updated: 2018/11/01 17:08:46 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	bcktcreation(char *str, t_env *env)
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
			fsize = ctword(line);
		else if (ctword(line) != fsize || (i == 0 && ctword(line) <= 1))
			ft_error(__func__, __LINE__);
		free(line);
		i++;
	}
	if (i == 0)
		ft_error(__func__, __LINE__);
	env->c = fsize;
	env->lin = i + 1;
	if (!(env->bckt = ft_memalloc(sizeof(t_wing) * fsize * (i + 1))))
		ft_error(__func__, __LINE__);
	close(fd);
}

void	collectingwings(t_env *env, char *line, int wing)
{
	wing = wing * env->c;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		env->bckt[wing].z = ft_atoi(line);
		if (env->z_max < env->bckt[wing].z)
			env->z_max = env->bckt[wing].z;
		while (*line && *line != ' ')
		{
			if (ft_isdigit(*line) == 0 && *line != '-')
				ft_error(__func__, __LINE__);
			line++;
		}
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
	bcktcreation(str, env);
	wingscheck(str, env);
	ft_drawbucket(env);
}
