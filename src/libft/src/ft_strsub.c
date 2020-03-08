/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:30:06 by cshinoha          #+#    #+#             */
/*   Updated: 2019/05/25 19:02:53 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!len)
		return (NULL);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	return (ft_strncpy(sub, (s + start), len));
}
