/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:42:42 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 16:38:55 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void 			cls_cnst(char **raw, t_game *game)
{
	int			x;
	int			y;
	int			n;
	t_cel		***cls;

	x = 0;
	while ((cls = game->field.cels) && raw[x])
	{
		y = 0;
		cls[x] || (cls[x] = ft_tmemalloc(sizeof(t_cel*), game->field.width + 1));
		while (raw[x][y])
		{
			if (!cls[x][y] && !(cls[x][y] = (t_cel*)ft_memalloc(sizeof(t_cel))))
				ft_error("Malloc error", -1);
			n = (cls[x][y]->xy.x = x) + 1 && ((cls[x][y]->xy.y = y)) ;
			if (raw[x][y] == '.')
				cls[x][y]->content = 0;
			else if (ft_tolower(raw[x][y]) == game->enemy.letter)
				cls[x][y]->content = game->enemy.number;
			else if (ft_tolower(raw[x][y]) == game->you.letter)
				cls[x][y]->content = game->you.number;
			else
				ft_error("Wrong map", n - n - 1);
			y++;
		}
		x++;
	}
}