/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:34:01 by cshinoha          #+#    #+#             */
/*   Updated: 2019/04/27 16:18:48 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void *area;

	area = malloc(size);
	if (area)
		ft_bzero(area, size);
	return (area);
}

void	*ft_tmemalloc(size_t type_size, size_t amount)
{
	void *area;

	area = malloc(type_size * amount);
	if (area)
		ft_bzero(area, type_size);
	return (area);
}

void	*ft_tmalloc(size_t type_size, size_t amount)
{
	void *area;

	area = malloc(type_size * amount);
	return (area);
}