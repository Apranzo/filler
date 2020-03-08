/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:53:57 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/29 03:53:57 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	va_start(args, format);
	len = ft_vfprintf(1, format, args);
	va_end(args);
	return (len);
}

int				ft_vfprintf(int fd, const char *format, ...)
{
	t_info		info;

	if (!format)
		return (-1);
	va_start(info.ap, format);
	initialize_buffer(fd, &info.buffer);
	while (*format)
	{
		if (buffer_full(&info.buffer) == 1)
			print_buffer(&info.buffer);
		if (*format == '%')
		{
			format++;
			parsing(&format, &info);
			if (*format == 0)
				break ;
		}
		else
			write_char(&info.buffer, *format);
		++format;
	}
	if (info.buffer.index != 0)
		print_buffer(&info.buffer);
	va_end(info.ap);
	return (info.buffer.length);
}
