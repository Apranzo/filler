/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:43:54 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/15 19:22:54 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void pr(t_cel ***cls, t_xy xy)
{
	int i = 0;
	int k = 0;
	unsigned heat;
	int fd = open("heatmap",  O_RDWR | O_APPEND | O_CREAT, 0777);
	ft_vfprintf(fd, "\n\n%d : %d\n\n", xy.x, xy.y);
	while (cls[i])
	{
		k = 0;
		while (cls[i][k])
		{
			char c = cls[i][k]->content  ? (cls[i][k]->content == 1 ? 'o' : 'x') : '%';
			heat = cls[i][k]->heat;
			ft_vfprintf(fd, "%d:%d  \t%.2d %c| ", i, k, heat, c);
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

	int fd = STDOUT_FILENO; // open("ou",  O_RDWR | O_APPEND | O_CREAT, 0777);
	ft_gnl(0, &line);
	plrs_cnst(line, &game);
	while (1)
	{
		if (!field_cnst(0, &game))
			break ;
		fill_heatmap(&game);
		step = fill_piece(game, piece_cnst(0));
		pr(game.field.cels, step);
		ft_putnbr_fd(fd, step.x);
		ft_putchar_fd(fd, ' ');
		ft_putnbr_fd(fd, step.y);
		ft_putchar_fd(fd, '\n');
	}
	return 0;
}
