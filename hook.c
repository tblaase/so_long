/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:39:11 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 14:20:05 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (EXIT_SUCCESS);
	}
	if (keycode == A)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->background, data->x, data->y);
		data->x -= TEXTURE_WIDTH;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->x, data->y);
	}
	if (keycode == S)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->background, data->x, data->y);
		data->y += TEXTURE_HEIGHT;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->x, data->y);
	}
	if (keycode == D)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->background, data->x, data->y);
		data->x += TEXTURE_WIDTH;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->x, data->y);
	}
	else if (keycode == W)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->background, data->x, data->y);
		data->y -= TEXTURE_HEIGHT;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->x, data->y);
	}
	printf("You moved %d times.\n", ++data->counter);
	// printf("keycode %d\n", keycode);
	return (0);
}
