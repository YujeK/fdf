/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:26:05 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/06 17:12:11 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		retnextline(char **str, const int fd, char **line)
{
	size_t len;

	len = 0;
	while (str[fd][len] && str[fd][len] != '\n')
		len++;
	if (len != 0 || ft_strlen(str[fd]) > 0)
	{
		*line = ft_strsub(str[fd], 0, len);
		len += (len == ft_strlen(str[fd])) ? 0 : 1;
		str[fd] = ft_strsubfree(str[fd], len, ft_strlen(str[fd]) - len);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			reid;
	char		readance[BUFF_SIZE + 1];
	static char	*str[10240];

	if (line == NULL || fd < 0 || fd > 10240 || BUFF_SIZE < 1)
		return (-1);
	if (str[fd] == NULL)
		if ((str[fd] = ft_strnew(0)) == NULL)
			return (-1);
	while (!(ft_strchr(str[fd], '\n')) &&
			(reid = read(fd, readance, BUFF_SIZE)) > 0)
	{
		readance[reid] = '\0';
		if (!(str[fd] = ft_strjoinfree(str[fd], readance)))
			return (0);
	}
	if (reid == -1)
		return (-1);
	return (retnextline(str, fd, line));
}
