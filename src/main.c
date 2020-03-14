/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:43:54 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 16:22:38 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void 			pr(t_cel ***cls)
{
	int i = 0;
	int k = 0;
	unsigned heat;
	int fd = open("heatmap",  O_RDWR | O_CREAT, 0666);
	while (cls[i])
	{
		k = 0;
		while (cls[i][k])
		{
			heat = cls[i][k]->heat;
			ft_vfprintf(fd, "%.3d | ", heat);
			k++;
		}
		ft_vfprintf(fd, "\n\n");
		i++;
	}
}

int					main(void) {

	char			*line;
	static t_game	game;
	t_xy			step;

	ft_gnl(0, &line);
	plrs_cnst(line, &game);
	while (1)
	{
		if (!field_cnst(0, &game))
			break ;
		fill_heatmap(&game);
		pr(game.field.cels);
		step = fill_piece(game, piece_cnst(0));
		ft_vfprintf(STDOUT_FILENO, "%d %d\n", step.x, step.y);
	}
	return 0;
}
