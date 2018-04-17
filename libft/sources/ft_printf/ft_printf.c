/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:00 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/17 16:21:29 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_printf(t_data *data, const char *s)
{
	ft_bzero(data, sizeof(*data));
	data->ft = (char*)s;
	data->fd = 1;
	data->str = NULL;
}

int				ft_printf(const char *format, ...)
{
	t_data		data;

	ft_init_printf(&data, format);
	va_start(data.ap, format);
	while (*data.ft && data.error >= 0)
	{
		if (*data.ft == '%')
		{
			*++data.ft ? ft_attribuate(&data) : 0;
			data.i = 0;
			if (!(*data.ft) || data.error)
				break ;
		}
		*data.ft == '{' ? ft_set_color(&data, 0) : 0;
		if (!data.error && !ft_strchr("%{", *data.ft))
			ft_buffering(&data, data.ft, 1);
		!ft_strchr("%{", *data.ft) ? ++data.i : 0;
		*data.ft && !ft_strchr("%{", *data.ft) ? ++data.ft : 0;
	}
	write(data.fd, data.buf, data.i_b);
	va_end(data.ap);
	return (data.error == -1 ? -1 : data.len);
}
