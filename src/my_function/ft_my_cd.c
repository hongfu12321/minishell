/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:15:27 by fhong             #+#    #+#             */
/*   Updated: 2018/10/22 17:19:09 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	get_oldpwd(char *path_var, t_minienv *envp)
{
	_Bool	flag;
	char	**tmp;
	char	*cwd;
	char	buff[PATH_MAX + 1];

	if (!(cwd = getcwd(buff, PATH_MAX)))
		return (0);
	tmp = (char **)malloc(sizeof(char *) * 4);
	tmp[0] = ft_strdup("setenv");
	tmp[1] = ft_strdup(path_var);
	tmp[2] = ft_strdup(cwd);
	tmp[3] = NULL;
	flag = ft_my_setenv(tmp, envp);
	ft_tablefree(tmp);
	return (flag);
}

_Bool	ft_my_cd(char **para, t_minienv *envp)
{
	char	*path;
	_Bool	flag;

	flag = 0;
	if (para[1] && para[1][0] == '-')
		path = get_env_var(envp->env, "OLDPWD");
	else
		path = (para[1]) ? ft_strdup(para[1]) : get_env_var(envp->env, "HOME");
	if (access(path, F_OK) == -1)
		ft_putstr("cd: no such directory\n");
	else if (access(path, R_OK) == -1)
		ft_putstr("cd: permission denied\n");
	else
	{
		flag = get_oldpwd("OLDPWD", envp);
		chdir(path);
		flag = get_oldpwd("PWD", envp);
	}
	ft_strdel(&path);
	return ((flag == 1) ? 1 : 0);
}
