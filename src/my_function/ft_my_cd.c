/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:15:27 by fhong             #+#    #+#             */
/*   Updated: 2018/10/19 15:33:03 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	get_oldpwd(char *cwd, t_minienv *envp)
{
	_Bool	flag;
	char **tmp;

	tmp = (char **)malloc(sizeof(char *) * 3);
	tmp[0] = ft_strdup("setenv");
	tmp[1] = ft_strdup("OLDPWD");
	tmp[2] = ft_strdup(cwd);
	flag = ft_my_setenv(tmp, envp);
	ft_tablefree(tmp);
	return (flag);
}

_Bool	ft_my_cd(char **para, t_minienv *envp)
{
	_Bool	flag;
	char 	*path;
	char	*cwd;
	char	buff[PATH_MAX + 1];

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
		if (!(cwd = getcwd(buff, PATH_MAX)))
			return (0);
		flag = get_oldpwd(cwd, envp);
		chdir(path);
	}
	ft_strdel(&path);
	return ((flag == 1) ? 1 : 0);
}
