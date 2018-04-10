/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:48:45 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/10 17:31:59 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		remove_arg(t_list *lst)
{
	if (!lst)
		return ;
	remove_arg(lst->next);
	if (lst->content)
		free(lst->content);
	if (lst)
		free(lst);
}

void		print_arg(t_list *lst)
{
	if (!lst)
		return ;
	print_arg(lst->next);
	ft_printf("%s\n", lst->content);
	if (lst->content)
		free(lst->content);
	if (lst)
		free(lst);
}
