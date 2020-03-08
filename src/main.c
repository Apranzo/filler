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

void 			cls_cnst(t_game *game)
{
	int			i;
	int			k;
	t_cel		***cls;

	i = 0;
	cls = game->field->cels;
	while (game->field->raw[i])
	{
		k = 0;
		cls[i] = ft_tmalloc(sizeof(t_cel*), game->field->width);
		while (game->field->raw[i][k])
		{
			if (!(cls[i][k] = (t_cel*)malloc(sizeof(t_cel))))
				ft_error("Malloc error", -1);
			cls[i][k]->coord = ft_xynw(i, k);
			if (game->field->raw[i][k] == '.')
				cls[i][k]->content = NULL;
			else if (ft_tolower(game->field->raw[i][k]) == game->enemy->letter)
				cls[i][k]->content = game->enemy;
			else if (ft_tolower(game->field->raw[i][k]) == game->you->letter)
				cls[i][k]->content = game->you;
			else
				ft_error("Wrong map", -1);
			k++;
		}
		i++;
	}
}

void 			fld_cnst(int fd, t_game *game)
{
	char		**tmp;
	char		*line;
	int 		i;

	if (!(game->field = (t_field *)malloc(sizeof(t_field))))
		ft_error("Malloc error", -1);
	ft_gnl(fd, &line);
	tmp = ft_strsplit(line, ' ');
	game->field->height = ft_atoi(tmp[1]);
	game->field->width = ft_atoi(tmp[2]);
	ft_freematr(tmp);
	game->field->raw = ft_tmemalloc(sizeof(char *), game->field->height + 1);
	ft_gnl(fd, &line);
	free(line);
	i = 0;
	while (i < game->field->height && ft_gnl(fd, &line) > 0)
	{
		game->field->raw[i] = line + FILD_OFFSET;
		i++;
	}
	if (!(game->field->cels = ft_tmalloc(sizeof(t_cel*), game->field->height)))
		ft_error("Malloc error", -1);
	cls_cnst(game);
}

int			main() {

	char	*line;
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	int fd = open("out2", O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	ft_gnl(0, &line);
	plrs_cnst(line, game);
	free(line);
	fld_cnst(0, game);
	fill_heatmap(game);

//	ft_vfprintf(fd, "p1:%u\t", game->pls[0].number);
//	ft_vfprintf(fd, "p2:%u\n", game->pls[1].number);
//	ft_vfprintf(fd, "fh:%u\tfw:%u\n", game->field->height, game->field->width);
	ft_putstrss_fd(game->field->raw, -1, 0);
	ft_vfprintf(STDOUT_FILENO, "12 14\n");
	while (ft_gnl(STDIN_FILENO, &line) > 0)
	{
		ft_vfprintf(fd, "%s\n", line);
		while (ft_gnl(STDIN_FILENO, &line) > 0)
		{
			ft_vfprintf(fd, "%s\n", line);
		}
		ft_vfprintf(STDOUT_FILENO, "12 14\n");
	}
	return 0;
}
