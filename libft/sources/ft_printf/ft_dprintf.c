/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:46:10 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/31 19:15:58 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_printf(t_data *data, const char *s, int fd)
{
	ft_bzero(data, sizeof(*data));
	data->ft = (char*)s;
	data->fd = fd;
	data->str = NULL;
}

int				ft_dprintf(int fd, const char *format, ...)
{
	t_data		data;

	ft_init_printf(&data, format, fd);
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
