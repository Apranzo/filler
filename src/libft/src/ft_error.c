/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:41:45 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:41:50 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		ft_error_fd(int fd, char *mes, int code)
{
	write(fd, mes, ft_strlen(mes));
	exit(code);
}

void		ft_error(char *mes, int code)
{
	ft_error_fd(2, mes, code);
}
