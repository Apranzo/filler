/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:06:39 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/08 22:04:03 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void 		fill_token(t_game *game, t_piece *piece)
{

	long	i;
	long	k;
	long	h;
	long	heat;
	long	min_heat;

	i = 0;
	heat = 0;
	while (i < game->field->height)
	{
		k = 0;
		while (k < game->field->width)
		{
			h = 0;
			while (piece->amount < h)
			{
				if (piece->crd[h]->x + i > game->field->height || piece->crd[h]->y + k > game->field->height)
					break ;
				if (game->field->cels[piece->crd[h]->x + i][piece->crd[h]->y + k]->content != game->enemy)
					heat += game->field->cels[piece->crd[h]->x + i][piece->crd[h]->y + k]->heat;
			}

			k++;
		}
		i++;
	}
}