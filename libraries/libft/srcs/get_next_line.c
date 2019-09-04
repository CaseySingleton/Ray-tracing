/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 13:25:45 by csinglet          #+#    #+#             */
/*   Updated: 2018/07/06 19:56:30 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>

static t_list		*get_file(int fd, t_list **lst)
{
	t_list		*cur;

	cur = *lst;
	if (!(*lst))
	{
		*lst = ft_lstnew(NULL, 0);
		(*lst)->content_size = fd;
		return (*lst);
	}
	while (cur != NULL)
	{
		if (cur->content_size == (size_t)fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew(NULL, 0);
	cur->content_size = fd;
	ft_lstadd_end(lst, cur);
	return (cur);
}

static void			extra(void **str, int offset)
{
	char	*extra;

	extra = ft_strdup(*str + offset + 1);
	free(*str);
	*str = ft_strdup(extra);
	free(extra);
	extra = NULL;
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*file;
	char			buff[BUFF_SIZE + 1];
	int				bytes;

	ft_bzero(buff, BUFF_SIZE + 1);
	file = get_file(fd, &lst);
	if ((!file->content && !(file->content = ft_strdup(""))) || fd < 0)
		return (-1);
	while (ft_strchr(file->content, '\n') == NULL &&
	(bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		file->content = ft_realloc_str(file->content, BUFF_SIZE);
		if (!(file->content = ft_strcat(file->content, buff)))
			return (-1);
	}
	if ((bytes < BUFF_SIZE && !ft_strlen(file->content)) || bytes == -1)
		return (bytes == -1 ? -1 : 0);
	bytes = ft_copy_until(line, file->content, '\n');
	if (bytes < (int)ft_strlen(file->content))
		extra(&file->content, bytes);
	else
		ft_strclr(file->content);
	return (1);
}
