/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:32:53 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 16:40:46 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(t_data *data, char **argv)
{
	(void)data;
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
	data->windowsize_x = ft_line_length(fd) * TEXTURE_WIDTH;
	data->windowsize_y = ft_count_lines(fd) * TEXTURE_HEIGHT;
	printf("%d, %d\n", data->windowsize_x, data->windowsize_y);
	if (data->windowsize_x <= 0 || data->windowsize_y <= 0)
	{
		perror("Error when creating map");
		exit(EXIT_FAILURE);
	}
}

void	ft_create_map(t_data *data, char **argv, t_map *map)
{
	char	buffer[1];
	int		fd;
	int		i;
	int		bytes;

	bytes = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	map->boder = malloc(data->windowsize_y * sizeof(char *));
	if (!map->boder)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	while (map->boder[i])
	{
		map->boder[i++] = ft_calloc(data->windowsize_x, sizeof(char));
		if (!map->boder[i])
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
	}
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] == '1')
			ft_put_border(data, map);
		if (buffer[0] == 'P')
			ft_put_player(data);
		if (buffer[0] == 'C')
			ft_put_treasure(data);
		if (buffer[0] == 'E')
			ft_put_exit(data);//////still need to add exit texture
	}
}
