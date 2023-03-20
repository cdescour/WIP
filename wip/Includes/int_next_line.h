/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:44:54 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 09:45:14 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_NEXT_LINE_H
# define INT_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define FD_SIZE  4864
# define BUFFER_SIZE 100

int		int_next_line(int fd, char **line);
int		ft_remplissage(char **tmp, int fd, char **line);
int		free_leak(char **ptr, int nb, int fd);
char	*ft_check(char **tmp, int r, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif

