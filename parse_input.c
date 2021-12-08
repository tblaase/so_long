/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:14:33 by tblaase           #+#    #+#             */
/*   Updated: 2021/12/08 14:36:05 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_map_error(char *error_msg)
/* will print the error message end exit the process */
{
	printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

static void	ft_check_borders(t_data *data)
/* will check if the whole map is surrounded by walls */
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			ft_map_error("Error\nmap has to be rectangular\n");
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				ft_map_error("Error\nfor map '0','1','C','P','E' are valid\n");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				ft_map_error("Error\nmap has to be surrounded by walls\n");
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				ft_map_error("Error\nmap has to be surrounded by walls\n");
			x++;
		}
		y++;
	}
}

static void	ft_check_content(t_data *data)
/* will check the contents of the map if valid */
{
	int	y;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map->diamonds = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		exit += ft_count_c(data->map->map[y], 'E');
		player += ft_count_c(data->map->map[y], 'P');
		data->map->diamonds += ft_count_c(data->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_map_error("Error\nonly valid map if one player is contained\n");
	if (exit == 0)
		ft_map_error("Error\nonly valid map if at least one exit is contained\n");
	if (data->map->diamonds == 0)
		ft_map_error("Error\nonly valid map if at least one coin is contained\n");
}

static void	ft_input_error(int	argc)
/* only exists because of the 25 line limit */
{
	if (argc != 2)
	{
		ft_map_error("Error\nUsage: './so_long mappath/mapname.ber'\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_parse_input(t_data *data, char **argv, int argc)
/* will translate the .ber file into a 2-dimensional array of char * */
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	ft_input_error(argc);
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	ft_check_content(data);
	ft_check_borders(data);
}
