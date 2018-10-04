/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readverif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:08:03 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/04 13:32:17 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	ft_readverif(char *file_name)
{
	int	fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error(__func__, __LINE__);
	return (fd);
}
