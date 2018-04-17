/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:33:41 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/17 18:45:32 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_join_clr(t_data *data)
{
	int		i;
	int		strlen;
	int		buflen;
	char	*new;

	i = -1;
	strlen = 0;
	buflen = 0;
	while (data->str[strlen])
		++strlen;
	while (data->buf[buflen])
		++buflen;
	if (!(new = malloc(sizeof(char) * (strlen + buflen + 1))))
		return (0);
	while (++i < strlen)
		new[i] = data->str[i];
	buflen = 0;
	while (data->buf[buflen])
		new[i++] = data->buf[buflen++];
	free(data->str);
	data->str = new;
	return (1);
}

void		ft_buffering(t_data *data, const void *s, int len)
{
	int		i;
	char	*src;

	i = -1;
	src = (char*)s;
	while (++i - len)
	{
		if (data->i_b == BUFF_SIZE)
		{
			if (!data->str)
				write(data->fd, data->buf, BUFF_SIZE);
			else if (data->str && !ft_join_clr(data))
			{
				data->error = -1;
				return ;
			}
			ft_bzero(data->buf, BUFF_SIZE);
			data->i_b = 0;
		}
		data->buf[data->i_b++] = src[i];
		data->len++;
	}
}

void		ft_error(t_data *data, int to_remove)
{
	data->error = -1;
	while (to_remove-- && data->i_b)
	{
		data->buf[data->i_b--] = '\0';
		data->i--;
	}
	data->len = -1;
}
