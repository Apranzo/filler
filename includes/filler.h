/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:15:58 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/08 21:25:42 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include <libft.h>
# define IAM cshinoha.filler
# define FILD_OFFSET 4

typedef	struct		s_xy
{
	int				x;
	int				y;
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
	char 			**raw;
	t_cel			***cels;
	unsigned 		width;
	unsigned 		height;
}					t_field;


typedef struct		s_piece
{
	char 			**raw;
	int 			amount;
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
long				fill_heatmap(t_game *game);

#endif
