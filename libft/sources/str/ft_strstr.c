/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:34:00 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 16:34:23 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*haystack && *needle)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)))
			return (ft_strstr(haystack + 1, needle));
		else
			return ((char*)haystack);
	}
	return ((*needle) ? NULL : (char*)haystack);
}
