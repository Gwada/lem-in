/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:08:44 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/09 22:02:52 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int					i;
	int					num;
	int					pos_num;
	unsigned long long	max;

	i = 0;
	max = 0;
	num = 0;
	pos_num = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			pos_num = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		max = max * 10 + nptr[i] - '0';
		if (max > INTMAXLEN)
			return ((pos_num == 1) ? -1 : 0);
		num = num * 10 + nptr[i++] - '0';
	}
	return (num * pos_num);
}
