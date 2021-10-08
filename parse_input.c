/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:14:33 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/08 11:23:14 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_map_error(char *error_msg)
{
	printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

static void	ft_check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->windowsize_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->windowsize_x / IMG_W)
			ft_map_error("Error: invalid map\n");
		x = 0;
		while (x < (data->windowsize_x / IMG_W))
		{
			if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
			{
				// printf("%d, %d\n", x, y);
				// printf("%c\n", map->map[y][x]);
				ft_map_error("Error: invalid map\n");
			}
			if ((y == (data->windowsize_y / IMG_H - 1) || x == (data->windowsize_x / IMG_W - 1)) && data->map->map[y][x] != '1')
				ft_map_error("Error: invalid map\n");
			x++;
		}
		y++;
	}
}

static void	ft_input_error(t_data *data)
{
	// ft_check_content(data);
	ft_check_borders(data);
}

void	ft_parse_input(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	if (argc != 2)
	{
		printf("Usage: './so_long mapname.ber'");
		exit(EXIT_FAILURE);
	}
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	ft_input_error(data);
}
