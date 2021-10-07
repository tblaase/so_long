/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:39:11 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 16:51:40 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_collect(t_data *data, t_map *map)
{
	data->collected++;
	map->map[data->player_y][data->player_x] = '0';
}

void	ft_move(t_data *data, t_map *map, char position, int direction)
{
	if (position == 'y')
	{
		if (map->map[data->player_y + 1 * direction][data->player_x] == '1')
			return ;
	}
	if (position == 'x')
	{
		if (map->map[data->player_y][data->player_x + 1 * direction] == '1')
			return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->background,
		(data->player_x * TEXTURE_WIDTH), (data->player_y * TEXTURE_HEIGHT));
	if (position == 'y')
		data->player_y = data->player_y + 1 * direction;
	if (position == 'x')
		data->player_x = data->player_x + 1 * direction;
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		(data->player_x * TEXTURE_WIDTH), (data->player_y * TEXTURE_HEIGHT));
	if (map->map[data->player_y][data->player_x] == 'C')
		ft_collect(data, map);
	mlx_do_sync(data->mlx);
}
