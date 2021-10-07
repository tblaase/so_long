/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:17:34 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 19:23:11 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_FAILURE);
}

static int	ft_render_next_frame(t_data *data, t_map *map)
{
	ft_putbackground(data);
	ft_create_map(data, map);
	data->map = map;
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
	{
		printf("Usage: './so_long mapname.ber'");
		exit(EXIT_FAILURE);
	}
	ft_init(&data, argv);
	map.map = ft_calloc(data.windowsize_y + 1, sizeof(char *));
	if (!map.map)
	{
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}
	ft_parse_input(&map, argv);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		printf("programm init failed");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.windowsize_x,
			data.windowsize_y, "./so_long");
	ft_render_next_frame(&data, &map);
	mlx_loop(data.mlx);
	perror("loop failed");
	exit(EXIT_FAILURE);
}
