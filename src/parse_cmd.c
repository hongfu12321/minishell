/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:27:43 by fhong             #+#    #+#             */
/*   Updated: 2018/10/19 16:45:47 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_special_char(char *str, char **envp, char c)
{
	char *new;
	char *tmp;

	if (!str[1] && str[0] != '~')
		return (str);
	if (c == '$' && !(new = get_env_var(envp, &str[1])))
		return (str);
	if (c == '~')
	{
		new = get_env_var(envp, "HOME");
		if (str[1] != '\0')
		{
			tmp = new;
			new = ft_strjoin(tmp, &str[1]);
			ft_strdel(&tmp);
		}
	}
	return (new);
}

char	**parse_cmd(char **envp, char *str)
{
	int		i;
	int		len;
	char	*tmp;
	char	**parse;

	if ((parse = ft_strsplit(str, ' ')) && *parse == NULL)
		return (NULL);
	i = 0;
	while (parse[++i])
	{
		tmp = parse[i];
		len = ft_strlen(parse[i]);
		if ((parse[i][0] == '\"' && parse[i][len - 1] == '\"') ||
			(parse[i][0] == '\'' && parse[i][len - 1] == '\''))
		{
			parse[i] = ft_strsub(parse[i], 1, len - 2);
			ft_strdel(&tmp);
			continue ;
		}
		if (parse[i][0] == '~' || parse[i][0] == '$')
			parse[i] = parse_special_char(parse[i], envp, parse[i][0]);
		if (ft_strcmp(parse[i], tmp) != 0)
			ft_strdel(&tmp);
	}
	return (parse);
}
