/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:32:58 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/13 14:44:50 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_fd	*ft_create_one(t_fd *current, int fd)
{
	t_fd	*new;

	if (!(new = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->ret = 0;
	ft_bzero(new->buf, BUFF_SIZE + 1);
	if (current && fd < current->fd)
	{
		new->previous = current->previous ? current->previous : NULL;
		if (current->previous)
			current->previous->next = new;
		new->next = current;
		current->previous = new;
	}
	else if (current && fd > current->fd)
	{
		new->next = current->next ? current->next : NULL;
		if (current->next)
			current->next->previous = new;
		new->previous = current;
		current->next = new;
	}
	return (new);
}

static	t_fd	*ft_del_one(t_fd *current)
{
	if (current && !current->previous && !current->next)
	{
		free(current);
		current = NULL;
	}
	else if (current && !current->previous && current->next)
	{
		current = current->next;
		free(current->previous);
		current->previous = NULL;
	}
	else if (current && current->previous && !current->next)
	{
		current = current->previous;
		free(current->next);
		current->next = NULL;
	}
	else if (current && current->previous && current->next)
	{
		current->next->previous = current->previous;
		current = current->next;
		free(current->previous->next);
		current->previous->next = current;
	}
	return (current);
}

static	t_fd	*ft_find(t_fd *current, int fd)
{
	if (!current)
	{
		if (!(current = ft_create_one(current, fd)))
			return (NULL);
		current->previous = NULL;
		current->next = NULL;
		return (current);
	}
	if (fd > current->fd)
	{
		if (current->next && fd >= current->next->fd)
			return (ft_find(current->next, fd));
		return (ft_create_one(current, fd));
	}
	if (fd < current->fd)
	{
		if (current->previous && fd <= current->previous->fd)
			return (ft_find(current->previous, fd));
		return (ft_create_one(current, fd));
	}
	return (current);
}

static	char	*ft_make_line(t_fd *cur, char **line)
{
	char		*new;

	new = NULL;
	cur->i = 0;
	while (cur->buf[cur->i] && cur->buf[cur->i] != '\n')
		cur->i++;
	if (cur->buf[cur->i] == '\n')
		cur->nl = 1;
	if (!(new = ft_strnew(ft_strlen(*line) + cur->i)))
		return (NULL);
	ft_strcpy(new, *line);
	ft_strncat(new, cur->buf, cur->i);
	free(*line);
	if (cur->nl)
		cur->i++;
	ft_strncpy(cur->buf, &cur->buf[cur->i], BUFF_SIZE);
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*cur;

	if (fd < 0 || !line || BUFF_SIZE < 1 || !(cur = ft_find(cur, fd)))
		return (-1);
	cur->nl = 0;
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (!cur->nl)
	{
		if (!*cur->buf && ((cur->ret = read(fd, cur->buf, BUFF_SIZE)) == -1))
			return (-1);
		if (!(*line = ft_make_line(cur, line)))
			return (-1);
		if (cur->ret < BUFF_SIZE)
		{
			if (**line)
				return (1);
			if (!cur->ret && !*cur->buf && !*line)
				ft_del_one(cur);
			return (cur->ret ? 1 : 0);
		}
	}
	return (1);
}
