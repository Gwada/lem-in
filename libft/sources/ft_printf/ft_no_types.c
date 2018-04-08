/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:52:27 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/12 09:52:30 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_types(t_data *data)
{
	if ((data->filler = data->min_s - 1) > 0)
		ft_filler(data, 0);
	ft_buffering(data, data->ft, 1);
	if (data->filler > 0)
		ft_filler(data, 1);
}
