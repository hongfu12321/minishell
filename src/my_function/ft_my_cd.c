/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:15:27 by fhong             #+#    #+#             */
/*   Updated: 2018/10/18 17:26:47 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	ft_my_cd(char **para, char **envp)
{
	int		flag;
	char 	*path;

	flag = 0;
	if (para[1] != NULL)
		path = ft_strdup(para[1]);
	else
		path = get_env_var(envp, "HOME");
	if (access(path, F_OK) == -1)
		ft_putstr("cd: no such file or directory\n");
	else if (access(path, R_OK) == -1)
		ft_putstr("cd: permission denied\n");
	else
	{
		chdir(path);
		flag = 1;
	}
	ft_strdel(&path);
	return ((flag == 1) ? 1 : 0);
}