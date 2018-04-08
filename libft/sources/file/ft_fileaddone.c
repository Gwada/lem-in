/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileaddone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:09:53 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 17:09:57 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_fileaddone(t_list *lst)
{
	if (!lst)
		return (ft_lstnew(NULL, 0));
	if (!lst->next)
		return (ft_lstnew(NULL, 0));
	return (ft_fileaddone(lst->next));
}
