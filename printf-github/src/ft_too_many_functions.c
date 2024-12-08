/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_too_many_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:59:29 by houabell          #+#    #+#             */
/*   Updated: 2024/12/01 15:08:23 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	if_conditions(t_data *data, const char *str)
{
	if (data->format.left_justified)
	{
		put_s_in_buff_n_time(str, data->format.pr, data);
		put_in_buff_n_time(' ', data->format.pd, data);
	}
	else
	{
		put_in_buff_n_time(data->format.pad_char, data->format.pd, data);
		put_s_in_buff_n_time(str, data->format.pr, data);
	}
}

void	flush_buff(t_data *data)
{
	data->chars_written += write(1, data->buf, data->buf_index);
	ft_bzero(data->buf, BUF_SIZE);
	data->buf_index = 0;
}

void	itoa_buf(t_data *data, t_union_ints int_value)
{
	t_union_ints	tmp;
	char			c;

	if (data->format.is_negative && !data->format.is_converted)
	{
		int_value.just_int = -(int_value.just_int);
		data->format.is_converted = 1;
		itoa_buf(data, int_value);
	}
	else if (int_value.uint < data->format.base)
	{
		if (data->format.upper_case)
			c = UP_BASE_16[int_value.uint];
		else
			c = LOW_BASE_16[int_value.uint];
		data->format.buf_tmp[data->format.nbr_len++] = c;
	}
	else
	{
		tmp.uint = int_value.uint / data->format.base;
		itoa_buf(data, tmp);
		tmp.uint = int_value.uint % data->format.base;
		itoa_buf(data, tmp);
	}
}
