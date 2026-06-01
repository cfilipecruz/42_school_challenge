#include "get_next_line.h"

void	gnl_init(t_line *line)
{
	line->str = NULL;
	line->len = 0;
	line->cap = 0;
}

char	*gnl_free(t_line *line)
{
	free(line->str);
	gnl_init(line);
	return (NULL);
}

static void	gnl_copy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

static int	gnl_grow(t_line *line, size_t need)
{
	char	*new;
	size_t	cap;

	if (line->cap >= need)
		return (1);
	cap = line->cap;
	if (cap == 0)
		cap = 64;
	while (cap < need)
		cap *= 2;
	new = malloc(sizeof(char) * cap);
	if (!new)
		return (0);
	gnl_copy(new, line->str, line->len);
	free(line->str);
	line->str = new;
	line->cap = cap;
	return (1);
}

int	gnl_append(t_line *line, char *src, size_t size)
{
	size_t	i;

	if (!gnl_grow(line, line->len + size + 1))
		return (0);
	i = 0;
	while (i < size)
	{
		line->str[line->len] = src[i];
		line->len++;
		i++;
	}
	line->str[line->len] = '\0';
	return (1);
}