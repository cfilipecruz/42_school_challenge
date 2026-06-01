#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE <= 0
#  define GNL_BUFFER_SIZE 1
# else
#  define GNL_BUFFER_SIZE BUFFER_SIZE
# endif

typedef struct s_line
{
	char	*str;
	size_t	len;
	size_t	cap;
}	t_line;

void	gnl_init(t_line *line);
char	*gnl_free(t_line *line);
int		gnl_append(t_line *line, char *src, size_t size);
char	*get_next_line(int fd);

#endif