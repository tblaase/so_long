/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:50:29 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 13:52:09 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s)
/* will return the length of a string
** will return 0 if the string is empty */
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}
