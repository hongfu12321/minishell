/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:02:31 by fuhong            #+#    #+#             */
/*   Updated: 2018/10/18 23:05:29 by fuhong           ###   ########.fr       */
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
	i = search_env_index(envp, str);
	para = ft_strdup(&envp[i][len]);
	return (para);
}

char	**create_env(char **envp, char *para, int flag)
{
	int 	len;
	int		new_len;
	char	**new_envp;

	len = 0;
	while (envp[len])
		len++;
	len = (flag == SET_ENV) ? len + 1 : len;
	new_envp = (char **)malloc(sizeof(char *) * (len + 1));
	new_envp[len] = NULL;
	len = 0;
	new_len = 0;
	while (envp[len])
	{
		(void)para;
//		if (flag == SET_ENV && !envp[len + 2])
//			new_envp[new_len++] = ft_strdup(para);
//		else
			new_envp[new_len++] = ft_strdup(envp[len++]);
	}
	return (new_envp);
}
