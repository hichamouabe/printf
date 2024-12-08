/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:21:40 by houabell          #+#    #+#             */
/*   Updated: 2024/12/01 15:34:19 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	parse_flag(t_data *data)
{
	char	flag;

	while (ft_strchr(FLAGS, *data->s) && (*data->s != '.'))
	{
		flag = *data->s;
		if (flag == '0')
			data->format.zero_pad = 1;
		else if (flag == '+')
			data->format.plus = 1;
		else if (flag == ' ')
			data->format.space = 1;
		else if (flag == '#')
			data->format.hash = 1;
		else if (flag == '-')
			data->format.left_justified = 1;
		++data->s;
	}
}

static void	fetch_wp(t_data *data, int *value)
{
	if (ft_strchr(NUMBERS, *data->s))
		*value = ft_atoi(data);
}

int	parse_format(t_data *data)
{
	ft_bzero(&(data->format), sizeof(t_format));
	data->format.precision_value = -1;
	parse_flag(data);
	fetch_wp(data, &data->format.width_value);
	if (*data->s == '.' && *(++data->s))
	{
		data->format.precision_value = 0;
		fetch_wp(data, &data->format.precision_value);
	}
	if (!ft_strchr(SPECIFIER, *data->s))
		return (-1);
	data->format.specifier = *data->s;
	return (data->format.specifier);
}
