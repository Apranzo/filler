/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:00:18 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/12 17:58:12 by cshinoha         ###   ########.fr       */
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

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	words;
	unsigned int	nofword;
	char			**tab;

	if (!s)
		return (NULL);
	nofword = 0;
	words = ft_cntwords(s, c);
	if (!(tab = (char **)ft_tmalloc(sizeof(char *), words + 1)))
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (!(tab[nofword] = ft_storeword(s, c)))
				return (NULL);
			nofword++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	tab[nofword] = 0;
	return (tab);
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
