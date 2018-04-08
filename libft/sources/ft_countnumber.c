/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:10:25 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 17:10:26 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countnumber(int n)
{
	int				number;
	unsigned int	ui;

	number = 1;
	if (n < 0)
		number++;
	ui = (n < 0) ? -n : n;
	while (ui > 9)
	{
		number++;
		ui /= 10;
	}
	return (number);
}
