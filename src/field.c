/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:41:18 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 20:58:33 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int 			field_cnst(int fd, t_game *game)
{
	char		**tmp;
	char		*line;
	int			i;
	char 		**raw;

	if ((i = ft_gnl(fd, &line)) <= 0)
		return (i);
	tmp = ft_strsplit(line, ' ');
	game->field.height = ft_atoi(tmp[1]);
	game->field.width = ft_atoi(tmp[2]);
	ft_freematr(tmp);
	raw = ft_tmemalloc(sizeof(char *), game->field.height + 1);
	ft_gnl(fd, &line);
	free(line);
	i = 0;
	while (i < game->field.height && ft_gnl(fd, &line) > 0)
		raw[i++] = line + FILD_OFFSET;
	if (!(game->field.cels = ft_tmemalloc(sizeof(t_cel*), game->field.height + 1)))
		ft_error("Malloc error", -1);
	cls_cnst(raw, game);
	i = 0;
	while (raw[i])
		free(raw[i++] - FILD_OFFSET);
	return (1);
}
