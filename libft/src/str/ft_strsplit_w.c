/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_w.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:45:07 by fhong             #+#    #+#             */
/*   Updated: 2018/10/22 20:57:32 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static size_t	ft_count_letters(char const *str)
{
	size_t	count;

	count = 0;
	while (!is_whitespace(str[count]) && str[count])
		count++;
	return (count);
}

static size_t	ft_count_words(char const *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (!is_whitespace(*str))
		{
			if (is_whitespace(*(str + 1)) || *(str + 1) == '\0')
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
		while (is_whitespace(*s) && *s)
			s++;
		tab[i] = ft_strnew(ft_count_letters(s));
		j = 0;
		while (!is_whitespace(*s) && *s)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
