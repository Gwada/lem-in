/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:37:30 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/09 10:18:08 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (!len)
		return (NULL);
	if (!*needle)
		return ((char*)haystack);
	while (haystack[++i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j] || !(needle[j])) && j + i < len)
		{
			if (!needle[++j] || (needle[j - 1] == haystack[i + j - 1]
				&& i + j - 1 == len))
				return ((char*)&haystack[i]);
			if (i + j >= len)
				return (NULL);
		}
	}
	return (NULL);
}
