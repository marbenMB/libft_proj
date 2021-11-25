#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char	**ft_t_count(char *s, char c)
{
	char	**tab;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && s[1] == c)
			i++;
		s++;
	}
	if (*(s - 1) != c)
		i++;
	tab = (char **)malloc(sizeof(char *) * i++);
	if (!tab)
		return (NULL);
	return (tab);
}

int ft_c_count(char *s, char c)
{
    int	i;

	i = -1;
	while (s[++i] != c && s[i])
		;
	return (i++);
}

char	*ft_fill(char *s, char c)
{
	char	*str;
	int		nb_char;

	nb_char = ft_c_count((char *)s, c);
	str = (char *)malloc(sizeof(char) * nb_char + 1);
	ft_strlcpy(str, (char *)s, nb_char + 1);
	return (str);
}

char	**ft_special(char *s, char c)
{
	char	**tab;

	if (*s == '\0' && c == 0)
		{
			tab = (char **)malloc(sizeof(char *));
			if (!tab)
				return (NULL);
			tab[0] = NULL;
			return (tab);
		}
		else if (c == 0)
		{
			tab = (char **)malloc(sizeof(char *) * 2);
			tab[0] = ft_strdup(s);
			if (!tab)
				return (NULL);
			tab[1] = NULL;
			return (tab);
		}
		return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

    if (!s)
        return (NULL);
    if ((*s == '\0' && c == 0) || c == 0)
	{
		tab = ft_special((char *)s ,c);
		return (tab);
	}
    while (*s == c)
        s++;
	tab = ft_t_count((char *)s, c);
    while ((*tab) && *s)
    {
        *tab = ft_fill((char *)s, c);
		s += ft_strlen(*tab);
		while (*s == c)
			s++;
		*tab++;
    }
    **tab = NULL;
	return (tab);
}