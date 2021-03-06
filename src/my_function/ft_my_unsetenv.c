/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 05:15:08 by fuhong            #+#    #+#             */
/*   Updated: 2018/10/22 20:08:28 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	ft_my_unsetenv(char **parse, t_minienv *envp)
{
	int		i;
	int		len;
	int		index;
	char	**new_envp;

	if (parse[1] && (index = search_env_index(envp->env, parse[1])) != -1)
	{
		len = ft_tablesize(envp->env) + 1;
		new_envp = (char **)ft_memalloc(sizeof(char *) * len);
		new_envp[len] = NULL;
		i = 0;
		len = 0;
		while (envp->env[len])
		{
			if (len == index)
				len++;
			new_envp[i++] = ft_strdup(envp->env[len++]);
		}
		ft_tablefree(envp->env);
		envp->env = new_envp;
		return (1);
	}
	ft_putendl("Usage: unsetenv name");
	return (0);
}
