/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:04:13 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 19:34:19 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_object(t_data *data, t_map *map, char *relative_path)
{
	int		img_width;
	int		img_height;

	printf("put: %s\n", relative_path);
	map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, map->object,
		map->x, map->y);
}

void	ft_put_player(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	data->player_x = map->x;
	data->player_y = map->y;
	printf("put player\n");
	relative_path = "./textures/ship.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->player_x, data->player_y);
}

// void	ft_put_border(t_data *data, t_map *map)
// {
// 	char	*relative_path;
// 	int		img_width;
// 	int		img_height;

// 	relative_path = "./textures/asteroid.xpm";
// 	data->player = mlx_xpm_file_to_image(data->mlx, relative_path,
// 			&img_width, &img_height);
// 	mlx_put_image_to_window(data->mlx, data->win, data->player,
// 		data->player_x, data->player_y);
// }

// void	ft_put_treasure(t_data *data)
// {
// 	char	*relative_path;
// 	int		img_width;
// 	int		img_height;

// 	relative_path = "./textures/asteroid.xpm";
// 	data->player = mlx_xpm_file_to_image(data->mlx, relative_path,
// 			&img_width, &img_height);
// 	mlx_put_image_to_window(data->mlx, data->win, data->player,
// 		data->player_x, data->player_y);
// }

// void	ft_put_exit(t_data *data)
// {
// }
