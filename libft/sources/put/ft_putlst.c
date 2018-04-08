/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:51:52 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 16:51:58 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst, void (*f)(char const *))
{
	if (!lst)
		return ;
	if (lst->content)
		f(lst->content);
	if (lst->next)
		ft_putlst(lst->next, f);
}
