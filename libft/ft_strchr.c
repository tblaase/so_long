/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:37:46 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 13:53:02 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
/* will return a pointer to the position of first appearance of c in s
** will return a pointer to NULL if not found */
{
	char	a;
	int		i;

	if (!s)
		return (NULL);
	a = c;
	i = 0;
	while (s && s[i] != '\0' && s[i] != a)
		i++;
	if (s[i] == a)
		return ((char *)(s + i));
	else
		return (NULL);
}
