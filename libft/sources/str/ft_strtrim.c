/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:30:08 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/08 14:24:13 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		beggin;
	int		end;
	int		i;
	char	*cpy;

	beggin = 0;
	if (!s)
		return (NULL);
	while (s[beggin] == '\t' || s[beggin] == ' ' || s[beggin] == '\n')
		beggin++;
	end = ft_strlen(s) - 1;
	while ((s[end] == '\n' || s[end] == ' ' || s[end] == '\t') && beggin < end)
		end--;
	if (!(cpy = ft_strnew(end - beggin + 1)))
		return (NULL);
	i = -1;
	while (++i <= end - beggin)
		cpy[i] = s[beggin + i];
	cpy[i] = '\0';
	return (cpy);
}
