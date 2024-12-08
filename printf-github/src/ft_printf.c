/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:19:33 by houabell          #+#    #+#             */
/*   Updated: 2024/12/01 12:48:26 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	render_format(t_data *data)
{
	char			spec;
	t_union_ints	int_values;

	int_values.just_int = 0;
	spec = data->format.specifier;
	if (spec == '%')
		print_char(data, '%');
	else if (spec == 'c')
		print_char(data, va_arg(data->ap, int));
	else if (spec == 's')
		print_str(data, va_arg(data->ap, char *));
	else if (ft_strchr("dixXpu", spec))
		handle_number_format(data, &int_values);
	return ;
}

static int	init_data(t_data *data, const char *format)
{
	data->chars_written = 0;
	data->s = format;
	data->buf = ft_calloc(BUF_SIZE, sizeof(char));
	if (data->buf == NULL)
		return (-1);
	data->buf_index = 0;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data, format) == -1)
		return (-1);
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
		{
			if (!parse_format(&data))
				return (-1);
			render_format(&data);
		}
		else
			put_in_buf(&data, *data.s);
		++data.s;
	}
	flush_buff(&data);
	va_end(data.ap);
	free(data.buf);
	return (data.chars_written);
}
