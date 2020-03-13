/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:42:42 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/13 21:36:55 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void 			cls_cnst(char **raw, t_game game)
{
	int			i;
	int			k;
	t_cel		***cls;

	i = 0;
	while ((cls = game.field.cels) && raw[i])
	{
		k = 0;
		!cls[i] && (cls[i] = ft_tmemalloc(sizeof(t_cel*), game.field.width + 1));
		while (raw[i][k])
		{
			if (!cls[i][k] && !(cls[i][k] = (t_cel*)malloc(sizeof(t_cel))))
				ft_error("Malloc error", -1);
			cls[i][k]->coord = ft_xynw(i, k);
			if (raw[i][k] == '.')
				cls[i][k]->content = 0;
			else if (ft_tolower(raw[i][k]) == game.enemy.letter)
				cls[i][k]->content = game.enemy.number;
			else if (ft_tolower(raw[i][k]) == game.you.letter)
				cls[i][k]->content = game.you.number;
//			else
//				ft_error("Wrong map", -1);
			k++;
		}
		i++;
	}
}