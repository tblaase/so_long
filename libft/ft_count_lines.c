/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:25:07 by tblaase           #+#    #+#             */
/*   Updated: 2021/12/08 17:16:04 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	exit_error(void)
{
	printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd, int x, int img_w)
/* returns how many lines the file of fd contains */
{
	char	buffer[1];
	int		linecount;
	int		bytes;
	int		i;

	i = 0;
	buffer[0] = '\0';
	linecount = 1;
	bytes = 1;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1 && i != (x / img_w))
			exit_error();
		if (i == (x / img_w))
		{
			linecount++;
			i = 0;
		}
		else
			i++;
	}
	return (linecount);
}
