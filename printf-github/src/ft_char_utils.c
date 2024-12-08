/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:27:00 by houabell          #+#    #+#             */
/*   Updated: 2024/12/01 14:46:38 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_char(t_data *data, int c)
{
	int		width;
	char	pad_char;

	width = data->format.width_value;
	if (data->format.zero_pad && !data->format.left_justified)
		pad_char = '0';
	else
		pad_char = ' ';
	if (width > 1)
	{
		if (data->format.left_justified)
		{
			put_in_buff_n_time((char)c, 1, data);
			put_in_buff_n_time(' ', width - 1, data);
		}
		else
		{
			put_in_buff_n_time(pad_char, width - 1, data);
			put_in_buff_n_time((char)c, 1, data);
		}
	}
	else
		put_in_buff_n_time((char)c, 1, data);
}

static void	handle_null_string(t_data *data, const char **str, int *str_len)
{
	(void) data;
	if (*str == NULL)
	{
		*str = "(null)";
		*str_len = ft_strlen(*str);
	}
}

static int	calculate_precision(t_data *data, int str_len)
{
	if (data->format.precision_value >= 0)
	{
		if (data->format.precision_value < str_len)
			return (data->format.precision_value);
		else
			return (str_len);
	}
	return (str_len);
}

static int	calculate_padding(t_data *data, int precision)
{
	if (data->format.width_value > precision)
		return (data->format.width_value - precision);
	return (0);
}

void	print_str(t_data *data, const char *str)
{
	int		str_len;

	if (str != NULL)
		str_len = ft_strlen(str);
	else
		str_len = 0;
	handle_null_string(data, &str, &str_len);
	data->format.pr = calculate_precision(data, str_len);
	data->format.pd = calculate_padding(data, data->format.pr);
	if (data->format.zero_pad)
		data->format.pad_char = '0';
	else
		data->format.pad_char = ' ';
	if_conditions(data, str);
}
