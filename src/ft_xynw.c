/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xynw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:19:44 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 16:19:38 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_xy		*ft_xynw(int x, int y)
{
	t_xy	*new;

	if (!(new = malloc(sizeof(t_xy))))
		ft_error("Malloc error", -1);
	new->x = x;
	new->y = y;
	return (new);
}
