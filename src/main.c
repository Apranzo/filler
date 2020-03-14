/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:43:54 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 20:38:33 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void 			pr(t_cel ***cls)
{
	int i = 0;
	int k = 0;
	unsigned heat;
	int fd = open("heatmap",  O_RDWR | O_APPEND | O_CREAT, 0777);
	ft_vfprintf(fd, "\n\n");
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
//		pr(game.field.cels);
		step = fill_piece(game, piece_cnst(0));
		ft_putnbr_fd(STDOUT_FILENO, step.x);
		ft_putchar_fd(STDOUT_FILENO, ' ');
		ft_putnbr_fd(STDOUT_FILENO, step.y);
		ft_putchar_fd(STDOUT_FILENO, '\n');
	}
	return 0;
}
