/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:39:37 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 21:28:14 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		size_pars(int fd, t_xy *xy)
{
	char 			*line;
	char 			*num;

	if (ft_gnl(fd, &line) <= 0)
		ft_error("Piece line is empty", -1);
	if (!(num = ft_strsplbyindex(line, ' ', 1)))
		ft_error("Malloc error", -1);
	xy->x = ft_atoi(num);
	free(num);
	if (!(num = ft_strsplbyindex(line, ' ', 2)))
		ft_error("Malloc error", -1);
	xy->y = ft_atoi(num);
	free(num);
	if (xy->x <= 0 || xy->y <= 0)
		ft_error("Wrong piece size", -1);
}

t_piece				piece_cnst(int fd)
{
	static t_piece	piece;
	static t_xy		xy;
	int 			i;
	char 			*line;

	size_pars(fd, &xy);
	if (!(piece.crd = ft_tmemalloc(sizeof(t_xy*), xy.x * xy.y + 1)))
		ft_error("Malloc error", -1);
	piece.height = xy.x;
	piece.width = xy.y;
	(i = 0) || (xy.x = 0);
	while (xy.x < piece.height)
	{
		xy.y = 0;
		if (ft_gnl(fd, &line) <= 0)
			ft_error("Piece line is not exists", -1);
		while (xy.y < piece.width)
		{
			if (line[xy.y] == '*')
				piece.crd[i++] = ft_xynw(xy.x, xy.y);
			xy.y++;
		}
		xy.x++;
	}
	!*(piece.crd) && ft_error("Piece is empty", -1);
	return (piece);
}

void			piece_dstr(t_piece piece)
{
	int			i;

	i = 0;
	while (piece.crd && piece.crd[i])
		free(piece.crd[i++]);
	free(piece.crd);
//	free(piece);
}