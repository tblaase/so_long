/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:17:34 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 19:41:04 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_render_next_frame(t_data *data)
{
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

static void	ft_loop(t_data *data, t_map *map, char **argv)
{
	(void)map;
	(void)argv;

	// data->player_x = 0;
	// data->player_y = 0;
	// ft_put_player(data);
	mlx_loop_hook(data->mlx, ft_render_next_frame, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
	{
		perror("Usage: './so_long mapname.ber'");
		exit(EXIT_FAILURE);
	}
	ft_map_error(&data, argv);
	ft_window_size(&data, argv);
	data.counter = 0;
	/////////////////////////////
	// data.mlx = mlx_init();
	// data.win = mlx_new_window(data.mlx, data.windowsize_x,
	// data.windowsize_y, argv[1]);
	// // ft_create_map(&data, argv, &map);
	// map.x = 0;
	// map.y = 0;
	// ft_put_player(&data, &map);
	//////////////////////////
	ft_loop(&data, &map, argv);
	return (0);
}
