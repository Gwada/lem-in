/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:57:50 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 13:41:19 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*sdest;
	char	*ssrc;
	size_t	i;

	i = -1;
	sdest = (char*)dest;
	ssrc = (char*)src;
	if (ssrc < sdest)
		while ((int)(--n) >= 0)
			*(sdest + n) = *(ssrc + n);
	else
		while (++i < n)
			*(sdest + i) = *(ssrc + i);
	return (dest);
}
