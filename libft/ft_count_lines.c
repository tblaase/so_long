/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:25:07 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/08 15:09:33 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_lines(int fd)
/* returns how many lines the file of fd contains */
{
	char	buffer[1];
	int		linecount;
	int		bytes;

	buffer[0] = '\0';
	linecount = 0;
	bytes = 1;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			linecount++;
	}
	return (linecount);
}
