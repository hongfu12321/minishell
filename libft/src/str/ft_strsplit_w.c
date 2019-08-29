/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_w.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:18:52 by fhong             #+#    #+#             */
/*   Updated: 2019/08/28 22:06:41 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_letters(char const *str)
{
	size_t	count;

	count = 0;
	while (!ft_isspace(str[count]) && str[count])
		count++;
	return (count);
}

static size_t	ft_count_words(char const *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			if (ft_isspace(*(str + 1)) || *(str + 1) == '\0')
				count++;
		}
		str++;
	}
	return (count);
}

char			**ft_strsplit_w(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		words;
	char		**tab;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (ft_isspace(*s) && *s)
			s++;
		tab[i] = ft_strnew(ft_count_letters(s));
		j = 0;
		while (!ft_isspace(*s) && *s)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
