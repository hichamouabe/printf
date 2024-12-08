/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:31:15 by houabell          #+#    #+#             */
/*   Updated: 2024/11/30 20:50:50 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# define BUF_SIZE 4096
# define FLAGS "-0.# +"
# define NUMBERS "0123456789"
# define SPECIFIER "cspdiuxX%"
# define LOW_BASE_16 "0123456789abcdef"
# define UP_BASE_16 "0123456789ABCDEF"

typedef enum e_base
{
	BASE_10 = 10,
	BASE_16 = 16,
}	t_base;

typedef union u_t_union_ints
{
	unsigned long	uint;
	long			just_int;
}	t_union_ints;

typedef struct s_format
{
	bool	left_justified;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero_pad;
	char	specifier;
	int		width_value;
	char	buf_tmp[64];
	int		pr;
	int		pd;
	char	pad_char;
	int		nbr_len;
	int		precision_value;
	bool	signed_value;
	bool	is_negative;
	bool	is_converted;
	int		padding_spaces;
	int		padding_zeros;
	t_base	base;
	bool	upper_case;
	bool	lower_case;
}	t_format;

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	char		*buf;
	int			buf_index;
	t_format	format;
}	t_data;

int		ft_printf(const char *format, ...);
int		parse_format(t_data *data);
void	print_char(t_data *data, int c);
void	print_str(t_data *data, const char *str);
void	print_nums(t_data *data, t_union_ints int_values);
void	handle_number_format(t_data *data, t_union_ints *int_values);
void	itoa_buf(t_data *data, t_union_ints int_value);
void	flush_buff(t_data *data);
void	put_in_buf(t_data *data, char c);
void	put_in_buff_n_time(char c, int precision, t_data *data);
void	put_s_in_buff_n_time(const char *s, int length, t_data *data);
void	set_padding_spaces(t_data *data);
void	set_padding_zeros(t_data *data);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(t_data *data);
void	*ft_bzero(void *b, size_t len);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	if_conditions(t_data *data, const char *str);
#endif
