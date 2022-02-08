/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:52:53 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/08 16:57:49 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_gnl(char **p)
/*
** free's a given pointer and set's it to NULL
*/
{
	free(*p);
	*p = NULL;
}

int	ft_strlen_gnl(char *s)
/*
** returns length of a string until '\0'
** if the string is NULL return is 0
*/
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr_gnl(char *s, int c, int flag)
/*
** finds char c in string s and returns its position as an integer
** if flag == 1 return is -5 when input string is NULL
** if flag == 0 return is -1 when input string is NULL
*/
{
	int	i;

	if (flag == 1 && s == NULL)
		return (-5);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strnjoin_gnl(char *s1, char *s2, int n)
/*
** joins two strings
** first string does not have o exist
** only n characters of the second string get copied
** output is a allocated string
*/
{
	char	*output;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (s2[i2] == '\0')
		return (NULL);
	output = malloc(ft_strlen_gnl(s1) + n + 1);
	if (output == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			output[i] = s1[i];
			i++;
		}
	}
	while (s2 && s2[i2] != '\0' && i2 < n)
		output[i++] = s2[i2++];
	output[i] = '\0';
	if (s1)
		ft_free_gnl(&s1);
	return (output);
}

char	*ft_strndup_gnl(char *input, int n)
/*
** duplicates n characters from input into output
** output is a allocated string
*/
{
	char	*output;
	int		len;
	int		i;

	i = 0;
	len = n;
	output = malloc(len + 1);
	if (output == NULL)
		return (NULL);
	while (input && input[i] != '\0' && i < n)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
