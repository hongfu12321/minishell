/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:02:31 by fuhong            #+#    #+#             */
/*   Updated: 2018/10/19 05:44:15 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_env_index(char **envp, char *str)
{
	int		i;
	int		len;
	char	*para;

	if (*str == '\0')
		return (-1);
	i = -1;
	str = ft_strjoin(str, "=");
	len = ft_strlen(str);
	para = NULL;
	while (envp[++i])
		if (ft_strncmp(envp[i], str, len) == 0)
			return (i);
	ft_strdel(&str);
	return (-1);
}


char	*get_env_var(char **envp, char *str)
{
	int		i;
	int		len;
	char	*para;

	if (*str == '\0')
		return (NULL);
	len = ft_strlen(str) + 1;
	if ((i = search_env_index(envp, str)) == -1)
		return (NULL);
	para = ft_strdup(&envp[i][len]);
	return (para);
}
