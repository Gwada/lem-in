/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:01:30 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 13:45:43 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		new->content = NULL;
	else
	{
		if (!(new->content = (ft_strnew(content_size))))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
	}
	new->content_size = !content ? 0 : content_size;
	new->next = NULL;
	return (new);
}
