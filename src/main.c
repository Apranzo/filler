#include "../includes/filler.h"

void			plrs_cnst(char *str, t_game *game)
{
	char 		*uid;

	uid = ft_strsplbyindex(str, ' ', 2);
	if (!uid || *uid != 'p')
		ft_error("Wrong player identifier", -1);
	if (!(game->you = (t_player *)malloc(sizeof(t_player))) ||
			!(game->enemy = (t_player *)malloc(sizeof(t_player))))
		ft_error("Malloc error", -1);
	game->you->number = uid[1] + '0';
	game->you->letter = game->you->number % 2 ? 'x' : 'o';
	game->enemy->number = game->you->number % 2 + 1;
	game->enemy->letter = game->you->letter == 'o' ? 'x' : 'o';
	free(uid);
}

void 			cls_cnst(t_game *game, char **raw)
{
	int			i;
	int			k;
	t_cel		***cls;

	i = 0;
	while ((cls = game->field->cels) && raw[i])
	{
		k = 0;
		cls[i] = ft_tmalloc(sizeof(t_cel*), game->field->width);
		while (raw[i][k])
		{
			if (!(cls[i][k] = (t_cel*)malloc(sizeof(t_cel))))
				ft_error("Malloc error", -1);
			cls[i][k]->coord = ft_xynw(i, k);
			if (raw[i][k] == '.')
				cls[i][k]->content = NULL;
			else if (ft_tolower(raw[i][k]) == game->enemy->letter)
				cls[i][k]->content = game->enemy;
			else if (ft_tolower(raw[i][k]) == game->you->letter)
				cls[i][k]->content = game->you;
			else
				ft_error("Wrong map", -1);
			k++;
		}
		i++;
	}
}

int 			fld_cnst(int fd, t_game *game)
{
	char		**tmp;
	char		*line;
	int 		i;
	char 		**raw;

	if (!(game->field = (t_field *)malloc(sizeof(t_field))))
		ft_error("Malloc error", -1);
	if ((i = ft_gnl(fd, &line)) <= 0)
		return (i);
	ft_printf(line);
	tmp = ft_strsplit(line, ' ');
	game->field->height = ft_atoi(tmp[1]);
	game->field->width = ft_atoi(tmp[2]);
	ft_freematr(tmp);
	raw = ft_tmemalloc(sizeof(char *), game->field->height + 1);
	ft_gnl(fd, &line);
	free(line);
	i = 0;
	while (i < game->field->height && ft_gnl(fd, &line) > 0)
	{
		raw[i] = line + FILD_OFFSET;
		i++;
	}
	if (!(game->field->cels = ft_tmalloc(sizeof(t_cel*), game->field->height)))
		ft_error("Malloc error", -1);
	cls_cnst(game, raw);
	i = 0;
	while (raw[i])
	{
		free(raw[i] - FILD_OFFSET);
		i++;
	}
	return (1);
}

t_piece			*piece_cnst(int fd, t_game *game)
{
	t_piece		*piece;
	int 		x;
	int 		y;
	int 		i;
	char 		*line;
	char 		*num;

	i = 0;
	if (ft_gnl(fd, &line) <= 0)
		ft_error("Piece line is empty", -1);
	if (!(num = ft_strsplbyindex(line, ' ', 1)))
		ft_error("Malloc error", -1);
	x = ft_atoi(num);
	free(num);
	if (!(num = ft_strsplbyindex(line, ' ', 2)))
		ft_error("Malloc error", -1);
	y = ft_atoi(num);
	free(num);
	if (x <= 0 || y <= 0)
		ft_error("Wrong piece size", -1);
	if (!(piece = malloc(sizeof(t_piece))))
		ft_error("Malloc error", -1);
	if (!(piece->crd = ft_tmemalloc(sizeof(t_xy*), x * y)))
		ft_error("Malloc error", -1);
	piece->width = y;
	piece->height = x;
	while (x--)
	{
		y = piece->width;
		if (ft_gnl(fd, &line) <= 0)
			ft_error("Piece line is not exists", -1);
		while (y--)
		{
			if (line[y] == '*')
				piece->crd[i++] = ft_xynw(x, y);
		}
	}
	if (!*(piece->crd))
		ft_error("Piece is empty", -1);
	return (piece);
}

void			field_dstr(t_field *field)
{

}

void			piec_dstr(t_piece *piece)
{
	while ( piece->crd)
		free(piece->crd++);
	free(piece);
}

int				main(void) {

	char		*line;
	t_game		*game;
	t_xy		step;
	t_piece		*piece;

	game = (t_game *)malloc(sizeof(t_game));
	ft_gnl(0, &line);
	plrs_cnst(line, game);
	free(line);
	while (1)
	{
		if (!fld_cnst(0, game))
			break ;
		fill_heatmap(game);
		piece = piece_cnst(0, game);
		step = fill_token(game, piece);
		piec_dstr(piece);
		ft_vfprintf(STDOUT_FILENO, "%d %d\n", step.x, step.y);
	}
	return 0;
}
