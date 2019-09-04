/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 21:57:40 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/23 21:57:42 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*current;
	t_list		*next;

	current = *alst;
	while (current)
	{
		next = current->next;
		(*del)(current->content, current->content_size);
		free(current);
		current = next;
	}
	(*alst) = NULL;
}
