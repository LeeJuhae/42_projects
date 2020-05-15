#include "get_next_line.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;

	line = 0;
	printf("buffer size : %d\n", BUFFER_SIZE);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
	//		printf("[Return: %d] Line #%d: %s", ret, ++line, buff);
			if (*buff == '\0')
				printf("enter input!");
			else
				printf("no");
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of stdin\n");
		close(fd);
	}
	return (0);
}
// binary file 확인
// int main(void)
// {
// 	char *line = 0;
// 	int ret;
// 	int fd;
// 	// fd = open("your_file_name", O_RDONLY);
// 	fd = 0;
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// 	return (0);
// }
