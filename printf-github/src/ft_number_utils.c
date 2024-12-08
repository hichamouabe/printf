/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:22:21 by houabell          #+#    #+#             */
/*   Updated: 2024/12/01 11:13:02 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	put_0x(t_data *data)
{
	if ((ft_strchr("xX", data->format.specifier) && data->format.hash
			&& data->format.buf_tmp[0] != '0') || data->format.specifier == 'p')
	{
		if (data->format.upper_case)
			put_s_in_buff_n_time("0X", 2, data);
		else
			put_s_in_buff_n_time("0x", 2, data);
	}
}

static void	put_sign(t_data *data)
{
	if (data->format.base == BASE_16)
		put_0x(data);
	if (data->format.signed_value)
	{
		if (data->format.is_negative)
			put_in_buff_n_time('-', 1, data);
		else if (data->format.plus)
			put_in_buff_n_time('+', 1, data);
		else if (data->format.space)
			put_in_buff_n_time(' ', 1, data);
	}
}

void	print_nums(t_data *data, t_union_ints int_values)
{
	itoa_buf(data, int_values);
	set_padding_zeros(data);
	set_padding_spaces(data);
	if (data->format.left_justified)
	{
		put_sign(data);
		put_in_buff_n_time('0', data->format.padding_zeros, data);
		put_s_in_buff_n_time(data->format.buf_tmp, data->format.nbr_len, data);
		put_in_buff_n_time(' ', data->format.padding_spaces, data);
	}
	else
	{
		put_in_buff_n_time(' ', data->format.padding_spaces, data);
		put_sign(data);
		put_in_buff_n_time('0', data->format.padding_zeros, data);
		put_s_in_buff_n_time(data->format.buf_tmp, data->format.nbr_len, data);
	}
}

void	handle_number_format(t_data *data, t_union_ints *int_values)
{
	if (!data->format.specifier)
		return ;
	if (ft_strchr("di", data->format.specifier))
	{
		data->format.base = BASE_10;
		int_values->just_int = (long)va_arg(data->ap, int);
		data->format.signed_value = 1;
		if (int_values->just_int < 0)
			data->format.is_negative = 1;
	}
	else if (data->format.specifier == 'p')
	{
		data->format.base = BASE_16;
		int_values->uint = (unsigned long)va_arg(data->ap, void *);
	}
	else if (ft_strchr("xXu", data->format.specifier))
	{
		if (data->format.specifier == 'X')
			data->format.upper_case = 1;
		data->format.base = BASE_16;
		int_values->uint = (unsigned long)va_arg(data->ap, unsigned int);
		if (data->format.specifier == 'u')
			data->format.base = BASE_10;
	}
	print_nums(data, *int_values);
}
