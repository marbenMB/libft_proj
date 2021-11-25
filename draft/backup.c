/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:38:04 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/23 15:38:23 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int		T_count(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && s[1] == c) // if s[0] != c && s[1] == c <=> i++
			i++;
		s++;
	}
	if (*(s - 1) != c) // if there is no separator before \0 then i++
		i++;
	return (i + 1);
}

int		C_count(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] != c && s[i]) // if *s == c <=> break loop and return i
		;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_tab;
	int		nb_char;
	int		index;

	if (s)
	{
		if (*s == '\0')
		 	return (calloc(1,1));
		while (*s == c)
			s++;
		nb_tab = T_count((char *)s, c); // how many tab will be allocated
		tab = (char **)malloc(sizeof(char *) * nb_tab); // tabs allocation
		index = 0; //intialization of the index
		while (*s && index < nb_tab - 1)
		{
			nb_char = C_count((char *)s, c); // how many word in single tab
			tab[index] = (char *)malloc(sizeof(char) * nb_char + 1); // allocate single tab
			strlcpy(tab[index], (char *)s, nb_char + 1); // cpy the first tab
			s += nb_char; // s incrementation
			while (*s == c) // skiping separators
				s++;
			index++; // index incrementation
		}
		tab[index] = NULL; // the final tab == NULL;
		return (tab);
	}
	return(NULL);
}

int main()
{
    char *s = "hello , yes i am , here ,, no but l,, just , iam here,,,,,,,,,,,,,,,,";
	char c = ',';

    char **tab = ft_split(s, c);
    printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
	printf("%s\n", tab[5]);
	printf("%s\n", tab[6]);
	//printf("%s\n", tab[7]);
    return (0);
}