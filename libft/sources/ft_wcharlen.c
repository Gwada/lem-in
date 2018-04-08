/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:22:53 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/13 18:24:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t c)
{
	if (c >= 0)
	{
		if ((c < 0x80 && MB_CUR_MAX > 0) || (c < 0x100 && MB_CUR_MAX == 1))
			return (1);
		else if (c > 0x7f && c < 0x800 && MB_CUR_MAX > 1)
			return (2);
		else if (MB_CUR_MAX > 2
		&& ((c >= 0x800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF)))
			return (3);
		else if (c > 0x10000 && c <= 0x10FFFF && MB_CUR_MAX > 3)
			return (4);
	}
	return (0);
}
