/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:11:37 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 17:17:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_filedelone(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return (NULL);
	free(lst->content);
	lst->content_size = 0;
	next = (lst->next) ? lst->next : NULL;
	lst->next = NULL;
	free(lst);
	return (next);
}
