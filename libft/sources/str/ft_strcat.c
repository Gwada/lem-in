/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:47:29 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 16:48:19 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t len;

	i = -1;
	len = ft_strlen(dest);
	while (src[++i])
		*(dest + len + i) = src[i];
	*(dest + len + i) = '\0';
	return (dest);
}
