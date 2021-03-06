/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:43:33 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 16:49:53 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				plrs_cnst(char *str, t_game *game)
{
	char 			*uid;
	static t_player	you;
	static t_player	enemy;

	uid = ft_strsplbyindex(str, ' ', 2);
	if (!uid || *uid != 'p')
		ft_error("Wrong player identifier", -1);
	game->you = you;
	game->enemy = enemy;
	game->you.number = (uid[1] - '0') / 1;
	game->you.letter = game->you.number % 2 ? 'o' : 'x';
	game->enemy.number = game->you.number % 2 + 1;
	game->enemy.letter = game->you.letter == 'o' ? 'x' : 'o';
	free(uid);
}