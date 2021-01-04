#include "get_next_line.h"

int main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
		line = NULL;
	}
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
	free(line);
	line = NULL;
}
