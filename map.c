/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:32:53 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 18:39:00 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(t_data *data, char **argv)
{
	(void)data;
	(void)argv;
}

void	ft_fill_background(t_data *data)
{
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	char	*relative_path;

	relative_path = "./textures/nightsky.xpm";
	data->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
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
		printf("Error: map has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->windowsize_x = ft_line_length(fd);
	data->windowsize_y = ft_count_lines(fd);
	printf("%d, %d\n", data->windowsize_x, data->windowsize_y);
	data->windowsize_x *= TEXTURE_WIDTH;
	data->windowsize_y *= TEXTURE_HEIGHT;
	printf("%d, %d\n", data->windowsize_x, data->windowsize_y);
	if (data->windowsize_x <= 0 || data->windowsize_y <= 0)
	{
		perror("Error: map has no valid dimensions");
		exit(EXIT_FAILURE);
	}
}

void	ft_create_map(t_data *data, t_map *map)
{
	map->x = 0;
	map->y = 0;
	while (map->y < (data->windowsize_y / TEXTURE_HEIGHT))
	{
		// printf("coordinates put: %d, %d\n", map->x, map->y);
		if (map->map[map->y][map->x] == 'P')
			ft_put_player(data, map);
		else if (map->map[map->y][map->x] == '1')
			ft_put_object(data, map, "./textures/asteroid.xpm");
		else if (map->map[map->y][map->x] == 'C')
			ft_put_object(data, map, "./textures/gemstone.xpm");
		else if (map->map[map->y][map->x] == 'E')
			ft_put_object(data, map, "./textures/galaxy.xpm");
		if (map->x < (data->windowsize_x / TEXTURE_WIDTH))
			map->x++;
		else
		{
			map->y++;
			map->x = 0;
		}
	}
}
