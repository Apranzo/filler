/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:15:58 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/10 19:53:26 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include <libft.h>
# define IAM cshinoha.filler
# define FILD_OFFSET 4

typedef	struct		s_xy
{
	unsigned		x;
	unsigned		y;
}					t_xy;

typedef struct		s_player
{
	unsigned		number : 1;
	char			letter;
}					t_player;

typedef struct		s_cel
{
	t_player 		*content;
	t_xy			*coord;
	long 			heat;
}					t_cel;

typedef struct		s_field
{
	t_cel			***cels;
	unsigned 		width;
	unsigned 		height;
}					t_field;


typedef struct		s_piece
{
	unsigned 		width;
	unsigned 		height;
	t_xy			**crd;
}					t_piece;


typedef struct		s_game
{
	t_player		*you;
	t_player		*enemy;
	t_field 		*field;

}					t_game;


t_xy				*ft_xynw(int x, int y);
void				calc_heat(t_game *game, t_cel *cel);
void				fill_heatmap(t_game *game);
t_xy				fill_token(t_game *game, t_piece *piece)

#endif
