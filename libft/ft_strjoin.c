/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:29:26 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/07 19:00:13 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
/* will append s2 to s1
** will return NULL if s2 is NULL */
{
	char	*c;
	int		i;
	int		i2;

	if (!s2)
		return (NULL);
	i = 0;
	i2 = 0;
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		c[i++] = s2[i2++];
	c[i] = '\0';
	free(s1);
	s1 = NULL;
	return (c);
}
