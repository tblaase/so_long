/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:12:06 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/08 15:34:07 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_data *data)
{
	printf("Congratulations, you found all the Diamonds and the exit.\n");
	printf("You won!\n");
	printf("Is %d moves really the best you can do?\n", data->counter);
	exit(EXIT_SUCCESS);
}
