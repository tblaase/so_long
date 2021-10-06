/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:17:34 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 16:32:56 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_render_next_frame(t_data *data)
{
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	char	*relative_path;
	int		img_width;
	int		img_height;

	if (argc != 2)
	{
		perror("Usage: './so_long mapname.ber'");
		exit(EXIT_FAILURE);
	}
	ft_map_error(&data, argv);
	ft_window_size(&data, argv);
	ft_create_map(&data, argv, &map);
	data.counter = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.windowsize_x,
			data.windowsize_y, argv[1]);
	mlx_loop_hook(data.mlx, ft_render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
