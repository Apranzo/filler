/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 08:42:14 by cshinoha          #+#    #+#             */
/*   Updated: 2019/05/25 18:57:45 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl_fd( int fd, char const *s)
{
	if (s)
		ft_putstr_fd(fd, s);
	ft_putstr_fd(fd, "\n");
}
