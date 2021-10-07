/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:07:33 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 19:13:43 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data, char **argv)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/ship.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/nightsky.xpm";
	data->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	ft_window_size(data, argv);
	data->counter = 0;
	data->collected = 0;
}
