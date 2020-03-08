/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 22:38:04 by cshinoha          #+#    #+#             */
/*   Updated: 2019/03/12 22:38:08 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char*))
{
	while (*tab)
	{
		if (f(*tab) == 1)
			return (1);
		tab++;
	}
	return (0);
}