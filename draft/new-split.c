#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	str = (char *)s1;
	len = strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (i < len && *s1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


// int	ft_t_count(char *s, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (*s)
// 	{
// 		if (*s != c && s[1] == c)
// 			i++;
// 		s++;
// 	}
// 	if (*(s - 1) != c)
// 		i++;
// 	return (i + 1);
// }

// int	ft_c_count(char *s, char c)
// {
// 	int	i;

// 	i = -1;
// 	while (s[++i] != c && s[i])
// 		;
// 	return (i++);
// }

// char	*ft_fill(char *s, char c)
// {
// 	char	*str;
// 	int		nb_char;

// 	nb_char = ft_c_count((char *)s, c);
// 	str = (char *)malloc(sizeof(char) * (ft_c_count((char *)s, c)));
// 	strlcpy(str, (char *)s, nb_char + 1);
// 	return (str);
// }

// char	**ft_special(char *s, char c)
// {
// 	char	**tab;

// 	if (*s == '\0' && c == 0)
// 		{
// 			tab = (char **)malloc(sizeof(char *));
// 			if (!tab)
// 				return (NULL);
// 			tab[0] = NULL;
// 			return (tab);
// 		}
// 		else if (c == 0)
// 		{
// 			tab = (char **)malloc(sizeof(char *) * 2);
// 			tab[0] = ft_strdup(s);
// 			if (!tab)
// 				return (NULL);
// 			tab[1] = NULL;
// 			return (tab);
// 		}
// 		return (tab);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	int		nb_tab;
// 	int		nb_char;
// 	int		i;

// 	if (s)
// 	{
// 		if ((*s == '\0' && c == 0) || c == 0)
// 		{
// 			tab = ft_special((char *)s ,c);
// 			return (tab);
// 		}
// 		while (*s == c)
// 			s++;
// 		nb_tab = ft_t_count((char *)s, c);
// 		tab = (char **)malloc(sizeof(char *) * ft_t_count((char *)s, c));
// 		if (!tab)
// 			return (NULL);
// 		i = 0;
// 		while (*s && i < nb_tab - 1)
// 		{
// 			tab[i] = ft_fill((char *)s, c);
// 			s += strlen(tab[i]);
// 			while (*s == c)
// 				s++;
// 			i++;
// 		}
// 		tab[i] = NULL;
// 		return (tab);
// 	}
// 	return (NULL);
// }

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
	strlcpy(str, (char *)s, nb_char + 1);
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
	int		index;

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
	index = 0;
    while (*s)
    {
        tab[index] = ft_fill((char *)s, c);
		s += strlen(tab[index]);
		while (*s == c)
			s++;
		index++;
    }
    tab[index] = NULL;
	return (tab);
}
int main()
{
    char *s = "      split       this for   me  !       ";
	char c = ' ';

    char **tab = ft_split(s, c);
    printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
	printf("%s\n", tab[5]);
	// printf("%s\n", tab[6]);
	//printf("%s\n", tab[7]);
    return (0);
}




/* ------------------------------------------------------------------------------

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
	strlcpy(str, (char *)s, nb_char + 1);
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
	int		index;

    if (!s)
        return (NULL);
    if ((*s == '\0' && c == 0) || c == 0)
	{
		tab = ft_special((char *)s ,c);
		if (!tab)
			return (NULL);
		return (tab);
	}
    while (*s == c)
        s++;
	tab = ft_t_count((char *)s, c);
	index = 0;
    while (*s)
    {
        tab[index] = ft_fill((char *)s, c);
		s += strlen(tab[index]);
		while (*s == c)
			s++;
		index++;
    }
    tab[index] = NULL;
	return (tab);
}


------------------------------------------------------------------------------ */
