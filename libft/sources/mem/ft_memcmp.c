/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:58:18 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 15:42:39 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*us1;
	char	*us2;
	size_t	i;

	us1 = (char*)s1;
	us2 = (char*)s2;
	i = -1;
	while (++i < n)
		if (us1[i] != us2[i])
			return ((unsigned char)us1[i] - (unsigned char)us2[i]);
	return (0);
}
