/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:21:32 by fuhong            #+#    #+#             */
/*   Updated: 2018/10/19 16:41:08 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_env(char **envp, char *new_var)
{
	int		i;
	int		len;
	char	**new_envp;

	len = 0;
	while (envp[len])
		len++;
	new_envp = (char **)malloc(sizeof(char *) * (len + 2));
	new_envp[len + 1] = NULL;
	i = -1;
	while (++i < len)
	{
		if (i == (len - 1))
		{
			new_envp[i] = new_var;
			new_envp[i + 1] = ft_strdup(envp[i]);
			break ;
		}
		new_envp[i] = ft_strdup(envp[i]);
	}
	ft_tablefree(envp);
	return (new_envp);
}

_Bool	ft_my_setenv(char **parse, t_minienv *envp)
{
	int		index;
	char	*new_var;
	char	*tmp_var;
	char	**tmp_envp;

	tmp_envp = envp->env;
	if (parse[1] != NULL && parse[1][0] != '\0')
	{
		if ((new_var = ft_strjoin(parse[1], "=")) && parse[2] != NULL)
		{
			tmp_var = new_var;
			new_var = ft_strjoin(new_var, parse[2]);
			ft_strdel(&tmp_var);
		}
		if ((index = search_env_index(envp->env, parse[1])) != -1)
		{
			tmp_var = envp->env[index];
			envp->env[index] = new_var;
			ft_strdel(&tmp_var);
		}
		else
			envp->env = set_env(tmp_envp, new_var);
		return (1);
	}
	return (0);
}
