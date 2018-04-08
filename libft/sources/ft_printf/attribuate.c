/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribuate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:42:37 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/13 17:01:11 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_attribuate(t_data *data)
{
	data->bd = 0;
	data->prec = 1;
	data->min_s = 0;
	while (ft_strchr(".0123456789# +-*hjlqz", *data->ft))
	{
		ft_flags_parser(data);
		ft_precision_parser(data);
		ft_len_mod_parser(data);
		if (!(*data->ft))
			return ;
	}
	if (*data->ft)
	{
		data->bd & POS ? data->bd &= ~SPACE : 0;
		if (ft_strchr("BCDOSUX", *data->ft))
			data->bd |= *data->ft != 'X' ? LONG : MAJ;
		ft_put_type(data);
		++data->ft;
	}
}

int						ft_atoi_p(const char *nptr)
{
	unsigned long long	num;

	num = 0;
	while (*nptr >= '0' && *nptr <= '9')
		num = num * 10 + *(nptr++) - '0';
	return ((int)num);
}
