#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*retour(char *save);
char	*cut_start(char *s, int ret);
int		chr_is_in_str(char *s, char chr);

#endif
