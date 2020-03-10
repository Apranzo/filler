/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:14:19 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/08 20:58:05 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void 		calc_heat(t_game *game, t_cel *cel)
{

	long	i;
	long	k;
	long	dist;

	cel->heat = 0;
	i = 0;
	while (i < game->field->height)
	{
		k = 0;
		while (k < game->field->width)
		{
			if (game->field->cels[i][k]->content == game->enemy)
			{
				dist = ft_abs(k - cel->coord->x) + ft_abs(i - cel->coord->y);
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
	while (i < game->field->height)
	{
		k = 0;
		while (k < game->field->width)
		{
			if (game->field->cels[i][k]->content == NULL)
				calc_heat(game, game->field->cels[i][k]);
			k++;
		}
		i++;
	}
}