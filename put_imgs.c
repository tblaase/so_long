/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:04:13 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 16:38:01 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_data *data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/ship.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->player_x, data->player_y);
}

void	ft_put_border(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;


}
