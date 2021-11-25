#include "libft.h"
#define RETURN return (NULL)
#define DETECT(str) (!str) RETURN

size_t  ft_limit(char *str, char c)
{
	size_t  i;

	i = 0;
	while (*str)
	{
		if (*str == c && str[1] != c)
			i++;
		str++;
	}
	return (i + 2);
}

size_t  ft_endstr(char *str, char c)
{
	size_t  end;

	end = 0;
	while (*str && *str != c)
	{
		end++;
		str++;
	}
	return (end);
}

char	**ft_split(char const *s, char c)
{
	char    *str;
	char    **tab;
	int     pos;

	if DETECT(s);
	str = ft_strtrim(s, &c);
	if DETECT(str);
	tab = (char **)malloc(ft_limit(str, c) * sizeof(char *));
	if DETECT(tab);
	pos = 0;
	while (*str)
	{
		tab[pos] = ft_substr(str, 0, ft_endstr(str, c));
		if DETECT(tab[pos]);
		pos++;
		free(str);
		str += ft_endstr(str, c);
		str = ft_strtrim(str, &c);
		if DETECT(str);
	}
	tab[pos] = NULL;
	free(str);
	return (tab);
}

#include <string.h>
#include <stdio.h>

 int main()
 {
 	char * * tab = ft_split("     ", ' ');
 	printf("%s\n", tab[0]);
	//  printf("%s\n", tab[1]);
	//  printf("%s\n", tab[2]);
	//  printf("%s\n", tab[3]);
	//  printf("%s\n", tab[4]);
	//  printf("%s\n", tab[5]);
 	return (0);
 }