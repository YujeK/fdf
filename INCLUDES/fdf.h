/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:27:56 by asamir-k          #+#    #+#             */
/*   Updated: 2018/10/09 17:02:06 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "mlx.h"
#include <fcntl.h>

# define Yenvdim 800
# define Xenvdim 800
# define BORDER 5

/*
** Colors  HEXADECIMAL :
*/
# define PINK       0xFD2BE6
# define BLUE       0x0012FD
# define RED        0xFD0000
# define CYAN       0x00F3FD
# define YELLOW     0xFDF800
# define GREEN      0x05FD00
# define BROWN      0x8C4629
# define ORANGE     0xF87C00
# define WHITE      0xFFFFFF
# define BLACK      0x000000
# define PURPLE     0x7400AC
# define GREY       0x9A9A9A

typedef struct      s_wing
{
    int colors;
    int z;
}                   t_wing;

typedef struct      s_env
{
    void    *mlx;
    void    *win;
    int     x;
    int     y;
    int     col;
    int     lin;
    t_wing  *bucket;
}                   t_env;

typedef struct      s_line
{
    int     x;
    int     y;
    int     d;
    int     dx;
    int     dy;
    int     s1;
    int     s2;
}                   t_line;

typedef struct      s_point
{
    int     x;
    int     y;
}                   t_point;


int     signdetector(int x);
int		main(int ac, char *av[]);
void	line_drawer(t_env *env, t_point point1, t_point point2, int color);
int     key_manager(int key, void *param);
int     mouse_manager(int button, void *param);
void    parsemanager(t_env *env, char *str);
int     ft_readverif(char *str);
void    ft_error(const char function[], int line);
int     ft_countwords(char *str);
void    ft_printbucket(t_env *env);
void    ft_drawbucket(t_env *env);

#endif
