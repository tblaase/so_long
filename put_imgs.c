/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:04:13 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 19:27:02 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putbackground(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->windowsize_y)
	{
		x = 0;
		while (x < data->windowsize_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->background, x, y);
			x += TEXTURE_WIDTH;
		}
		y += TEXTURE_HEIGHT;
	}
}

void	ft_put_object(t_data *data, t_map *map, char *relative_path)
{
	int		img_width;
	int		img_height;

	map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, map->object,
		(map->x * TEXTURE_WIDTH), (map->y * TEXTURE_HEIGHT));
}

void	ft_put_player(t_data *data, t_map *map)
{
	data->player_x = map->x;
	data->player_y = map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		(data->player_x * TEXTURE_WIDTH), (data->player_y * TEXTURE_HEIGHT));
}
