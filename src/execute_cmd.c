/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:08:38 by fhong             #+#    #+#             */
/*   Updated: 2018/10/22 20:59:42 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				is_my_func(char **cmd)
{
	int ret;

	ret = -1;
	while (++ret < FUNC_NUM)
		if (ft_strcmp(cmd[0], g_my_func[ret].name) == 0)
			return (ret);
	return (-1);
}

_Bool			run_system_func(char **cmd, t_minienv *envp)
{
	int		i;
	char	**path_table;
	char	*path;
	char	*name;
	_Bool	result;

	result = 0;
	if (!(path_table = ft_strsplit(get_env_var(envp->env, "PATH"), ':')))
		ft_exit("Can't find the path\n");
	name = ft_strjoin("/", cmd[0]);
	i = -1;
	while (path_table[++i])
	{
		if (!path_table[i])
			path = cmd[0];
		else
			path = ft_strjoin(path_table[i], name);
		result = (execve(path, cmd, envp->env) == -1) ? 0 : 1;
		ft_strdel(&path);
	}
	ft_printf("%s: Command not found\n", cmd[0]);
	ft_strdel(&path);
	ft_tablefree(path_table);
	return (result);
}

_Bool			run_builtin_func(char *cmd, t_minienv *envp, char **p, int ret)
{
	_Bool result;

	if (ft_strncmp(cmd, "setenv", 6) == 0)
		result = ft_my_setenv(p, envp);
	else if (ft_strncmp(cmd, "unsetenv", 8) == 0)
		result = ft_my_unsetenv(p, envp);
	else
		result = g_my_func[ret].fct(p, envp);
	return (result);
}

void			run_cmd(char *cmd, t_minienv *envp)
{
	int		ret;
	int		stat_loc;
	_Bool	result;
	char	**parse;
	pid_t	pid;

	ret = -1;
	result = 0;
	if ((parse = parse_cmd(envp->env, cmd)) == NULL)
		return ;
	if ((ret = is_my_func(parse)) != -1)
		result = run_builtin_func(cmd, envp, parse, ret);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			result = run_system_func(parse, envp);
			exit(0);
		}
		else if (pid < 0)
			ft_exit("Fail to create new process");
		waitpid(pid, &stat_loc, WUNTRACED);
	}
	ft_tablefree(parse);
}
