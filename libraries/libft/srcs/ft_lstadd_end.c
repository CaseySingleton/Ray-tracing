/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:31:20 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/30 19:31:40 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_end(t_list **alst, t_list *new_node)
{
	t_list		*temp;

	if (*alst == NULL)
	{
		*alst = new_node;
		return ;
	}
	temp = *alst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}
