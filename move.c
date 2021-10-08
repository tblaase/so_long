/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:39:11 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/08 11:07:37 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_move(t_data *data, char position, int direction)
{
	if (position == 'y' && direction == -1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			(data->player_x * IMG_W), (data->player_y * IMG_H));
	}
	if (position == 'x' && direction == -1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			(data->player_x * IMG_W), (data->player_y * IMG_H));
	}
	if (position == 'y' && direction == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_down,
			(data->player_x * IMG_W), (data->player_y * IMG_H));
	}
	if (position == 'x' && direction == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			(data->player_x * IMG_W), (data->player_y * IMG_H));
	}
}

static void	ft_collect(t_data *data, char position, int direction)
{
	data->collected++;
	data->map->map[data->player_y][data->player_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->player_x * IMG_W), (data->player_y * IMG_H));
	ft_player_move(data, position, direction);
}

void	ft_move(t_data *data, char position, int direction)
{
	// if (position == 'y')
	// {
	// 	if (map->map[data->player_y + 1 * direction][data->player_x] == '1')
	// 		return ;
	// }
	// if (position == 'x')
	// {
	// 	if (map->map[data->player_y][data->player_x + 1 * direction] == '1')
	// 		return ;
	// }
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->player_x * IMG_W), (data->player_y * IMG_H));
	if (position == 'y' && data->map->map[data->player_y + 1 * direction][data->player_x] != '1')
		data->player_y = data->player_y + 1 * direction;
	else if (position == 'x' && data->map->map[data->player_y][data->player_x + 1 * direction] != '1')
		data->player_x = data->player_x + 1 * direction;
	ft_player_move(data, position, direction);
	if (data->map->map[data->player_y][data->player_x] == 'C')
		ft_collect(data, position, direction);
	mlx_do_sync(data->mlx);
}
