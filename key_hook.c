/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:51:04 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 18:30:32 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	if (keycode == A)
		ft_move(data, data->map, 'x', LEFT);
	else if (keycode == S)
		ft_move(data, data->map, 'y', DOWN);
	else if (keycode == D)
		ft_move(data, data->map, 'x', RIGHT);
	else if (keycode == W)
		ft_move(data, data->map, 'y', UP);
	printf("You moved %d times.\n", ++data->counter);
	if (data->map->map[data->player_y][data->player_x] == 'E')
		ft_win(data);
	return (0);
}
