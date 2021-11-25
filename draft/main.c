#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

size_t    ft_strlen(const char *s)
{
    size_t    i;

    i = -1;
    while (s[++i])
        ;
    return (i);
}


char    *ft_strdup(const char *s1)
{
    char    *str;
    size_t    len;
    size_t    i;

    str = (char *)s1;
    len = ft_strlen(s1);
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


size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t    s_len;
    int        dst_s;
    int        i;

    s_len = ft_strlen(src);
    dst_s = (int)dstsize;
    i = 0;
    if (dst_s)
    {
        while (src[i] && --dst_s)
        {
            *dst++ = src[i++];
        }
        *dst = '\0';
    }
    return (s_len);
}


char    *skip(char *s, char c)
{
    while (*s == c)
        s++;
    return (s);
}

char    **ft_special(char **tab, char *s, char c)
{
    if (*s == '\0' && c == 0) 
        {
            tab = (char **)malloc(sizeof(char *));
            if(!tab)
                return(NULL);
            tab[0] = NULL;
            return (tab);
        }
    else if (c == 0)
        {
            tab = (char **)malloc(sizeof(char *) * 2);
            tab[0] = ft_strdup(s);
            if(!tab)
                return(NULL);
            tab[1] = NULL;
            return (tab);
        }
    if (!tab)
        return (NULL);
    return (tab);
}

int        T_count(char *s, char c)
{
    int    i;

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

int        C_count(char *tab, char *s, char c)
{
    int    i;

    i = -1;
    while (s[++i] != c && s[i]) // if *s == c <=> break loop and return i
        ;
    tab = (char *)malloc(sizeof(char) * i + 1); // allocate single tab
    ft_strlcpy(tab, (char *)s,i + 1); // cpy the first tab
    return (i);
}

char    **ft_split(char const *s, char c)
{
    char    **tab;
    int     index;
	int		i;
    
    if(s)
    {
        s = skip((char *)s , c);
        tab = ft_special(tab, (char *)s, c);
        tab = (char **)malloc(sizeof(char *) * T_count((char *)s, c));
        tab = ft_special(tab, (char *)s, c);
        while (*s)
        {
            index = 0;
            i = C_count(tab[index], (char *)s, c);
            s += i;
            s = skip((char *)s , c);
            index++;
        }
        tab[index] = NULL; // the final tab == NULL;
        return (tab);
    }
    return(NULL);
}

int   main()
{
  char **t = ft_split("  tripouelle 42  ", ' ');
  int i = 0;
  
  while (t[i])
  {
    printf("%s\n", t[i]);
    i++;
  }
  return (0);
 }