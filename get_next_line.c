#include "get_next_line.h"

int	cut_start_debut(char *s)
{
	int		start;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	start = i;
	if (s[i] && s[i] == '\n')
		start++;
	return (start);
}

char	*cut_start(char *s, int ret)
{
	char	*str;
	int		start;
	int		i;

	i = 0;
	if (!s || ret == 0)
	{
		free(s);
		return (NULL);
	}
	start = cut_start_debut(s);
	i = ft_strlen(s);
	str = malloc(sizeof(*str) * (i - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	free(s);
	str[i] = 0;
	return (str);
}

char	*retour(char *save)
{
	int		i;
	char	*ret;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		ret = malloc(i + 2);
	else
		ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	if (save[i] == '\n')
		ret[i + 1] = '\0';
	while (i >= 0)
	{
		ret[i] = save[i];
		i--;
	}
	return (ret);
}

char	*gnl_debut(int fd)
{
	char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof (*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			ret;
	static char	*save;
	char		*ligne;

	ret = 1;
	buf = gnl_debut(fd);
	if (!buf)
		return (NULL);
	while (ret > 0 && chr_is_in_str(save, '\n') == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = 0;
		save = ft_strjoin(save, buf);
	}
	free(buf);
	ligne = retour(save);
	save = cut_start(save, ret);
	return (ligne);
}
