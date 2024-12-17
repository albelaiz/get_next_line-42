/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:52:43 by albelaiz          #+#    #+#             */
/*   Updated: 2024/12/14 18:44:10 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_after_line(char *copy);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_extract_line(char *str);
char	*ft_strchr(const char *str, int c);
char	*read_and_append(int fd, char *copy);
void	*free_buffer(int bytes, char *buffer);
char	*ft_strncpy(char *s1, char *s2, int len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
