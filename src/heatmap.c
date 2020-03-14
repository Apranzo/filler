/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:14:19 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 20:04:54 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void 		chebyshev(t_game *game, t_cel *cel)
{

	long	i;
	long	k;
	long	dist;
	unsigned dx;
	unsigned dy;

	i = 0;
	while (i < game->field.height)
	{
		k = 0;
		while (k < game->field.width)
		{
			if (game->field.cels[i][k]->content == game->enemy.number)
			{
				dx = ft_abs(i - cel->xy.x);
				dy = ft_abs(k - cel->xy.y);
				dist = 2 * ft_max(dx, dy) + 1 * ft_min(dx, dy);
				cel->heat = dist < cel->heat ? dist : cel->heat;
			}
			k++;
		}
		i++;
	}
}

void 		fill_heatmap(t_game *game)
{

	long	i;
	long	k;
	i = 0;
	while (i < game->field.height)
	{
		k = 0;
		while (k < game->field.width)
		{
			game->field.cels[i][k]->heat = game->field.height * game->field.width;
			if (game->field.cels[i][k]->content == 0)
				chebyshev(game, game->field.cels[i][k]);
			k++;
		}
		i++;
	}
}