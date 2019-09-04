/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:40:25 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/08 15:06:48 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_head;
	t_list		*temp_list;

	if (lst == NULL)
		return (0);
	if (!(new_head = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_head = (*f)(lst);
	temp_list = new_head;
	while (lst->next)
	{
		lst = lst->next;
		temp_list->next = (*f)(lst);
		temp_list = temp_list->next;
	}
	return (new_head);
}
