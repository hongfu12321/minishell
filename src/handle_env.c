/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:51:43 by fhong             #+#    #+#             */
/*   Updated: 2018/10/22 20:59:51 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_env_index(char **envp, char *str)
{
	int	i;
	int	len;

	if (*str == '\0')
		return (-1);
	i = -1;
	len = ft_strlen(str);
	while (envp[++i])
		if ((ft_strncmp(envp[i], str, len) == 0) && envp[i][len] == '=')
			return (i);
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
