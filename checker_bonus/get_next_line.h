#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int chr);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
size_t	ft_strlen(char const *s);

#endif
