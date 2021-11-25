/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:34:50 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/20 19:52:35 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*now;

	if (!lst)
		return (NULL);
	now = lst;
	while (now && now -> next)
		now = now -> next;
	return (now);
}
