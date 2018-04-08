/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:59:05 by dlavaury          #+#    #+#             */
/*   Updated: 2018/03/31 19:15:36 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_init_printf(t_data *data, const char *s)
{
	ft_bzero(data, sizeof(*data));
	data->ft = (char*)s;
	if (!(data->str = malloc(sizeof(char))))
		return (0);
	*data->str = '\0';
	return (1);
}

int				ft_sprintf(char **str, const char *format, ...)
{
	t_data		data;

	if (!ft_init_printf(&data, format))
		return (-1);
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
	!ft_join_clr(&data) ? data.error = -1 : 0;
	*str = data.str;
	va_end(data.ap);
	return (data.error == -1 ? -1 : data.len);
}
