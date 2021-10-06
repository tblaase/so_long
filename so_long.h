/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:42:26 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 19:33:15 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

/* ********** defines to make work easier ********** */

# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32
# define W 13
# define A 0
# define S 1
# define D 2

/* ***** struct to hand all of my programms data between functions ***** */

typedef struct s_data
{
	void	*mlx;
	void	*player;
	void	*background;
	void	*win;
	int		windowsize_x;
	int		windowsize_y;
	int		player_x;
	int		player_y;
	int		counter;
}				t_data;

/* ***** struct to create the map and keep track of the borders ***** */

typedef struct s_map
{
	char	**boder;
	void	*object;
	int		x;
	int		y;
}				t_map;

/* ********** all of my functions ********** */

void	ft_fill_background(t_data *data);
void	ft_map_error(t_data *data, char **argv);
void	ft_window_size(t_data *data, char **argv);
int		ft_key_hook(int keycode, t_data *data);
void	ft_create_map(t_data *data, char **argv, t_map *map);
void	ft_put_object(t_data *data, t_map *map, char *relative_path);
// void	ft_put_border(t_data *data, t_map *map);
void	ft_put_player(t_data *data, t_map *map);

#endif
