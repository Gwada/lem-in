/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileaddone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:56:23 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 16:56:37 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_pileaddone(t_list *lst)
{
	t_list	*new;

	if (!(new = ft_lstnew(NULL, 0)))
		return (NULL);
	new->next = lst;
	return (new);
}
