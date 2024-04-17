#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2 && s2[i])
	{
		str[i + len] = s2[i];
		i++;
	}
	if (s1)
		free(s1);
	str[i + len] = 0;
	return (str);
}

int	chr_is_in_str(char *s, char chr)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == chr)
			return (1);
		i++;
	}
	return (0);
}
