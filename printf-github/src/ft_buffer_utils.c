/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:28:25 by houabell          #+#    #+#             */
/*   Updated: 2024/11/30 20:59:23 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_in_buf(t_data *data, char c)
{
	if (data->buf_index == BUF_SIZE)
		flush_buff(data);
	data->buf[data->buf_index++] = c;
}

void	put_in_buff_n_time(char c, int precision, t_data *data)
{
	while (precision-- > 0)
		put_in_buf(data, c);
}

void	put_s_in_buff_n_time(const char *s, int length, t_data *data)
{
	if (!s || length <= 0)
		return ;
	while (length--)
		put_in_buf(data, *s++);
}
