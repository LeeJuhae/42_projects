/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:33:56 by ijuhae            #+#    #+#             */
/*   Updated: 2020/04/13 16:39:02 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		set_line(char **line, char **content)
{
	char *tmp;

	tmp = *line;
	if (tmp == 0)
		*line = ft_strdup(*content);
	else
		*line = ft_strjoin(tmp, *content);
	free(tmp);
	if (*line == 0)
		return (-1);
	return (1);
}

int		get_content(int fd, char **buf, char **stack_fd, char **line)
{
	int	ret;

	ret = 1;
	if (*stack_fd == 0)
	{
		*buf = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (*buf == 0)
			return (-1);
		ret = read(fd, *buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(*line);
			*line = 0;
		}
	}
	else
	{
		*buf = ft_strdup(*stack_fd);
		free(*stack_fd);
	}
	return (ret);
}

void	set_rest(char **rest, char **buf)
{
	*rest = *buf;
	while (**rest != '\n')
		(*rest)++;
	**rest = '\0';
	(*rest)++;
}

int		get_next_line(int fd, char **line)
{
	static	char	*stack[OPEN_MAX];
	int				ret;
	char			*buf;
	char			*rest;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
			!(*line = (char *)ft_calloc(1, 1)))
		return (-1);
	while ((ret = get_content(fd, &buf, &stack[fd], line)) > 0)
	{
		if (ft_strchr(buf, '\n') != 0)
		{
			set_rest(&rest, &buf);
			stack[fd] = ft_strdup(rest);
			ret = set_line(line, &buf);
			break ;
		}
		stack[fd] = 0;
		if (set_line(line, &buf) == -1)
			break ;
		free(buf);
	}
	free(buf);
	return (ret);
}
