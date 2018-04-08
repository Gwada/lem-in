/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:19:57 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/09 10:19:59 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int maj;

	i = 0;
	maj = 1;
	while (str[i] != '\0')
	{
		if (maj == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= ' ';
			maj = 0;
		}
		else if (maj == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ' ';
		else if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
				|| (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			maj = 1;
		else if (maj == 1 && ((str[i] >= 'A' && str[i] <= 'Z')
					|| (str[i] >= '0' && str[i] <= '9')))
			maj = 0;
		i++;
	}
	return (str);
}
