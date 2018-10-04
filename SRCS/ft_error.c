/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:05:14 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/04 13:12:49 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <sys/errno.h>

void	ft_error(const char function[], int line)
{
	ft_putstr("Error during ");
	ft_putstr(function);
	ft_putstr(" (at line : ");
    ft_putnbr(line);
	ft_putstr(") => ");
	ft_putendl_fd(strerror(errno), 2);
	exit(errno);
}
