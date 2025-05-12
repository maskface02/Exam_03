#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

char	*get_next_line(int fd)
{
	char	*res;
	char	readed;
	int		readed_bytes;
	int		i;

	i = 0;
	res = malloc(BUFFER_SIZE + 1);
	if (!res)
		return (NULL);
	while (1)
	{
		readed_bytes = read(fd, &readed, 1);
		if (readed_bytes == -1)
			return (free(res), NULL);
		if (!readed_bytes)
			break ;
		res[i++] = readed;
		if (readed == '\n')
			break ;
	}
	res[i] = '\0';
	if (!i)
		return (free(res), NULL);
	return (res);
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	if (ac > 2 || ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}
