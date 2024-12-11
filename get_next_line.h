#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
char	*read_and_append(int fd, char *copy);
void	*free_buffer(int bytes, char *buffer);
char	*ft_strncpy(char *s1, char *s2, int len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif