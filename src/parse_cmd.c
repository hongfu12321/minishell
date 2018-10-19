/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:27:43 by fhong             #+#    #+#             */
/*   Updated: 2018/10/18 17:27:45 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(char **envp, char *str)
{
	int		i;
	int		len;
	char	*para;

	if (*str == '\0')
		return (NULL);
	i = -1;
	str = ft_strjoin(str, "=");
	len = ft_strlen(str);
	para = NULL;
	while (envp[++i])
		if (ft_strncmp(envp[i], str, len) == 0)
		{
			para = ft_strdup(&envp[i][len]);
			break ;
		}
	ft_strdel(&str);
	return (para);
}
