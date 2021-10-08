/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:42:26 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/08 13:10:16 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

/* ********** defines to make work easier ********** */

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

/* ***** struct to store the different images ***** */

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}				t_img;

/* ***** struct to create the map and keep track of the contents ***** */

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		diamonds;
}				t_map;

/* ***** struct to hand all of my programms data between functions ***** */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}				t_data;

/* ********** all of my functions ********** */

void	ft_fill_background(t_data *data);
void	ft_window_size(t_data *data, char **argv);
int		ft_key_hook(int keycode, t_data *data);
void	ft_create_map(t_data *data);
void	ft_put_object(t_data *data, char *relative_path);
void	ft_put_player(t_data *data);
void	ft_parse_input(t_data *data, char **argv, int argc);
void	ft_putbackground(t_data *data);
void	ft_win(t_data *data);
int		ft_mouse_hook(int mousecode, t_data *data);
void	ft_move(t_data *data, char position, int direction);
int		ft_exit(t_data *data);
void	ft_init(t_data *data, t_map *map);

#endif
