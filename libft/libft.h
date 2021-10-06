/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:53:29 by tblaase           #+#    #+#             */
/*   Updated: 2021/10/06 15:52:21 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <fcntl.h>

int		ft_atoi(const char *str);
int		ft_count_c(char *s, char c);
int		ft_count_lines(int fd);
int		ft_line_length(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
