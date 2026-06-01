#include "get_next_line.h"

static char	*gnl_reset(ssize_t *pos, ssize_t *len)
{
	*pos = 0;
	*len = 0;
	return (NULL);
}

static int	gnl_take(char *buf, ssize_t *pos, ssize_t len, t_line *line)
{
	ssize_t	start;
	ssize_t	end;

	start = *pos;
	end = start;
	while (end < len && buf[end] != '\n')
		end++;
	if (end < len && buf[end] == '\n')
		end++;
	if (!gnl_append(line, buf + start, (size_t)(end - start)))
		return (-1);
	*pos = end;
	if (line->str[line->len - 1] == '\n')
		return (1);
	return (0);
}

static int	gnl_fill(int fd, char *buf, ssize_t *pos,
	ssize_t *len, t_line *line)
{
	int	status;

	status = 0;
	while (status == 0)
	{
		if (*pos >= *len)
		{
			*len = read(fd, buf, BUFFER_SIZE);
			*pos = 0;
			if (*len <= 0)
				return ((int)*len);
		}
		status = gnl_take(buf, pos, *len, line);
	}
	return (status);
}

char	*get_next_line(int fd)
{
	static char		buf[GNL_BUFFER_SIZE];
	static ssize_t	pos;
	static ssize_t	len;
	static int		saved_fd = -1;
	t_line			line;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (gnl_reset(&pos, &len));
	if (saved_fd != fd)
	{
		pos = 0;
		len = 0;
		saved_fd = fd;
	}
	gnl_init(&line);
	status = gnl_fill(fd, buf, &pos, &len, &line);
	if (status < 0)
	{
		gnl_free(&line);
		return (gnl_reset(&pos, &len));
	}
	if (line.len == 0)
		return (gnl_free(&line));
	return (line.str);
}
