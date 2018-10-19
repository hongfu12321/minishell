/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:21:32 by fuhong            #+#    #+#             */
/*   Updated: 2018/10/18 23:08:18 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_my_setenv(char **parse, char **envp)
{
	int		index;
	char	*new_var;
	char	*tmp_var;
	char	**tmp_envp;

	tmp_envp = envp;
	if (parse[1] != NULL && parse[1][0] != '\0')
	{
		new_var = ft_strjoin(parse[1], "=");
		if (parse[2] && parse[2] != NULL)
			new_var = ft_strjoin(new_var, parse[2]);
		if ((index = search_env_index(envp, parse[1])) != -1)
		{
			tmp_var =envp[index];
			envp[index] = new_var;
			ft_strdel(&tmp_var);
		}
		else
		{
			ft_printf("new_var: %s\n", new_var);
		//	ft_tablefree(tmp_envp);
			envp = create_env(envp, new_var, SET_ENV);
			ft_printf("OUT!!!");
		}
	}
	return (envp);
}
