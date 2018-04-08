/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:09:40 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/13 15:15:53 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchri_up(const char *s, unsigned c)
{
	int	i;

	i = 0;
	while (*s && *s != (char)c && *s != (char)c + 32)
	{
		s++;
		i++;
	}
	return (((*s == (char)c) || (*s == (char)c + 32)) ? i : -1);
}
