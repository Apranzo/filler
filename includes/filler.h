/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:15:58 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/15 19:25:20 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include "../src/libft/include/libft.h"
# define FILD_OFFSET 4

typedef	struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_player
{
	int				number;
	char			letter;
}					t_player;

typedef struct		s_cel
{
	int		 		content;
	t_xy			xy;
	int				heat;
}					t_cel;

typedef struct		s_field
{
	t_cel			***cels;
	int		 		width;
	int		 		height;
}					t_field;

typedef struct		s_piece
{
	int	 			width;
	int		 		height;
	t_xy			**crd;
}					t_piece;

typedef struct		s_game
{
	t_player		you;
	t_player		enemy;
	t_field 		field;

}					t_game;


int					calc_heat(t_xy beg, t_xy goal);
t_piece				piece_cnst(int fd);
int		 			field_cnst(int fd, t_game *game);
void	 			plrs_cnst(char *str, t_game *game);
void				cls_cnst(char **raw, t_game *game);
void				piece_dstr(t_piece);
//void 				field_dstr(t_game *game);
//void	 			plrs_dstr(t_game game);
void				cls_dstr(t_game game);
t_xy				*ft_xynw(int x, int y);
void				fill_heatmap(t_game *game);
t_xy				fill_piece(t_game game, t_piece piece);

#endif
