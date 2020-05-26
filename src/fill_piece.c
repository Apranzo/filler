/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:06:39 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/15 19:42:11 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		put_token(const t_game game, t_xy **crd, t_xy xy)
{
	int			i;
	int			heat;
	int			docking;

	heat = 0;
	i = 0;
	docking = 0;
	while (crd[i])
	{
		if (crd[i]->x + xy.x >=game.field.height ||
			crd[i]->y + xy.y >= game.field.width ||
			game.field.cels[crd[i]->x + xy.x][crd[i]->y + xy.y]
					->content == game.enemy.number)
			return (0) ;
		if (game.field.cels[crd[i]->x + xy.x][crd[i]->y + xy.y]
				->content != game.enemy.number)
			heat += game.field.cels[crd[i]->x + xy.x][crd[i]->y + xy.y]->heat;
		if (!docking && game.field.cels[crd[i]->x + xy.x][crd[i]->y + xy.y]
				->content == game.you.number)
			docking++;
		i++;
	}
	return (docking == 1 ? heat : 0);
}

t_xy 			fill_piece(t_game game, t_piece piece)
{
	t_cel		solution;
	int			x;
	int			y;
	int			heat;

	x = 0;
	solution = (t_cel){ 0,
					 (t_xy){game.field.height, game.field.width},
					 0};
	while (x < game.field.height)
	{
		y = 0;
		while (y < game.field.width)
		{
			heat = put_token(game, piece.crd, game.field.cels[x][y]->xy);
			solution = heat && (heat < solution.heat || !solution.heat)
					? (t_cel){ 0, (t_xy) {x, y}, heat }
					: solution;
			y++;
		}
		x++;
	}
	piece_dstr(piece);
	return solution.xy;
}