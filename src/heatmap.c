/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:14:19 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/15 19:28:10 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					calc_heat(t_xy beg, t_xy goal)
{
	int		 		dx;
	int		 		dy;

	dx = ft_abs(goal.x - beg.x);
	dy = ft_abs(goal.y - beg.y);
	return (2 * ft_max(dx, dy) + 1 * ft_min(dx, dy));
}

static void 		chebyshev(t_game *game, t_cel *cel)
{

	int				x;
	int				y;
	int				heat;

	x = 0;
	while (x < game->field.height)
	{
		y = 0;
		while (y < game->field.width)
		{
			if (game->field.cels[x][y]->content == game->enemy.number)
			{
				heat = calc_heat(cel->xy, (t_xy){x, y});
				cel->heat = heat < cel->heat ? heat : cel->heat;
			}
			y++;
		}
		x++;
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
			game->field.cels[i][k]->heat =
					calc_heat((t_xy) {0, 0},
							(t_xy) {game->field.height, game->field.width});
			if (game->field.cels[i][k]->content == 0)
				chebyshev(game, game->field.cels[i][k]);
			k++;
		}
		i++;
	}
}