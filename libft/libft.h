/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:53:29 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/08 17:09:59 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t nelem, size_t elsize);
int		ft_count_c(char *s, char c);
int		ft_count_lines(int fd, int line_length, int img_w);
int		ft_line_length(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// get_next_line
//this part lets you controll the BUFFER_SIZE without adding it when compiling
//this is really usefull when used inside libft
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void		ft_free_gnl(char **p);
int			ft_strlen_gnl(char *s);
int			ft_strchr_gnl(char *s, int c, int flag);
char		*ft_strnjoin_gnl(char *s1, char *s2, int n);
char		*ft_strndup_gnl(char *str, int n);
void		*ft_calloc_gnl(size_t nelem, size_t elsize);
char		*ft_update_nl_gnl(char **next_line, int position);
char		*ft_output_gnl(char **next_line, int position, int bytes);
char		*get_next_line(int fd);

#endif
