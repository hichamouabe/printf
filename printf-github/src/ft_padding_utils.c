/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:29:54 by houabell          #+#    #+#             */
/*   Updated: 2024/12/01 12:08:01 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	set_padding_spaces(t_data *data)
{
	data->format.padding_spaces = data->format.width_value
		- data->format.padding_zeros - data->format.nbr_len;
	if (ft_strchr("uxXp", data->format.specifier))
	{
		if ((ft_strchr("xX", data->format.specifier) && data->format.hash
				&& data->format.buf_tmp[0] != '0')
			|| data->format.specifier == 'p')
			data->format.padding_spaces -= 2;
		return ;
	}
	if (data->format.is_negative || (!data->format.is_negative
			&& (data->format.plus || data->format.space)))
		data->format.padding_spaces--;
}

static int	calc_padding_for_precision(t_data *data)
{
	if (data->format.precision_value >= 0
		&& data->format.precision_value > data->format.nbr_len)
		return (data->format.precision_value - data->format.nbr_len);
	return (0);
}

static int	calc_zero_padding(t_data *data)
{
	int	padding;

	padding = 0;
	if (data->format.zero_pad && !data->format.left_justified)
	{
		if (data->format.width_value > data->format.nbr_len)
			padding = data->format.width_value - data->format.nbr_len;
		if (data->format.specifier == 'u')
			return (padding);
		else if ((ft_strchr("xX", data->format.specifier)
				&& data->format.hash && data->format.buf_tmp[0] != '0')
			|| data->format.specifier == 'p')
			padding -= 2;
		if (data->format.is_negative || (!data->format.is_negative
				&& (data->format.plus || data->format.space)))
			padding--;
	}
	return (padding);
}

void	set_padding_zeros(t_data *data)
{
	int	padding_zeros;

	if (data->format.precision_value >= 0)
	{
		data->format.padding_zeros = calc_padding_for_precision(data);
		return ;
	}
	padding_zeros = calc_padding_for_precision(data);
	padding_zeros += calc_zero_padding(data);
	if (padding_zeros < 0)
		padding_zeros = 0;
	data->format.padding_zeros = padding_zeros;
}
