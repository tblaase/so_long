/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:12:06 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 16:48:03 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_data *data)
{
	printf("Congratulations, you won!\n");
	printf("You collected %d Diamonds.\n", data->collected);
	printf("Is %d moves really the best you can do?\n", data->counter);
	// sleep(1);
	exit(EXIT_SUCCESS);
}
