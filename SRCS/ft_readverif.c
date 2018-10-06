/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readverif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:08:03 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/06 17:33:07 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int	ft_readverif(char *str)
{
	int	fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error(__func__, __LINE__);
	return (fd);
}
