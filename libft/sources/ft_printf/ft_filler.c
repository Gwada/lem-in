/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:52:03 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/12 09:52:05 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_filler(t_data *data, char opt)
{
	if (data->filler <= 0)
		return ;
	data->car = ' ' | (data->bd & ZERO);
	if (!opt && !(data->bd & NEG))
		while (data->filler--)
			ft_buffering(data, &data->car, 1);
	else if (opt && data->bd & NEG)
		while (data->filler--)
			ft_buffering(data, &data->car, 1);
}
