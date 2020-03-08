/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:00:18 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/08 19:38:49 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			ft_wordlen(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char			*ft_storeword(char const *s, char c)
{
	int				i;
	char			*tmp;

	i = -1;
	if (!(tmp = ft_strnew(ft_wordlen(s, c))))
		return (NULL);
	while (s[++i] && s[i] != c)
		tmp[i] = s[i];
	ft_putstr(tmp);
	return (tmp);
}


char			**ft_strsplit(char const *s, char border)
{
	char		**matrix;
	size_t		howmany;

	while (*s == border)
		s++;
	howmany = ft_countwords(s, border);
	if (!(matrix = (char **)malloc(sizeof(char *) * (howmany + 1))))
		return (NULL);
	if (!howmany)
		matrix[0] = NULL;
	else
		ft_spliting(s, matrix, border);
	return (matrix);
}

char				*ft_strsplbyindex(char const *s, char c, int index)
{
	size_t 			cursor;

	cursor = 0;
	while (s[cursor] && index > 0)
	{
		if (s[cursor] == c)
			index--;
		cursor++;
		if (!index)
			return (ft_storeword(s + cursor, c));
	}
	return (!index ? ft_storeword(s + cursor, c) : NULL);
}
