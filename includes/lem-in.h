/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:56:18 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/10 19:05:21 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**		LIBRARIES
*/

# include "libft.h"
# include "ft_printf.h"

/*
**		MACCROS
*/

# define CHECK_POP		(1 << 0)
# define CHECK_NODE		(1 << 1)
# define CHECK_LINKS	(1 << 2)
# define ERROR			(1 << 28)
# define GOOD			(1 << 29)

/*
**		Structures
*/

typedef	struct			s_graph
{
	int					bd;
	unsigned int		pop;
	t_list				*lst;
}						t_graph;

/*
**		PROTOTYPES
*/

int						parse_file(t_graph *g, char *s);
void					print_arg(t_list *lst);
void					remove_arg(t_list *lst);

#endif
