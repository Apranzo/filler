/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:03:13 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/08 20:11:11 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstrss(char **ar, int c)
{
	ft_putstrss_fd(ar, c, 1);
}

void	ft_putstrss_fd(char **ar, int c, int fd)
{
	if (c < 0)
		c = '\n';
	while (*ar)
	{
		ft_putstr_fd(*ar, fd);
		ft_putchar_fd(c, fd);
		ar++;
	}
}
