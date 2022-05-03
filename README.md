# libft_proj
This project is about coding a C library.
It will contain a lot of general purpose functions your programs will rely upon.

## Funcitons : 
#### Mandatory :
• isalpha		• isdigit
• isalnum		• isascii
• isprint
• toupper		• tolower
• bzero			• memset
• memcpy		• memmove
• memchr		• memcmp
• strlen		• strlcpy
• strlcat		• strnstr
• strrchr		• strncmp
• strchr
• atoi
• ft_calloc		• ft_strdup
• ft_substr		• ft_strjoin
• ft_split		• ft_strtrim
• ft_strmapi		• ft_itoa
• ft_striteri		• ft_putchar_fd
• ft_putstr_fd		• ft_putendl_fd
• ft_putnbr_fd
#### Bonus :
• ft_lstnew		• ft_lstadd_front
• ft_lstlast		• ft_lstsize
• ft_lstdelone		• ft_lstadd_back
• ft_lstiter		• ft_lstclear
• ft_lstmap

## How to use :

run :
	- make
![making](images/Screen%20Shot%202022-05-03%20at%2014.10.20.png)
in terminal to make the mandatory part or :
	- make bonus
![making_bonus](images/Screen%20Shot%202022-05-03%20at%2014.10.47.png)
to make both mandatory and bonus parts at the same time.

In your program include the libft header :
	- #include "libft.h"
and compile your program adding the library :
	- gcc program.c libft.a

## Clean the object or clean all :
clean only objects :
	- make clean
clean all :
	- make fclean