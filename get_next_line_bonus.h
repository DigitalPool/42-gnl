/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 06:31:35 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 07:26:31 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE 1
# define FD_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

char	*get_next_line(int fd);
int		read_line(int fd, char **buffer);
char	*fill_the_line(char *buffer);
int		is_line(char *line);

size_t	find_end_line(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *s1, char *s2);
void	ft_shift_str(char *s, size_t shift, size_t len);

#endif
