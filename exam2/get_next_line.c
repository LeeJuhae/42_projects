#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc(int count, int size)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = malloc(size * count)))
		return (0);
	while (i < count)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

int	ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_strjoin(char *str, char c)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	new = ft_calloc(len + 1 + 1, sizeof(char));
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	if (str)
		free(str);
	return (new);
}

char	*ft_substr(char *str, int begin, int len)
{
	char	*p;
	int		i;

	i = 0;
	p = ft_calloc(len + 1, 1);
	while (str[begin] && i < len)
	{
		p[i] = str[begin + i];
		++i;
	}
	return (p);
}

int			get_next_line(char **line)
{
	static char	*rest;
	char		buf;
	int			pos;
	char		*temp;

	if (!line || (!rest && !(rest = ft_calloc(1, 1))))
		return (-1);
	while (read(0, &buf, 1) > 0)
	{
		rest = ft_strjoin(rest, buf);
		if (buf == '\n')
			break ;
	}
	if ((pos = ft_strchr(rest, '\n')) >= 0)
	{
		*line = ft_substr(rest, 0, pos);
		temp = rest;
		rest = ft_substr(rest, pos + 1, ft_strchr(rest, '\0'));
		free(temp);
		return (1);
	}
	*line = rest;
	return (0);
}

