/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:32:53 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/08 13:26:58 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_background(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	ft_window_size(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Invalid map_path/map");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd) * IMG_H);
	if (data->size_x <= 0 || data->size_y <= 0)
	{
		printf("Error\nmap has no valid dimensions\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_create_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_object(data, "./textures/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_put_object(data, "./textures/collectable.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_put_object(data, "./textures/exit.xpm");
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
