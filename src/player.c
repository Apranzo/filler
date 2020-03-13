/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:43:33 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/13 20:47:11 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				plrs_cnst(char *str, t_game game)
{
	char 			*uid;
	static t_player	you;
	static t_player	enemy;

	uid = ft_strsplbyindex(str, ' ', 2);
	if (!uid || *uid != 'p')
		ft_error("Wrong player identifier", -1);
	game.you = you;
	game.enemy = enemy;
	game.you.number = uid[1] + '0';
	game.you.letter = game.you.number % 2u ? 'x' : 'o';
	game.enemy.number = game.you.number % 2u + 1;
	game.enemy.letter = game.you.letter == 'o' ? 'x' : 'o';
	free(uid);
}