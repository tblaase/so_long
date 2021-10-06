/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:39:11 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 18:33:21 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_up(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->background,
		data->player_x, data->player_y);
	data->player_y -= TEXTURE_HEIGHT;
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->player_x, data->player_y);
}

static void	ft_move_left(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->background,
		data->player_x, data->player_y);
	data->player_x -= TEXTURE_WIDTH;
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->player_x, data->player_y);
}

static void	ft_move_down(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->background,
		data->player_x, data->player_y);
	data->player_y += TEXTURE_HEIGHT;
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->player_x, data->player_y);
}

static void	ft_move_right(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->background,
		data->player_x, data->player_y);
	data->player_x += TEXTURE_WIDTH;
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->player_x, data->player_y);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (EXIT_SUCCESS);
	}
	if (keycode == A)
		ft_move_left(data);
	else if (keycode == S)
		ft_move_down(data);
	else if (keycode == D)
		ft_move_right(data);
	else if (keycode == W)
		ft_move_up(data);
	printf("You moved %d times.\n", ++data->counter);
	return (0);
}
